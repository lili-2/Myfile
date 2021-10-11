// const http = require('http');

// //创建web服务 request获取 url传过来的信息  response给浏览器响应信息
// http.createServer(function (request, response) {

//     //设置响应头
//   response.writeHead(200, {'Content-Type': 'text/plain'});
   
//   //表示给我们页面上面输出一句话并结束响应
//   response.end('Hello World' );
// }).listen(8081);

// console.log('Server running at http://127.0.0.1:8081/'); 

const http = require('http');
http.createServer((req,res) => {

    console.log(req.url);

    res.writeHead(200,{'Content-type':'text/html;charset'})
})