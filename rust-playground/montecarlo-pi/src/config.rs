use std::fs::File;
use std::io::Read;
use serde::Deserialize;

#[derive(Deserialize)]
pub struct MontecarloPiConfig {
    #[serde(default = "default_n")]
    pub n: usize,

    #[serde(default = "default_cl_platform_id")]
    pub cl_platform_id: usize,

    #[serde(default = "default_cl_device_id")]
    pub cl_device_id: usize,

    #[serde(default = "default_use_f32")]
    pub use_f32: bool,

    #[serde(default = "default_m")]
    pub m: usize,

    #[serde(default = "default_cl_compile_arguments")]
    pub cl_compile_arguments: String,
}

#[inline]
fn default_n() -> usize { 1000000 }

#[inline]
fn default_cl_platform_id() -> usize { 0 }

#[inline]
fn default_cl_device_id() -> usize { 0 }

#[inline]
fn default_use_f32() -> bool { false }

#[inline]
fn default_m() -> usize { 100000 }

#[inline]
fn default_cl_compile_arguments() -> String { String::new() }

impl MontecarloPiConfig {
    pub fn new(config_path: &str) -> MontecarloPiConfig {
        let mut s = String::new();
        match File::open(config_path) {
            Ok(mut file) => {
                match file.read_to_string(&mut s) {
                    Ok(..) => {}
                    Err(e) => {
                        println!("[WARN] read config file {} failed: {}", config_path, e);
                    }
                }
            }
            Err(e) => {
                println!("[WARN] read config file {} failed: {}", config_path, e);
            }
        }
        return toml::from_str(&s).unwrap();
    }
}