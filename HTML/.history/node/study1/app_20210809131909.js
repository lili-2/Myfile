var http = require('http');

//创建web服务 request获取 url传过来的信息  response给浏览器响应信息
http.createServer(function (request, response) {

    //设置响应头
  response.writeHead(200, {'Content-Type': 'text/plain'});
  //表示
  response.end('Hello World');
}).listen(8081);

console.log('Server running at http://127.0.0.1:8081/');