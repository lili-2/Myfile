//导出几个方法 可以共用
const fs = require('fs');

//如果异步代码较多 容易产生回调地狱 封装成promise更好
exports.getDb = () => {
    fs.readFile
}