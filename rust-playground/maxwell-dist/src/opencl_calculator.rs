use ocl::*;
use ocl::builders::*;
use ocl::enums::*;
use ocl::core;
use crate::CONFIG;

pub struct OpenCLCalculator {
    pub n: usize,
    pub pro_que: ProQue,
    pub use_f32: bool,
    pub is_unified_memory: bool,
}

impl OpenCLCalculator {
    #[inline]
    pub fn new(n: usize, src: Vec<String>) -> OpenCLCalculator {
        let platform = Platform::list()[CONFIG.cl_platform_id];

        let device = Device::by_idx_wrap(platform, CONFIG.cl_device_id).expect(&format!("[ERROR] No device {} found in platform {}", CONFIG.cl_device_id, CONFIG.cl_platform_id));
        let device_spec = DeviceSpecifier::Single(device);
        let mut use_f32 = CONFIG.use_f32;
        match device.info(DeviceInfo::Extensions) {
            Ok(device_info) => {
                use_f32 = use_f32 || (device_info.to_string().find("cl_khr_fp64") == None);
            }
            Err(e) => {
                println!("[WARN] Cannot get device info of device {} in platform {}, Error: {}",
                         CONFIG.cl_device_id, CONFIG.cl_platform_id, e);
            }
        }

        let context = Context::builder()
            // .properties(ocl_interop::get_properties_list().platform(platform))
            .platform(platform)
            .devices(device_spec)
            .build().unwrap();

        let mut program_builder = ProgramBuilder::new();
        if (use_f32) {
            program_builder.cmplr_opt("-D DOUBLEPREC=0");
            println!("real -> f32 (float)");
        } else {
            println!("real -> f64 (double)");
        }
        println!("[DEBUG] Platform: {}, Device: {}", platform.name().unwrap(), device.name().unwrap());

        for s in src {
            program_builder.source(s);
        }
        program_builder.cmplr_opt("-I src/");
        let pro_que = ProQue::builder().device(device).context(context).prog_bldr(program_builder).dims(n).build().expect("Build OpenCL kernel failed!");
        if let ProgramBuildInfoResult::BuildLog(log) = pro_que.program().build_info(device, ProgramBuildInfo::BuildLog).unwrap() {
            println!("[DEBUG] build log:\n{}", log);
        }

        let is_unified_memory;
        if let DeviceInfoResult::HostUnifiedMemory(b) = pro_que.context().device_info(0, DeviceInfo::HostUnifiedMemory).unwrap() {
            is_unified_memory = b;
        } else {
            is_unified_memory = false;
        }

        return OpenCLCalculator {
            n,
            pro_que,
            use_f32,
            is_unified_memory,
        };
    }

    #[inline]
    pub fn create_buffer<T: OclPrm>(&self, len: usize, orig_val: Option<&[T]>, memflags: MemFlags) -> ocl::Result<Buffer<T>> {
        let mut buffer_builder = Buffer::<T>::builder().queue(self.pro_que.queue().clone()).len(len);

        buffer_builder = buffer_builder.flags(memflags);
        if (memflags & (MemFlags::ALLOC_HOST_PTR | MemFlags::USE_HOST_PTR | MemFlags::COPY_HOST_PTR) == MemFlags::from_bits(0).unwrap()) {
            match orig_val {
                Some(val) => {
                    if (self.is_unified_memory) {
                        unsafe { buffer_builder = buffer_builder.use_host_slice(val); }
                    } else {
                        buffer_builder = buffer_builder.flags(MemFlags::ALLOC_HOST_PTR);
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
        }
        return buffer_builder.build();
    }

    #[inline]
    pub fn enqueue_kernel(&self, kernel: &ocl::core::Kernel) -> ocl::core::Result<()>{
        unsafe {
            core::enqueue_kernel::<(), ()>(self.pro_que.queue().as_core(),
                                           kernel, 1, None,
                                           &[self.n, 0, 0], None,
                                           None, None)
        }
    }

    #[inline]
    pub fn enqueue_read_buffer<T: OclPrm, M: ocl::core::AsMem<T> + ocl::core::MemCmdRw>(&self, buffer: M, data: &mut [T]) ->  ocl::core::Result<()>{
        unsafe {
            core::enqueue_read_buffer::<T, M, (), ()>(self.pro_que.queue().as_core(), buffer,
                                                      true, 0, data, None, None)
        }
    }
}