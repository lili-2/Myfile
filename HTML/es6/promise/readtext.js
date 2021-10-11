/**
 *  封装一个函数 mineReadFile 读取文件内容
 *  参数： path 文件路径
 *  返回： promise对象
 */
//不需要再原始后面写回调函数，可以在后面的使用的时候写
function  mineReadFile(path){
    return new Promise((resolve,reject) => {
        require('fs').readFile(path,(err, data) => {
            if(err) reject(err);
            resolve(data);
        });
    })
}

mineReadFile('./resource/content.txt').then(value => {
    console.log(value.toString());
},reason => {
    console.log(reason);
});

2
