mod distribution;

use std::time::Instant;
use crate::distribution::{check_dist, print_vec};
use std::sync::{Arc, Mutex};
use std::thread;
use std::cmp::min;
use rayon::prelude::*;
// use rayon::ThreadPool;

// static cpu_thread_pool: ThreadPool = rayon::ThreadPoolBuilder::new().num_threads(num_cpus::get()).build().unwrap();

fn main() {
    let n = 100000000;

    let start_time = Instant::now();
    let xys = gen_randoms_n(n);
    let xs = Arc::new(xys.0);
    let ys = Arc::new(xys.1);
    println!("gen_randoms() elapsed: {}ms", start_time.elapsed().as_millis());

    let start_time = Instant::now();
    let cnt = cal_n(&xs, &ys, n);
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

#[inline]
fn gen_randoms_n(n: usize) -> (Vec<f64>, Vec<f64>) {
    let mut xs = vec![0.0; n];
    let mut ys = vec![0.0; n];

    xs.par_iter_mut().enumerate().for_each(|(i, val)| {
        let t = gen_random(i as f64);
        let t = gen_random(t);
        let t = gen_random(t);
        *val = gen_random(t);
    });

    ys.par_iter_mut().enumerate().for_each(|(i, val)| {
        *val = gen_random(xs[i]);
    });

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
fn cal_n(xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
    let cnt = Arc::new(Mutex::new(0 as u64));

    let thread_count = num_cpus::get();
    let mut thread_handlers = Vec::new();
    let len = ((n as f64) / (thread_count as f64)).ceil() as usize;
    for thread_index in 0..thread_count {
        let xs = xs.clone();
        let ys = ys.clone();
        let cnt = cnt.clone();
        thread_handlers.push(thread::spawn(move || {
            let mut lcnt: u64 = 0;
            for i in len * thread_index..min(len * (thread_index + 1), n) {
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