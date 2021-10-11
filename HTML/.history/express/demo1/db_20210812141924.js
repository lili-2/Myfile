//导出几个方法 可以共用
const fs = require('fs');
const { promisify } = require('util');
const readFile = promisify(fs.readFile);
const writeFile = promisify(fs.writeFile);
const path = require('path');

const dbPath = path.join(__dirname,'./db.json');

//如果异步代码较多 容易产生回调地狱 封装成promise方便一些 
//这里不需要手动封装
//promisify 把callback这种方式的API转换成promise对象
exports.getDb = async () => {
    const data = await readFile(dbPath,'utf8');
    return JSON.parse(data);
}
//async 即使返回普通数据 也会包装成promise对象
exports.saveDb = async db => {
    const data = JSON.stringify(db);
    await writeFile
}