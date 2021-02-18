extern crate num;

use self::num::traits::real::Real;
use std::fmt::Display;

pub fn check_dist<T: Real>(v: &Vec<T>, l: T, r: T, n: usize) -> Vec<usize> {
    let len = (r - l) / T::from(n).unwrap();
    let mut dist = vec![0 as usize; n];
    for i in v {
        dist[((*i - l) / len).floor().to_usize().unwrap()] += 1;
    }
    return dist;
}

pub fn print_vec<T: Display>(v: &Vec<T>) {
    for i in v {
        print!("{} ", *i);
    }
    println!();
}