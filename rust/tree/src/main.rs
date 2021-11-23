use std::env;
use std::fs;

fn main(){
    let args: Vec<String> = env::args().collect();
    println!("{:?}",args);

    // let query = &args[1];
    let filename = &args[2];

    let contents = fs::read_dir(filename)
        .expect("wrong file");

    for item in contents {
        println!("{}",item.unwrap().path().display())
    }

    // println!("{:?}",contents);
}