//导出几个方法 可以共用
const fs = require('fs');
const {} = require('util');

//如果异步代码较多 容易产生回调地狱 封装成promise方便一些 
//这里不需要手动封装
exports.getDb = () => {
    fs.readFile
}