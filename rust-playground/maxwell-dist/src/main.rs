#![allow(unused_parens)]

use maxwell_dist::opencl_calculator::OpenCLCalculator;
use maxwell_dist::CONFIG;
use maxwell_dist::util::read_file;
use glutin::event_loop::EventLoop;
use glutin::window::WindowBuilder;
use glutin::dpi::LogicalSize;
use glutin::ContextBuilder;
use glutin::platform::ContextTraitExt;
use glutin::platform::unix::RawHandle::{Glx, Egl};
use std::ffi::c_void;

fn main() {
    let dt = CONFIG.dt;
    let n = CONFIG.n;

    let event_loop = EventLoop::new();
    let window_builder = WindowBuilder::new()
        .with_title("maxwell-dist")
        .with_inner_size(LogicalSize::new(CONFIG.window_width, CONFIG.window_height));
    let windowed_context = ContextBuilder::new()
        .build_windowed(window_builder, &event_loop)
        .unwrap();

    let src = read_file("src/maxwell-dist.cl");

    let mut gl_context = None;
    unsafe {
        #[cfg(windows)]
        match windowed_context.raw_handle() {
            Wgl(wgl_context) => { gl_context = Some(wgl_context) }
            Egl(egl_context) => { gl_context = Some(egl_context) }
        }

        #[cfg(any(target_os = "macos", target_os = "android", target_os = "emscripten", target_os = "ios"))]
            {
                gl_context = Some(windowed_context.raw_handle());
            }


        #[cfg(unix)]
        match windowed_context.raw_handle() {
            Glx(glx_context) => { gl_context = Some(glx_context) }
            Egl(egl_context) => { gl_context = Some(egl_context) }
        }
    }

    let gl_handle = match gl_context {
        Some(context) => {
            Some(unsafe { std::mem::transmute(context) })
        }
        None => { None }
    };

    let calculator = OpenCLCalculator::new(n, src, gl_handle);
}
