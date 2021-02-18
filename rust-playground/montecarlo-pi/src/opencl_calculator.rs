extern crate ocl;

use ocl::ProQue;
use crate::MonteCarloPiCalculator;
use std::sync::Arc;
use crate::multi_thread_calculator::MultiThreadCalculator;
use self::ocl::core::DeviceInfo;
use self::ocl::{Device, Platform};
use self::ocl::builders::DeviceSpecifier;
use rayon::prelude::*;
use std::rc::Rc;

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
        const real base = 65536.0;
        const real a = 3289579.0;
        const real b = 90238493.0;
        __private const real t = fma(a, x, b) / base;
        __private const long t_int = (long) t;
        return (t - (real) t_int);
    }

    __kernel void gen_randoms(__global real* const xs, __global real* const ys, const unsigned long n){
        const unsigned int i = get_global_id(0);
        __private real t = gen_random(((real) i) / n);
        t = gen_random(t);
        t = gen_random(t);
        xs[i] = gen_random(t);
        ys[i] = gen_random(xs[i]);
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
        let kernel = self.pro_que.kernel_builder("gen_randoms").arg(&buffer_xs).arg(&buffer_ys).arg(n as u64).build()?;
        unsafe { kernel.enq()?; }
        buffer_xs.read(&mut xs).enq()?;
        buffer_ys.read(&mut ys).enq()?;
        return ocl::Result::Ok((xs, ys));
    }

    #[inline]
    fn try_gen_randoms_f32(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        let mut xs = vec![0.0; n];
        let mut ys = vec![0.0; n];
        let buffer_xs = self.pro_que.create_buffer::<f32>()?;
        let buffer_ys = self.pro_que.create_buffer::<f32>()?;
        let kernel = self.pro_que.kernel_builder("gen_randoms").arg(&buffer_xs).arg(&buffer_ys).arg(n as u64).build()?;
        unsafe { kernel.enq()?; }
        buffer_xs.read(&mut xs).enq()?;
        buffer_ys.read(&mut ys).enq()?;
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
}

impl MonteCarloPiCalculator for OpenCLThreadCalculator {
    #[inline]
    fn new(n: usize) -> OpenCLThreadCalculator {
        let platform = Platform::default();
        let device = Device::first(platform).expect("No device found in default platform!");
        let device_spec = DeviceSpecifier::Single(device);
        let device_info = device.info(DeviceInfo::Extensions).expect("Cannot get device info");
        let use_f32 = (device_info.to_string().find("cl_khr_fp64") == None);
        let mut src = String::new() + KERNEL_SRC;
        if (use_f32) {
            src = (String::new() + "#define REAL float\n" + KERNEL_SRC);
        }

        let pro_que = ProQue::builder().platform(platform).device(device_spec).src(src).dims(n).build().expect("Build OpenCL kernel failed!");
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
        return MultiThreadCalculator::cal_static(xs, ys, n);
    }
}