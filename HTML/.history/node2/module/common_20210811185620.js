const http = require('http');
const fs = require('fs');
const path = require('path');
const url = require('url');
 
exports.getMime = function(extname){
    switch(extname){
        case '.html':
            return 'text/html';
        case '.css':
            return 'text/css';
        case '.js':
            return 'text/javascript';
        default:
            return 'text/html'

    }
}

exports.static = function(req,res,staticpath){
    
        //1.获取地址
        // let pathname = req.url;
        let pathname = url.parse(req.url).pathname;
    
        let extname = path.extname(pathname);//可以获取后缀名
        //通过fs模块读取文件
    
        //设置默认路径
        pathname = pathname == '/' ? '/index/tm2.html' : pathname;
        //2.通过fs模块读取文件
        if(pathname != '/favicon.ico'){
            fs.readFile(`./${staticpath}` + pathname,(err,data)=>{
                let mine = exports.getMime(extname);
                if(err){
                    console.log('./tm' + pathname);
                    res.writeHead(404, {'Content-Type': 'text/html;charset="utf-8"'});
                    res.end('404 - 这个页面不存在');
                }else{
                    res.writeHead(200, {'Content-Type':`${mine};charset="utf-8"`});
                    res.end(data);
                }
            })
        }
}