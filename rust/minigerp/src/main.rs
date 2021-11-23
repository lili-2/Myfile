use minigerp::Config;
use std::env;
use std::process;

fn main() {
    //args会产生一个迭代器 迭代器上有一个collect方法，将值转化为一个集合
    // let args: Vec<String> = env::args().collect();

    let config = Config::new(env::args()).unwrap_or_else(|err|{
        eprintln!("Problem parsing arguments: {}",err);
        process::exit(1);
    });

    //这里的Err是Result_enum的变体 不是新的类型
    if let Err(e) = minigerp::run(config) {
        eprintln!("Application err: {}",e);
        process::exit(1);
    }
}


//封装好的 下一步利用迭代器对代码进行修改
// use minigerp::Config;
// use std::env;
// use std::process;

// fn main() {
//     //args会产生一个迭代器 迭代器上有一个collect方法，将值转化为一个集合
//     let args: Vec<String> = env::args().collect();

//     let config = Config::new(&args).unwrap_or_else(|err|{
//         eprintln!("Problem parsing arguments: {}",err);
//         process::exit(1);
//     });

//     //这里的Err是Result_enum的变体 不是新的类型
//     if let Err(e) = minigerp::run(config) {
//         eprintln!("Application err: {}",e);
//         process::exit(1);
//     }
// }



//错误处理
// use std::env;
// use std::fs;
// use std::process;
// use std::error::Error;
// fn main() {
//     //args会产生一个迭代器 迭代器上有一个collect方法，将值转化为一个集合
//     let args: Vec<String> = env::args().collect();

//     let config = Config::new(&args).unwrap_or_else(|err|{
//         println!("Problem parsing arguments: {}",err);
//         process::exit(1);
//     });

//     //这里的Err是Result_enum的变体 不是新的类型
//     if let Err(e) = run(config) {
//         println!("Application err: {}",e);
//         process::exit(1);
//     }
// }


// struct Config {
//     query: String,
//     filename: String,
// }

// fn run(config: Config) -> Result<(),Box<dyn Error>>{
//     let contents = 
//         fs::read_to_string(config.filename)?;

//     println!("With text:\n{}",contents);

//     Ok(())
// }

// impl Config {
//     fn new(args: &[String]) -> Result<Config, &'static str> {

//         if args.len() < 3 {
//             return Err("not enough arguments"); 
//         }

//         let query = args[1].clone();

//         let filename = args[2].clone(); 

//         Ok(Config { query, filename })

//     }   
// }



//处理错误
// use std::env;
// use std::fs;
// use std::process;
// fn main() {
//     //args会产生一个迭代器 迭代器上有一个collect方法，将值转化为一个集合
//     let args: Vec<String> = env::args().collect();

//     let config = Config::new(&args).unwrap_or_else(|err|{
//         println!("Problem parsing arguments: {}",err);
//         process::exit(1);
//     });

//     let contents = fs::read_to_string(config.filename)
//     .expect("somenthing wrong");

//     println!("With text:\n{}",contents);
// }

// struct Config {
//     query: String,
//     filename: String,
// }

// impl Config {
//     fn new(args: &[String]) -> Result<Config, &'static str> {

//         if args.len() < 3 {
//             return Err("not enough arguments"); 
//         }

//         let query = args[1].clone();

//         let filename = args[2].clone(); 

//         Ok(Config { query, filename })

//     }   
// }




//重构前
// use std::env;
// use std::fs;
// fn main() {
//     //args会产生一个迭代器 迭代器上有一个collect方法，将值转化为一个集合
//     let args: Vec<String> = env::args().collect();

//     let query = &args[1];

//     let filename = &args[2]; 

//     println!("Search for  {}",query);
//     println!("In file {}",filename);

//     let contents = fs::read_to_string(filename)
//     .expect("somenthing wrong");

//     println!("With text:\n{}",contents);
// }