//1. fs.stat 检索是文件还是目录
//2. fs.mkdir
//3. fs.writeFile
//4. fs.appendFile
//5.fs.readFile
//6. fs.rename
//7. fs.
let fs = require("fs");
fs.readdir('../node',function(err,data){
    if(err){
        console.log(err);
    }else{
        console.log(data);
    }
})