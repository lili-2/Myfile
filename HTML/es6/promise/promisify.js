/**
 * 错误优先的回调
 * util.promisify
 * util.promisify 传入一个遵循常见的错误优先的回调风格的函数 即(err, value) => {}，并返回一个promise的版本
 * fs中异步的api几乎都是错误优先的
 * 
 * 对于以后使用promise 
 * 不需要每一个方法都手动封装，而是可以借助 util.promisify 这个方法
 * 将以前那种回调函数风格的方法转变成promise风格的函数
 */


const util = require('util');
// const fs = require('fs');
// let mineReadFile = util.promisify(fs.readFile);
let mineReadFile = util.promisify(require('fs').readFile);


mineReadFile('./resource/content.txt').then(value => {
    console.log(value.toString());
},reason => {
    console.log(reason);
});

