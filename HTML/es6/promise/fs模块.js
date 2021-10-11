// //引入
// const fs = require('fs');

// //回调函数的形式
// //第一个参数，目标文件目录 第二个参数是回调 err是错误 data是读取到的
// fs.readFile('./resource/content.txt',(err, data) => {
//     if(err) throw err;
//     console.log(data.toString());
// });

// //Promise 形式
// let p = new Promise((resolve,reject) => {
//     fs.readFile('./resource/content.txt',(err, data) => {
//         if(err) reject(err);
//         resolve(data);
//     })
// });

// p.then(value => {
//     console.log(value.toString());
// },reason => {
//     console.log(reason);
// });