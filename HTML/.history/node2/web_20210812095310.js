//实现web服务器 可以让我们访问web服务器上面的网站 可以下载web服务器上的文件
//目前主流的服务器有Apache Nginx IIS
const http = require('http');
const fs = require('fs');
const common = require('./module/common.js')
const path = require('path');
const url = require('url');
const ejs = require('ejs');


// http.createServer(function (req, res) {
//     common.static(req,res,'/tm')
// }).listen(3000);

// console.log('Server running at http://127.0.0.1:8081/');


// http.createServer(function (req, res) {

//     //1.获取地址
//     // let pathname = req.url;
//     let pathname = url.parse(req.url).pathname;

//     let extname = path.extname(pathname);//可以获取后缀名
//     //通过fs模块读取文件

//     //设置默认路径
//     pathname = pathname == '/' ? '/index/tm2.html' : pathname;
//     //2.通过fs模块读取文件
//     if(pathname != '/favicon.ico'){
//         fs.readFile('./tm' + pathname,(err,data)=>{
//             let mine = common.getMime(extname);
//             if(err){
//                 console.log('./tm' + pathname);
//                 res.writeHead(404, {'Content-Type': 'text/html;charset="utf-8"'});
//                 res.end('404 - 这个页面不存在');
//             }else{
//                 res.writeHead(200, {'Content-Type':`${mine};charset="utf-8"`});
//                 res.end(data);
//             }
//         })
//     }
// }).listen(3000);

// console.log('Server running at http://127.0.0.1:3000/');



http.createServer(function (req, res) {

    //1.获取地址
    // let pathname = req.url;
    let pathname = url.parse(req.url).pathname;

    let extname = path.extname(pathname);//可以获取后缀名
    //通过fs模块读取文件

    //设置默认路径
    pathname = pathname == '/' ? '/index/tm2.html' : pathname;
    //2.通过fs模块读取文件
    if (pathname != '/favicon.ico') {
        fs.readFile('./tm' + pathname, (err, data) => {
            let mine = common.getMime(extname);
            if (pathname == '/login') {
                let msg = "从数据库里面获取的数据";
                let list = [
                    {
                        title:'新闻111'
                    },
                    {
                        title:'新闻111'
                    },
                    {
                        title:'新闻111'
                    },
                    {
                        title:'新闻111'
                    },
                    {
                        title:'新闻111'
                    },
                ]
                ejs.renderFile('./views/login.ejs', { msg: msg }, (err, data) => {
                    res.writeHead(200, { 'Content-Type': `${mine};charset="utf-8"` });
                    res.end(data);
                })
            }
            else if (pathname == 'register') {
                res.writeHead(200, { 'Content-Type': `${mine};charset="utf-8"` });
                res.end('执行注册');
            } else if (pathname == 'admin') {
                res.writeHead(200, { 'Content-Type': `${mine};charset="utf-8"` });
                res.end('处理后的业务逻辑');
            } else {
                res.writeHead(200, { 'Content-Type': `${mine};charset="utf-8"` });
                res.end('404');
            }
        })
    }
}).listen(3000);