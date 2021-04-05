use serde::Deserialize;
use crate::util::read_file;
use crate::constant;

#[derive(Deserialize)]
#[derive(Debug)]
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

    #[serde(default = "default_l")]
    pub lx: f64,

    #[serde(default = "default_l")]
    pub ly: f64,

    #[serde(default = "default_l")]
    pub lz: f64,

    #[serde(default = "default_temperature", alias = "T")]
    pub temperature: f64,

    #[serde(default = "default_r0")]
    pub r0: f64,

    #[serde(default = "default_m")]
    pub m: f64,

    #[serde(default = "default_g")]
    pub g: [f64; 3],
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
fn default_dt() -> f64 { 1e-7 }

#[inline]
fn default_l() -> f64 { 1e-8 }

#[inline]
fn default_temperature() -> f64 { 300.0 }

#[inline]
fn default_r0() -> f64 { 1e-10 }

#[inline]
fn default_m() -> f64 { constant::RELATIVE_ATOMIC_MASS }

#[inline]
fn default_g() -> [f64; 3] { [0.0; 3] }

impl MaxwellDistConfig {
    pub fn new(config_path: &str) -> MaxwellDistConfig {
        return toml::from_str(&read_file(config_path)).unwrap();
    }
}