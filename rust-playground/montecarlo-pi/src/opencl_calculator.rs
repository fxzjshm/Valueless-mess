extern crate ocl;

use ocl::ProQue;
use crate::MonteCarloPiCalculator;
use std::sync::Arc;
use self::ocl::core::{DeviceInfo, MEM_READ_ONLY, get_kernel_work_group_info, KernelWorkGroupInfo, MEM_READ_WRITE};
use self::ocl::{Device, Platform, Buffer};
use self::ocl::builders::{DeviceSpecifier, ProgramBuilder};
use rayon::prelude::*;
use std::time::Instant;
use self::ocl::enums::KernelWorkGroupInfoResult;
use core::mem;
use self::ocl::core::ffi::clSetKernelArg;
use std::ptr::null;

pub struct OpenCLThreadCalculator {
    pro_que: ProQue,
    use_f32: bool,
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
    __kernel void cal(__global real* const xs, __global real* const ys, __global unsigned long* output, __local unsigned long* reductionSums) {
        const size_t global_id = get_global_id(0),
                  /* global_size = get_global_size(0), */
                     local_id = get_local_id(0),
                     local_size = get_local_size(0),
                     work_group_id = global_id / local_size;
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
        let mut xs = vec![0.0; n];
        let mut ys = vec![0.0; n];
        let buffer_xs = self.pro_que.create_buffer::<f64>()?;
        let buffer_ys = self.pro_que.create_buffer::<f64>()?;
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
    fn try_gen_randoms_f32(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        let mut xs = vec![0.0; n];
        let mut ys = vec![0.0; n];
        let buffer_xs = self.pro_que.create_buffer::<f32>()?;
        let buffer_ys = self.pro_que.create_buffer::<f32>()?;
        let kernel = self.pro_que.kernel_builder("gen_randoms").arg(&buffer_xs).arg(&buffer_ys).build()?;
        let start_time = Instant::now();
        unsafe { kernel.enq()?; }
        self.pro_que.finish()?;
        println!("kernel enqueue used: {}ms", start_time.elapsed().as_millis());
        buffer_xs.read(&mut xs).enq()?;
        buffer_ys.read(&mut ys).enq()?;
        self.pro_que.finish()?;
        let mut xs_ret = vec![0.0; n];
        xs_ret.par_iter_mut().enumerate().for_each(|(i, val)| {
            *val = xs[i] as f64;
        });
        let mut ys_ret = vec![0.0; n];
        ys_ret.par_iter_mut().enumerate().for_each(|(i, val)| {
            *val = ys[i] as f64;
        });
        return ocl::Result::Ok((xs_ret, ys_ret));
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
    fn try_cal_f64(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> ocl::Result<u64> {
        let buffer_xs = Buffer::<f64>::builder().queue(self.pro_que.queue().clone()).flags(MEM_READ_ONLY).len(n).copy_host_slice(&xs).build()?;
        let buffer_ys = Buffer::<f64>::builder().queue(self.pro_que.queue().clone()).flags(MEM_READ_ONLY).len(n).copy_host_slice(&ys).build()?;
        let buffer_dummy = Buffer::<u64>::builder().queue(self.pro_que.queue().clone()).len(1).build()?;
        let kernel = self.pro_que.kernel_builder("cal").arg(&buffer_xs).arg(&buffer_ys).arg(&buffer_dummy).arg_local::<u64>(n).build()?;
        let work_group_size;
        if let KernelWorkGroupInfoResult::WorkGroupSize(wg_size) = get_kernel_work_group_info(&kernel, self.pro_que.device(), KernelWorkGroupInfo::WorkGroupSize).unwrap() {
            work_group_size = wg_size;
        } else {
            work_group_size = n;
        }
        println!("[DEBUG] try_cal_f64(): work_group_size = {}", work_group_size);
        let partial_count_len = (n as f64 / work_group_size as f64).ceil() as usize;
        let buffer_partial_count = Buffer::<u64>::builder().queue(self.pro_que.queue().clone()).len(partial_count_len).build()?;
        kernel.set_arg(2, &buffer_partial_count)?;
        unsafe { clSetKernelArg(kernel.as_ptr(), 3, mem::size_of::<u64>() * work_group_size, null()); }
        unsafe { kernel.enq()?; }
        self.pro_que.finish()?;
        let mut partial_count = vec![0 as u64; partial_count_len];
        buffer_partial_count.read(&mut partial_count).enq()?;
        self.pro_que.finish()?;
        let mut ret = 0;
        for x in partial_count {
            ret += x;
        }
        return ocl::Result::Ok(ret);
    }

    #[inline]
    fn try_cal_f32(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> ocl::Result<u64> {
        unimplemented!();
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
        return OpenCLThreadCalculator {
            pro_que,
            use_f32,
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