#![allow(unused_parens)]

mod distribution;
mod single_thread_calculator;
mod multi_thread_calculator;
mod opencl_calculator;
mod plot;
mod config;

use std::time::Instant;
use crate::distribution::{check_dist, print_vec};
use std::sync::Arc;
use crate::multi_thread_calculator::MultiThreadCalculator;
use crate::single_thread_calculator::SingleThreadCalculator;
use crate::opencl_calculator::OpenCLThreadCalculator;
use num::Float;
use std::cmp::min;
use crate::plot::{Env, Plot};
use crate::config::MontecarloPiConfig;
use lazy_static::lazy_static;
// use rayon::ThreadPool;

// static cpu_thread_pool: ThreadPool = rayon::ThreadPoolBuilder::new().num_threads(num_cpus::get()).build().unwrap();

lazy_static! {
    pub static ref CONFIG: MontecarloPiConfig = MontecarloPiConfig::new("montecarlo-pi.toml");
}

fn main() {
    let n = CONFIG.n;

    let implement = OpenCLThreadCalculator::new(n);
    let start_time = Instant::now();
    let xys = implement.gen_randoms(n);
    let xs = Arc::new(xys.0);
    let ys = Arc::new(xys.1);
    println!("gen_randoms() elapsed: {}ms", start_time.elapsed().as_millis());

    let start_time = Instant::now();
    let cnt = implement.cal(&xs, &ys, n);
    println!("calculation elapsed: {}ms", start_time.elapsed().as_millis());
    println!("{}", 4.0 * (cnt as f64) / (n as f64));

    print_vec(&check_dist(&xs, 0.0, 1.0 + f64::epsilon(), 10));
    print_vec(&check_dist(&ys, 0.0, 1.0 + f64::epsilon(), 10));

    // take first `m` points out and draw them
    let m = min(CONFIG.m, xs.len());
    let xs = xs.split_at(m).0.to_vec();
    let ys = ys.split_at(m).0.to_vec();

    let env = Env::new();
    let plot = Plot::new(&env);
    plot.figure(1);
    plot.scatter::<f64, f64>(&xs, &ys);
    plot.figure(2);
    plot.hist(&xs);
    plot.figure(3);
    plot.hist(&ys);
    plot.draw();
    plot.show();
}

#[inline]
fn gen_random(x: f64) -> f64 {
    let base = 65536.0;
    let a = 3289579.0;
    let b = 90238493.0;
    return ((a * x + b) % base) / base;
}

trait MonteCarloPiCalculator {
    fn new(n: usize) -> Self;
    fn gen_randoms(&self, n: usize) -> (Vec<f64>, Vec<f64>);
    fn cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64;
}