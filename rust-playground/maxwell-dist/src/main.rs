#![allow(unused_parens)]

use maxwell_dist::opencl_calculator::OpenCLCalculator;
use maxwell_dist::CONFIG;
use maxwell_dist::util::read_file;
use maxwell_dist::simulator::Simulator;
use ocl::core::Double3;

fn main() {
    let n = CONFIG.n;
    println!("{:#?}", *CONFIG);

    let src_maxwell_dist = read_file("src/maxwell-dist.cl");
    let src_randoms = read_file("src/randoms.cl");
    let calculator = OpenCLCalculator::new(n, vec![src_maxwell_dist, src_randoms]);
    let simulator;
    match Simulator::new(calculator) {
        Ok(s) => { simulator = s }
        Err(e) => {
            println!("[ERROR] {}", e);
            panic!()
        }
    }
    simulator.randomize();

    let mut rs = vec![Double3::zero(); n];
    simulator.calculator.enqueue_read_buffer(&simulator.buffer_r, &mut rs).unwrap();
    for r in rs {
        // println!("{},{},{}\n ", r[0] / CONFIG.lx, r[1] / CONFIG.ly, r[2] / CONFIG.lz);
    }
}
