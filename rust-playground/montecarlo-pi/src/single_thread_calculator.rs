use crate::{MonteCarloPiCalculator, gen_random};
use std::sync::Arc;

pub struct SingleThreadCalculator {}

impl SingleThreadCalculator {
    #[inline]
    fn gen_randoms_static(n: usize) -> (Vec<f64>, Vec<f64>) {
        let mut xs = vec![0.0; n];
        let mut ys = vec![0.0; n];
        for i in 0..n {
            let mut t = gen_random(i as f64 / n as f64);
            t = gen_random(t);
            t = gen_random(t);
            xs[i] = t;
            for _ in 0..10 {
                t = gen_random(t);
            }
            ys[i] = t;
        }
        return (xs, ys);
    }

    #[inline]
    #[allow(unused_parens)]
    fn cal_static(xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
        let mut cnt = 0;
        for i in 0..n {
            if (xs[i] * xs[i] + ys[i] * ys[i] < 1.0) {
                cnt += 1;
            }
        }
        return cnt;
    }
}


impl MonteCarloPiCalculator for SingleThreadCalculator {
    #[inline]
    fn new(_n: usize) -> SingleThreadCalculator {
        return SingleThreadCalculator {};
    }

    #[inline]
    fn gen_randoms(&self, n: usize) -> (Vec<f64>, Vec<f64>) {
        return SingleThreadCalculator::gen_randoms_static(n);
    }

    #[inline]
    fn cal(&self, xs: &Arc<Vec<f64>>, ys: &Arc<Vec<f64>>, n: usize) -> u64 {
        return SingleThreadCalculator::cal_static(xs, ys, n);
    }
}