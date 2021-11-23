// // match 它允许将一个值与一系列的模式相比较 并根据匹配的模式执行相应的代码
// enum Coin {
//     Penny,
//     Nickel,
//     Dime,
//     Quarter,
// }
// fn value_in_cents(coin:Coin) -> u32{
//     match coin {
//         Coin::Penny => 1,
//         _ => 2,
//     }
// }
// fn main(){
    
// }





//Option 类型 描述了一种值可能不存在的情形
// enum Option<T> {
//     Some(T),
//     None,
// }
// fn main(){

// }



// 枚举允许我们直接将其关联的数据嵌入枚举变体中
//每个变体可以拥有不同类型和数量的关联数据

// enum IpAddr {
//     V4(u8,u8,u8,u8),
//     V6(String)
// }

// fn main() {
//     let home = IpAddr::V4(127,0,0,1);
//     let loopback = IpAddr::V6(String::from("::1"));
// }


//关联函数
// # [derive(Debug)]
// struct Rectangle {
//     width: u32,
//     height: u32,
// }

// impl Rectangle {
//     fn square(size:u32) -> Rectangle{
//         Rectangle {width: size,height: size}
//     }
// }

// fn main(){

//     let sq = Rectangle::square(3);
//     println!("{:#?}",sq);
// }

//结构体中的方法

// # [derive(Debug)]
// struct Rectangle {
//     width: u32,
//     height: u32,
// }

// impl Rectangle {
//     fn area(&self) -> u32{
//         self.width * self.height
//     }

//     fn can_hold(&self,other: &Rectangle) -> bool{
//         self.width > other.width && self.height > other.height
//     }
// }
 
// fn main(){

//     let rect1 = Rectangle {width: 30,height: 50};
//     let rect2 = Rectangle {width:20,height:20};

//     println!("Can I hold reat {}",rect1.can_hold(&rect2));

//     println!("area {}",rect1.area());
// }






//结构体 输出
// # [derive(Debug)]
// struct Rectangle {
//     width: u32,
//     height: u32,
// }

// fn main(){
//     let rect1 = Rectangle {width: 30,height: 50};
//     println!("rect1 is {:#?}",rect1);
// }

//输入
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

//连续输入
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let ns: Vec<i32> = input.trim().split(' ').map(|x| x.parse().unwrap()).collect();
    for v in ns {
        print!("{} ", v);
    }
}


    