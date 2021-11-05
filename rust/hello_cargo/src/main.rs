
// use std::io;

// fn main() {
    
//     let mut n = String::new();
    
//     io::stdin().read_line(&mut n)
//         .expect("falied");

//     let n: u32 = n.trim().parse()
//         .expect("number");    
    
//     for i in 1..(n+1) {

//         println!("{}",i);
    
//     }
// }
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let ns: Vec<i32> = input.trim().split(' ').map(|x| x.parse().unwrap()).collect();
    for v in ns {
        print!("{} ", v);
    }
}
