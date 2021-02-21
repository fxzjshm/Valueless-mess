extern crate ocl;

use ocl::ProQue;
use crate::MonteCarloPiCalculator;
use std::sync::Arc;
use self::ocl::core::{DeviceInfo, MEM_READ_ONLY, get_kernel_work_group_info, KernelWorkGroupInfo, get_device_info, DeviceInfoResult, set_kernel_arg};
use self::ocl::{Device, Platform, Buffer, OclPrm};
use self::ocl::builders::{DeviceSpecifier, ProgramBuilder};
use rayon::prelude::*;
use std::time::Instant;
use self::ocl::enums::KernelWorkGroupInfoResult;
use core::mem;
use self::ocl::core::ffi::clSetKernelArg;
use std::ptr::null;
use num::NumCast;

pub struct OpenCLThreadCalculator {
    pro_que: ProQue,
    use_f32: bool,
    is_unified_memory: bool,
}

static KERNEL_SRC: &'static str = r#"
    #ifndef REAL
        #ifdef cl_khr_fp64
            #define REAL double
        #else
            #define REAL float
        #endif // cl_khr_fp64
    #endif // REAL

    typedef REAL real;


    inline real gen_random(const real x){
        const real base = (real) 65536.0;
        const real a = (real) 3289579.0;
        const real b = (real) 90238493.0;
        __private const real t = fma(a, x, b) / base;
        return fmod(t, (real) 1.0);
    }

    __kernel void gen_randoms(__global real* const xs, __global real* const ys){
        const size_t i = get_global_id(0);
        const size_t n = get_global_size(0);
        __private real t = gen_random(((real) i) / (real) n);
        t = gen_random(t);
        t = gen_random(t);
        xs[i] = gen_random(t);
        ys[i] = gen_random(xs[i]);
    }

    // reference: https://github.com/maoshouse/OpenCL-reduction-sum/blob/master/sum.cl
    __kernel void cal(__global real* const xs, __global real* const ys, __global unsigned long* output,
                      __local unsigned long* reductionSums, __global unsigned long* work_group_size) {
        const size_t global_id = get_global_id(0),
                     global_size = get_global_size(0),
                     local_id = get_local_id(0),
                     local_size = get_local_size(0),
                     work_group_id = global_id / local_size;
        if (global_id == 0) {
            work_group_size[0] = local_size;
        }
        real x = xs[global_id], y = ys[global_id];
        unsigned long is_inside = (sqrt(x * x + y * y) < (real) 1.0) ? 1 : 0;
        reductionSums[local_id] = is_inside;

        for (size_t offset = local_size >> 1; offset > 0; offset >>= 1) {
            barrier(CLK_LOCAL_MEM_FENCE);
            if (local_id < offset){
                reductionSums[local_id] += reductionSums[local_id + offset];
            }
        }

        if (local_id == 0) {
            output[work_group_id] = reductionSums[0];
        }
    }
"#;

impl OpenCLThreadCalculator {
    #[inline]
    fn try_gen_randoms(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        if (self.use_f32) {
            return self.try_gen_randoms_f32(n);
        } else {
            return self.try_gen_randoms_f64(n);
        }
    }

    #[inline]
    fn try_gen_randoms_f64(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        return self.try_gen_randoms_::<f64>(n);
    }

    #[inline]
    fn try_gen_randoms_f32(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        let (xs, ys) = self.try_gen_randoms_::<f32>(n)?;
        let xs_ret = xs.par_iter().map(|&x| x as f64).collect();
        let ys_ret = ys.par_iter().map(|&y| y as f64).collect();
        return ocl::Result::Ok((xs_ret, ys_ret));
    }

    #[inline]
    fn try_gen_randoms_<T: OclPrm + NumCast>(&self, n: usize) -> ocl::Result<(Vec<T>, Vec<T>)> {
        let mut xs = vec![num::cast::<f64, T>(0.0).unwrap(); n];
        let mut ys = xs.clone();
        let buffer_xs = self.create_buffer::<T>(n,Some(&xs))?;
        let buffer_ys = self.create_buffer::<T>(n,Some(&ys))?;
        let kernel = self.pro_que.kernel_builder("gen_randoms").arg(&buffer_xs).arg(&buffer_ys).build()?;
        let start_time = Instant::now();
        unsafe { kernel.enq()?; }
        self.pro_que.finish()?;
        println!("kernel enqueue used: {}ms", start_time.elapsed().as_millis());
        buffer_xs.read(&mut xs).enq()?;
        buffer_ys.read(&mut ys).enq()?;
        self.pro_que.finish()?;
        return ocl::Result::Ok((xs, ys));
    }

    #[inline]
    fn try_cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> ocl::Result<u64> {
        if (self.use_f32) {
            return self.try_cal_f32(xs, ys, n);
        } else {
            return self.try_cal_f64(xs, ys, n);
        }
    }

