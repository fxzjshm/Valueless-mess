#![allow(unused_parens)]

use maxwell_dist::cl_util::OpenCLCalculator;
use maxwell_dist::CONFIG;
use maxwell_dist::util::read_file;

fn main() {
    // all values should be measured show
    let dt = CONFIG.dt;
    let n = CONFIG.n;

    let src = read_file("src/maxwell-dist.cl");
    let calculator = OpenCLCalculator::new(n, src);
}
