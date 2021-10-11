var http = require('http');

//创建web服务 request获取 url传过来的信息  responsegei'liu'lan'qi
http.createServer(function (request, response) {
  response.writeHead(200, {'Content-Type': 'text/plain'});
  response.end('Hello World');
}).listen(8081);

console.log('Server running at http://127.0.0.1:8081/');