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
//11. fs.createWriteStream 写入文件 //58
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




// var readSteam = fs.createReadStream('./www/index.txt');
// let count = 0;
// let str = '';
// //数据过多的话 会读取多次
// readSteam.on('data',(data)=>{
//     str += data;
//     count++;
// })
// readSteam.on('end',()=>{
//     console.log(count);
//     console.log(str);
// })
// readSteam.on('error',(err)=>{
//     console.log(str);
//     console.log(count);
// })


// var str = '';
// for(var i = 0;i < 500;i++){
//     str+='我是从数据库获取的数据，我要保存起来\n'
// }

// const writeStream = fs.createWriteStream('./www/index.txt');

// writeStream.write(str);

// //是一个异步 需要标记写入完成

// writeStream.end();
// //只有标记写入完成 才能 触发finish事件

// writeStream.on('finish',()=>{
//     console.log('写入完成');
// })

//创建一个读取流 
var readSteam = fs.createReadStream('./www/pic1.jpg');
//创建一个写入流
var write