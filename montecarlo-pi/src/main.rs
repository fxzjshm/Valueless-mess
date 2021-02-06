mod distribution;
mod single_thread_calculator;
mod multi_thread_calculator;

use std::time::Instant;
use crate::distribution::{check_dist, print_vec};
use std::sync::Arc;
use crate::multi_thread_calculator::MultiThreadCalculator;
use crate::single_thread_calculator::SingleThreadCalculator;
// use rayon::ThreadPool;

// static cpu_thread_pool: ThreadPool = rayon::ThreadPoolBuilder::new().num_threads(num_cpus::get()).build().unwrap();

fn main() {
    let n = 100000000;

    let implement = SingleThreadCalculator::new();
    let start_time = Instant::now();
    let xys = implement.gen_randoms(n);
    let xs = Arc::new(xys.0);
    let ys = Arc::new(xys.1);
    println!("gen_randoms() elapsed: {}ms", start_time.elapsed().as_millis());

    let start_time = Instant::now();
    let cnt = implement.cal(&xs, &ys, n);
    println!("calculation elapsed: {}ms", start_time.elapsed().as_millis());
    println!("{}", 4.0 * (cnt as f64) / (n as f64));

    print_vec(&check_dist(&xs, 0.0, 1.0, 10));
    print_vec(&check_dist(&ys, 0.0, 1.0, 10));
}

#[inline]
fn gen_random(x: f64) -> f64 {
    let base = 65536.0;
    let a = 3289579.0;
    let b = 90238493.0;
    return ((a * x + b) % base) / base;
}

trait MonteCarloPiCalculator {
    fn gen_randoms(&self, n: usize) -> (Vec<f64>, Vec<f64>);
    fn cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64;
}