    #[inline]
    fn try_cal_<T: OclPrm>(&self, xs: &Vec<T>, ys: &Vec<T>, n: usize) -> ocl::Result<u64> {
        let buffer_xs = self.create_buffer::<T>(n, Some(xs))?;
        let buffer_ys = self.create_buffer::<T>(n, Some(ys))?;
        let buffer_dummy = self.create_buffer::<u64>(1, None)?;
        let buffer_work_group_size = self.create_buffer::<u64>(1, None)?;
        let kernel = self.pro_que.kernel_builder("cal").arg(&buffer_xs).arg(&buffer_ys).arg(&buffer_dummy).arg_local::<u64>(n).arg(&buffer_work_group_size).build()?;

        // this `work_group_size` doesn't necessarily equal to local_size (see below)
        // for memory allocation, so bigger is better (maybe)
        let mut work_group_size = match get_kernel_work_group_info(&kernel, self.pro_que.device(), KernelWorkGroupInfo::WorkGroupSize) {
            Ok(KernelWorkGroupInfoResult::WorkGroupSize(wg_size)) => wg_size,
            _ => match get_device_info(self.pro_que.device(), DeviceInfo::MaxWorkGroupSize) {
                Ok(DeviceInfoResult::MaxWorkGroupSize(size)) => size,
                _ => n
            }
        };
        println!("work_group_size = {}", work_group_size);
        let buffer_partial_count = self.create_buffer::<u64>(n, None)?;
        kernel.set_arg(2, &buffer_partial_count)?;
        unsafe { clSetKernelArg(kernel.as_ptr(), 3, mem::size_of::<u64>() * work_group_size, null()); }
        unsafe { kernel.enq()?; }
        self.pro_que.finish()?;

        // read local_size as work_group_size because some platforms return max value when requesting CL_KERNEL_WORK_GROUP_SIZE
        let mut vec_work_group_size = vec![work_group_size as u64];
        buffer_work_group_size.read(&mut vec_work_group_size).enq()?;
        self.pro_que.finish()?;
        work_group_size = vec_work_group_size[0] as usize;
        println!("work_group_size = local_size = {}", work_group_size);
        let partial_count_len = (n as f64 / work_group_size as f64).ceil() as usize;
        println!("partial_count_len = {}", partial_count_len);
        let mut partial_count = vec![0 as u64; partial_count_len];
        buffer_partial_count.read(&mut partial_count).enq()?;
        self.pro_que.finish()?;

        // multi-thread isn't better here
        /*
        let partial_count = Arc::new(partial_count);
        let cnt = Arc::new(Mutex::new(0 as u64));
        let thread_count = num_cpus::get();
        let mut thread_handlers = Vec::new();
        let len = ((partial_count_len as f64) / (thread_count as f64)).ceil() as usize;
        for thread_index in 0..thread_count {
            let cnt = cnt.clone();
            let partial_count = partial_count.clone();
            thread_handlers.push(thread::spawn(move || {
                let mut lcnt: u64 = 0;
                for i in len * thread_index..min(len * (thread_index + 1), partial_count_len) {
                    lcnt += partial_count[i];
                }
                *(cnt.lock().unwrap()) += lcnt;
            }));
        } //
        for handler in thread_handlers {
            handler.join().expect("thread handler join() failed!");
        }
        let ret = *(cnt.lock().unwrap());
         */

        let mut ret = 0;
        for x in partial_count {
            ret += x;
        }
        return ocl::Result::Ok(ret);
    }

    #[inline]
    fn try_cal_f32(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> ocl::Result<u64> {
        let xs: Vec<f32> = xs.par_iter().map(|&x| x as f32).collect();
        let ys: Vec<f32> = ys.par_iter().map(|&y| y as f32).collect();
        return self.try_cal_::<f32>(&xs, &ys, n);
    }

    #[inline]
    fn try_cal_f64(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> ocl::Result<u64> {
        return self.try_cal_::<f64>(xs, ys, n);
    }

    #[inline]
    fn create_buffer<T: OclPrm>(&self, len: usize, orig_val: Option<&[T]>) -> ocl::Result<Buffer<T>> {
        let mut buffer_builder = Buffer::<T>::builder().queue(self.pro_que.queue().clone()).len(len);
        match orig_val {
            Some(val) => {
                if (self.is_unified_memory) {
                    unsafe { buffer_builder = buffer_builder.use_host_slice(val); }
                } else {
                    buffer_builder = buffer_builder.copy_host_slice(val);
                }
            }
            None => {
                if (self.is_unified_memory) {
                    // this is even worse ??
                    // buffer_builder = buffer_builder.flags(MemFlags::ALLOC_HOST_PTR);
                }
            }
        }
        return buffer_builder.build();
    }
}

impl MonteCarloPiCalculator for OpenCLThreadCalculator {
    #[inline]
    fn new(n: usize) -> OpenCLThreadCalculator {
        let platform = *Platform::list().first().unwrap();
        let device = Device::first(platform).expect("No device found in default platform!");
        let device_spec = DeviceSpecifier::Single(device);
        let device_info = device.info(DeviceInfo::Extensions).expect("Cannot get device info");
        let use_f32 = (device_info.to_string().find("cl_khr_fp64") == None);
        let mut src = String::new() + KERNEL_SRC;
        if (use_f32) {
            src = (String::new() + "#define REAL float\n" + KERNEL_SRC);
            println!("real -> f32 (float)");
        } else {
            println!("real -> f64 (double)");
        }

        let mut program_builder = ProgramBuilder::new();
        program_builder.src(src).cmplr_opt("");
        let pro_que = ProQue::builder().platform(platform).device(device_spec).prog_bldr(program_builder).dims(n).build().expect("Build OpenCL kernel failed!");

        let is_unified_memory;
        if let DeviceInfoResult::HostUnifiedMemory(b) = pro_que.context().device_info(0, DeviceInfo::HostUnifiedMemory).unwrap() {
            is_unified_memory = b;
        } else {
            is_unified_memory = false;
        }

        return OpenCLThreadCalculator {
            pro_que,
            use_f32,
            is_unified_memory,
        };
    }

    #[inline]
    fn gen_randoms(&self, n: usize) -> (Vec<f64>, Vec<f64>) {
        return self.try_gen_randoms(n).expect("Call to OpenCL kernel failed!");
    }

    #[inline]
    fn cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
        return self.try_cal(xs, ys, n).expect("Call to OpenCL kernel failed");
    }
}