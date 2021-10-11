//1. fs.stat 检索shi'wen'jian
let fs = require("fs");
fs.readdir('../node',function(err,data){
    if(err){
        console.log(err);
    }else{
        console.log(data);
    }
})