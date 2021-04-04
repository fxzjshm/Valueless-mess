#![allow(unused_parens)]

pub mod cl_util;
pub mod config;
pub mod util;

use lazy_static::lazy_static;
use crate::config::MaxwellDistConfig;

lazy_static! {
    pub static ref CONFIG: MaxwellDistConfig = MaxwellDistConfig::new("maxwell-dist.toml");
}