use std::fs::File;
use std::io::Read;

pub fn read_file(path: &str) -> String {
    let mut s = String::new();
    match File::open(path) {
        Ok(mut file) => {
            match file.read_to_string(&mut s) {
                Ok(..) => {}
                Err(e) => {
                    println!("[WARN] read config file {} failed: {}", path, e);
                }
            }
        }
        Err(e) => {
            println!("[WARN] read config file {} failed: {}", path, e);
        }
    }
    return s;
}