#![allow(unused_parens)]

pub mod opencl_calculator;
pub mod config;
pub mod util;
pub mod simulator;
pub mod constant;

use lazy_static::lazy_static;
use crate::config::MaxwellDistConfig;

lazy_static! {
    #[derive(Debug)]
    pub static ref CONFIG: MaxwellDistConfig = MaxwellDistConfig::new("maxwell-dist.toml");
}