use serde::Deserialize;
use crate::util::read_file;

#[derive(Deserialize)]
pub struct MaxwellDistConfig {
    #[serde(default = "default_n")]
    pub n: usize,

    #[serde(default = "default_cl_platform_id")]
    pub cl_platform_id: usize,

    #[serde(default = "default_cl_device_id")]
    pub cl_device_id: usize,

    #[serde(default = "default_use_f32")]
    pub use_f32: bool,

    #[serde(default = "default_cl_compile_arguments")]
    pub cl_compile_arguments: String,

    #[serde(default = "default_dt")]
    pub dt: f64,
}

#[inline]
fn default_n() -> usize { 1000 }

#[inline]
fn default_cl_platform_id() -> usize { 0 }

#[inline]
fn default_cl_device_id() -> usize { 0 }

#[inline]
fn default_use_f32() -> bool { false }

#[inline]
fn default_cl_compile_arguments() -> String { String::new() }

#[inline]
fn default_dt() -> f64 { return 1e-7; }

impl MaxwellDistConfig {
    pub fn new(config_path: &str) -> MaxwellDistConfig {
        return toml::from_str(&read_file(config_path)).unwrap();
    }
}