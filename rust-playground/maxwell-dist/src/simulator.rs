use crate::opencl_calculator::OpenCLCalculator;
use crate::CONFIG;
use crate::constant;
use ocl::MemFlags;
use ocl::core;
use ocl::core::{Float3, Mem, Double3, Uint2, ArgVal, Kernel};
use rand::RngCore;

pub struct Simulator {
    pub calculator: OpenCLCalculator,
    pub buffer_r: Mem,
    pub buffer_v: Mem,
    pub kernel_gen_r: Kernel,
    pub kernel_gen_v: Kernel,
    pub kernel_update: Kernel,
}

impl Simulator {
    pub fn new(calculator: OpenCLCalculator) -> ocl::Result<Simulator> {
        let buffer_r: Mem;
        let buffer_v: Mem;
        if (calculator.use_f32) {
            let buf = calculator.create_buffer::<Float3>(calculator.n, None, MemFlags::default())?;
            buffer_r = buf.as_core().clone();
            let buf = calculator.create_buffer::<Float3>(calculator.n, None, MemFlags::default())?;
            buffer_v = buf.as_core().clone();
        } else {
            let buf = calculator.create_buffer::<Double3>(calculator.n, None, MemFlags::default())?;
            buffer_r = buf.as_core().clone();
            let buf = calculator.create_buffer::<Double3>(calculator.n, None, MemFlags::default())?;
            buffer_v = buf.as_core().clone();
        }

        let mut rng = rand::thread_rng();
        let program = calculator.pro_que.program();

        // kernel_gen_randoms3s_with_boundary, kernel_gen_r
        let kernel_gen_randoms3s_with_boundary = core::create_kernel(&program, "gen_randoms3s_with_boundary")?;
        core::set_kernel_arg(&kernel_gen_randoms3s_with_boundary, 0, ArgVal::mem(&buffer_r))?;
        if (calculator.use_f32) {
            core::set_kernel_arg(&kernel_gen_randoms3s_with_boundary, 1, ArgVal::vector(&Float3::new(CONFIG.lx as f32, CONFIG.ly as f32, CONFIG.lz as f32)))?;
        } else {
            core::set_kernel_arg(&kernel_gen_randoms3s_with_boundary, 1, ArgVal::vector(&Double3::new(CONFIG.lx, CONFIG.ly, CONFIG.lz)))?;
        }
        core::set_kernel_arg(&kernel_gen_randoms3s_with_boundary, 2, ArgVal::vector(&Uint2::new(rng.next_u32(), rng.next_u32())))?;


        // kernel_gen_randoms3s_with_max_normal2, kernel_gen_v
        let kernel_gen_randoms3s_with_max_normal2 = core::create_kernel(&program, "gen_randoms3s_with_max_normal2")?;
        core::set_kernel_arg(&kernel_gen_randoms3s_with_max_normal2, 0, ArgVal::mem(&buffer_v))?;
        let mean_square_v = (3.0 * constant::BOLTZMANN_CONSTANT * CONFIG.temperature / CONFIG.m);
        if (calculator.use_f32) {
            core::set_kernel_arg(&kernel_gen_randoms3s_with_max_normal2, 1, ArgVal::scalar(&(mean_square_v as f32)))?;
        } else {
            core::set_kernel_arg(&kernel_gen_randoms3s_with_max_normal2, 1, ArgVal::scalar(&mean_square_v))?;
        }
        core::set_kernel_arg(&kernel_gen_randoms3s_with_max_normal2, 2, ArgVal::vector(&Uint2::new(rng.next_u32(), rng.next_u32())))?;

        // kernel_update
        let kernel_update = core::create_kernel(&program, "update")?;
        core::set_kernel_arg(&kernel_update, 0, ArgVal::mem(&buffer_r))?;
        core::set_kernel_arg(&kernel_update, 1, ArgVal::mem(&buffer_v))?;
        if (calculator.use_f32) {
            core::set_kernel_arg(&kernel_update, 2, ArgVal::scalar(&(CONFIG.m as f32)))?;
            core::set_kernel_arg(&kernel_update, 3, ArgVal::vector(&(Float3::new(CONFIG.g[0] as f32, CONFIG.g[1] as f32, CONFIG.g[2] as f32))))?;
            core::set_kernel_arg(&kernel_update, 4, ArgVal::vector(&(Float3::new(CONFIG.lx as f32, CONFIG.ly as f32, CONFIG.lz as f32))))?;
            core::set_kernel_arg(&kernel_update, 5, ArgVal::scalar(&(CONFIG.dt as f32)))?;
        } else {
            core::set_kernel_arg(&kernel_update, 2, ArgVal::scalar(&CONFIG.m))?;
            core::set_kernel_arg(&kernel_update, 3, ArgVal::vector(&Double3::new(CONFIG.g[0], CONFIG.g[1], CONFIG.g[2])))?;
            core::set_kernel_arg(&kernel_update, 4, ArgVal::vector(&Double3::new(CONFIG.lx, CONFIG.ly, CONFIG.lz)))?;
            core::set_kernel_arg(&kernel_update, 5, ArgVal::scalar(&CONFIG.dt))?;
        }

        return Ok(Simulator {
            calculator,
            buffer_r,
            buffer_v,
            kernel_gen_r: kernel_gen_randoms3s_with_boundary,
            kernel_gen_v: kernel_gen_randoms3s_with_max_normal2,
            kernel_update,
        });
    }

    pub fn randomize(&self) {
        self.calculator.enqueue_kernel(&self.kernel_gen_r).unwrap();
        core::finish(&self.calculator.pro_que.as_core()).unwrap();
        self.calculator.enqueue_kernel(&self.kernel_gen_v).unwrap();
        core::finish(&self.calculator.pro_que.as_core()).unwrap();
    }
}

