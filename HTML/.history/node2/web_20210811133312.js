//实现web服务器 可以让我们访问web服务器上面的网站 可以下载web服务器上的文件
//目前主流的服务器有Apache Nginx IIS
const http = require('http');
const fs = require('fs');
const common = require('./module/common.js')
const path = require('path');
http.createServer(function (req, res) {

    //1.获取地址
    let pathname = req.url;

    let extname = path.extname(pathname);//可以获取后缀名
    //通过fs模块读取文件

    //设置默认路径
    pathname = pathname == '/' ? '/index/tm2.html' : pathname;
    //2.通过fs模块读取文件
    if(pathname != '/favicon.ico'){
        fs.readFile('./tm' + pathname,(err,data)=>{
            let mine = common.getMime(extname);
            if(err){
                console.log('./tm' + pathname);
                res.writeHead(404, {'Content-Type': 'text/html;charset="utf-8"'});
                res.end('404 - 这个页面不存在');
            }else{
                res.writeHead(200, {`Content-Type': ${};charset="utf-8"`});
                res.end(data);
            }
        })
    }
}).listen(3000);

console.log('Server running at http://127.0.0.1:3000/');
//http://127.0.0.1:3000/login.html  //http://127.0.0.1:3000/index.html