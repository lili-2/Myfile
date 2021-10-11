//1. fs.stat 检索是文件还是目录
//2. fs.mkdir 创建目录
//3. fs.writeFile 创建写入目录
//4. fs.appendFile 追加目录
//5. fs.readFile 读取目录
//6. fs.rename 重命名
//7. fs.rename 重命名
let fs = require("fs");
fs.readdir('../node',function(err,data){
    if(err){
        console.log(err);
    }else{
        console.log(data);
    }
})