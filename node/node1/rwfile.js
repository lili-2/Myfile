const fs = require('fs');

// fs.mkdir('aaa',(err) => {
//     console.log(err);
// });

// fs.readFile('aaa/1.txt',(err,data) => {
//     if(err){
//         console.log('读取文件失败',err);
//     }else{
//         console.log(data.toString());
//      }
// })

// const { rejects } = require('assert');
// //同步
// var fd = fs.openSync('www/index.txt','r');
// // var content = fs.readFileSync(fd,{flag:'r',encoding:"utf-8"});
// console.log(content);
// // var content = fs.readFileSync(fd);
// console.log(content.toString());

// //异步
// fs.readFile('www/index.txt',{flag:'r',encoding:'utf-8'},function(err,data){
//     if(err){
//         console.log(err)
//     }else{
//         console.log(data);
//     }
// })

//封装 promise 异步
function fsRead(path){
    return  new Promise(function(resolve,reject){
        fs.readFile(path,{flag:'r',encoding:'utf-8'},function(err,data){
            if(err){
                reject(err);
            }else{
                resolve(data);
            }
        })
    })
}
// var w1 = fsRead('www/index.txt').then(function(res){
//     console.log(res);
// })


// async function Readlist(){
//     var file2 = await fsRead('www/index.txt');
//     var file3 = await fsRead('www/w1.html');
//     console.log(file2);
//     console.log(file3);
// }
// Readlist();

