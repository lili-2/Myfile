// const http = require('http');

// //创建web服务 request获取客户端 url传过来的信息  response给浏览器响应信息
// http.createServer(function (request, response) {

//     //设置响应头
//   response.writeHead(200, {'Content-Type': 'text/plain'});
   
//   //表示给我们页面上面输出一句话并结束响应
//   response.end('Hello World' );
// }).listen(8081);

// console.log('Server running at http://127.0.0.1:8081/'); 






// const http = require('http');
// const { updateFor } = require('typescript');
// http.createServer((req,res) => {

//     console.log(req.url);

//     res.writeHead(200,{"Content-type":"text/html;charset='utf-8'"})

//     //设置html 编码 这样汉语就不会乱码了
//     res.write('<head> <meta charset="Utf-8"></head>')
    
//     res.write("<h2>你好 node.js</h2>")
//     res.write('node js');
    
//     res.end();
    
// }).listen(3000);




// const url = require('url');

// var api = "http://www.itying.com?name=zhangsan&age=20";

// var getVal = url.parse(api,true).query;

// console.log(`姓名:${getVal.name} 年龄:${getVal.age}`);




const http = require('http');
const { updateFor } = require('typescript');
const url = re
http.createServer((req,res) => {

    console.log(req.url);

    res.writeHead(200,{"Content-type":"text/html;charset='utf-8'"})

    res.write('<head> <meta charset="Utf-8"></head>')
    
    console.log(req.url) //获取浏览器访问的地址

    if(req.url == '/favico.ico'){

    }
    
    res.end();
    
}).listen(3000);