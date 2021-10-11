//1. fs.stat 检索是文件还是目录
//2. fs.mkdir
//2. fs.
let fs = require("fs");
fs.readdir('../node',function(err,data){
    if(err){
        console.log(err);
    }else{
        console.log(data);
    }
})