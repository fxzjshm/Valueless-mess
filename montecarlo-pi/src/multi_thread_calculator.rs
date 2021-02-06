use crate::{MonteCarloPiCalculator, gen_random};
use rayon::prelude::*;
use std::sync::{Arc, Mutex};
use std::thread;
use std::cmp::min;

pub struct MultiThreadCalculator {}

impl MultiThreadCalculator {
    #[inline]
    pub fn new() -> MultiThreadCalculator {
        return MultiThreadCalculator {};
    }

    #[inline]
    fn gen_randoms_static(n: usize) -> (Vec<f64>, Vec<f64>) {
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

    #[inline]
    #[allow(unused_parens)]
    fn cal_static(xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
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
}

impl MonteCarloPiCalculator for MultiThreadCalculator {
    #[inline]
    fn gen_randoms(&self, n: usize) -> (Vec<f64>, Vec<f64>) {
        return MultiThreadCalculator::gen_randoms_static(n);
    }

    #[inline]
    fn cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
        return MultiThreadCalculator::cal_static(xs, ys, n);
    }
}