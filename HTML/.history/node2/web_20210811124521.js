//实现web服务器 可以让我们访问web服务器上面的网站 可以下载web服务器上的文件
//目前主流的服务器有Apache Nginx IIS
const http = require('http');
http.createServer(function (req, res) {

    //1.获取地址
    req.url




  res.writeHead(200, {'Content-Type': 'text/html;charset="utf-8"'});
  response.end('Hello World');
}).listen(8081);

console.log('Server running at http://127.0.0.1:8081/');
//http://127.0.0.1:8081/login.html  //http://127.0.0.1:8081/index.html