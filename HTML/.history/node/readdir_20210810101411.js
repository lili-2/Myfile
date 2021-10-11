//1. fs.stat 检索是文件还是目录
//2. fs.mkdir 创建目录
//3. fs.writeFile 创建写入目录
//4. fs.appendFile 追加目录
//5. fs.readFile 读取文件 .toString()
//6. fs.readdir 读取目录
//7. fs.rename 重命名 移动文件
//8. fs.rmdir 删除目录
//9. fs.unlink 删除文件
//10. fs.createReadSteam 从文件流中读取数据
const fs = require("fs");

// fs.stat('./www',(err,data)=> {
//     if(err){
//         console.log(err);
//         return ;
//     }

//     console.log(`是文件：${data.isFile()}`);
//     console.log(`是目录：${data.isDirectory()}`)
// })


// fs.writeFile('./www/hello.html',"你好node js 哈哈哈",(err)=>{
//     console.log(err);
// })


// fs.readdir('../node',function(err,data){
//     if(err){
//         console.log(err);
//     }else{
//         console.log(data);
//     }
// })
var readSteam = fs.createReadStream('./www/index.txt');
let count = 0;
let str = '';
readSteam.on('data',(data)=>{
    str+=
})