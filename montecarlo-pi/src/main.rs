mod distribution;

use std::time::Instant;
use crate::distribution::{check_dist, print_vec};
use std::sync::{Arc, Mutex};
use std::thread;
// use rayon::ThreadPool;

// static cpu_thread_pool: ThreadPool = rayon::ThreadPoolBuilder::new().num_threads(num_cpus::get()).build().unwrap();

fn main() {
    let n = 100000000;

    let start_time = Instant::now();
    let xys = gen_randoms_1(n);
    let xs = xys.0;
    let ys = xys.1;
    println!("gen_randoms() elapsed: {}ms", start_time.elapsed().as_millis());

    let start_time = Instant::now();
    let cnt = cal_1(&xs, &ys, n);
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

#[inline]
fn gen_randoms_1(n: usize) -> (Vec<f64>, Vec<f64>) {
    let mut xs = vec![0.0; n];
    let mut ys = vec![0.0; n];
    for i in 0..n {
        let t = gen_random(i as f64);
        xs[i] = gen_random(t);
        ys[i] = gen_random(xs[i]);
    }
    return (xs, ys);
}

#[allow(unused_parens)]
fn cal_1(xs: &Vec<f64>, ys: &Vec<f64>, n: usize) -> u64 {
    let mut cnt = 0;
    for i in 0..n {
        if (xs[i] * xs[i] + ys[i] * ys[i] < 1.0) {
            cnt += 1;
        }
    }
    return cnt;
}

#[allow(unused_parens)]
fn cal_n(xs: &Vec<f64>, ys: &Vec<f64>, n: usize) -> u64 {
    let cnt = Arc::new(Mutex::new(0 as u64));
    let xs = Arc::new(xs.clone());
    let ys = Arc::new(ys.clone());
    let thread_count = num_cpus::get();
    let mut thread_handlers = Vec::new();
    for thread_index in 0..thread_count {
        let xs = xs.clone();
        let ys = ys.clone();
        let cnt = cnt.clone();
        thread_handlers.push(thread::spawn(move || {
            let mut lcnt: u64 = 0;
            for i in (thread_index..n).step_by(thread_count) {
                if (xs[i] * xs[i] + ys[i] * ys[i] < 1.0) {
                    lcnt += 1;
                }
            }
            *(cnt.lock().unwrap()) += lcnt;
        }));
    }
    for handler in thread_handlers {
        handler.join().expect("thread handler join() failed!");
    }
    return *(cnt.lock().unwrap());
}