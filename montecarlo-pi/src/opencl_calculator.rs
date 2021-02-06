extern crate ocl;

use ocl::ProQue;
use crate::MonteCarloPiCalculator;
use std::sync::Arc;
use crate::multi_thread_calculator::MultiThreadCalculator;

pub struct OpenCLThreadCalculator {
    pro_que: ProQue
}

static KERNEL_SRC: &'static str = r#"
    // #define REAL float

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

    __kernel void gen_randoms(__global double* const xs, __global double* const ys){
        const unsigned int i = get_global_id(0);
        __private real t = gen_random((real) i);
        t = gen_random(t);
        t = gen_random(t);
        xs[i] = gen_random(t);
        ys[i] = gen_random(xs[i]);
    }
"#;

impl OpenCLThreadCalculator {
    #[inline]
    fn try_gen_randoms(&self, n: usize) -> ocl::Result<(Vec<f64>, Vec<f64>)> {
        let mut xs = vec![0.0; n];
        let mut ys = vec![0.0; n];
        let buffer_xs = self.pro_que.create_buffer::<f64>()?;
        let buffer_ys = self.pro_que.create_buffer::<f64>()?;
        let kernel = self.pro_que.kernel_builder("gen_randoms").arg(&buffer_xs).arg(&buffer_ys).build()?;
        unsafe { kernel.enq()?; }
        buffer_xs.read(&mut xs).enq()?;
        buffer_ys.read(&mut ys).enq()?;
        return ocl::Result::Ok((xs, ys));
    }
}

impl MonteCarloPiCalculator for OpenCLThreadCalculator {
    #[inline]
    fn new(n: usize) -> OpenCLThreadCalculator {
        return OpenCLThreadCalculator {
            pro_que: ProQue::builder().src(KERNEL_SRC).dims(n).build().expect("Build OpenCL kernel failed!")
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