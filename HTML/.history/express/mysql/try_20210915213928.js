const http=require('http'); 

var server = http.createServer(function(){
    console.log('有人来啦!!!');
});

//监听---等着
//端口---数字
server.listen(8080);

const http = require('http');

//服务器 request请求 输入 浏览器发送过来的页面 response响应 输出，你要发给浏览器的东西
let server = http.createServer(function(request,response){

    console.log('有人');

    console.log(request.url);
    // response.write('aaaaa');
    // response.end();

    
    if(request.url == '/1.html'){
        response.write('<html><head></head><body><div style="width:200px;height:200px;background:red"></div></body></html>');
        response.end();
    }else if(request.url == '/1.txt'){
        response.write('<html><head></head><body><div style="width:200px;height:200px;background:blue"></div></body></html>');
        response.end();
    }else{
        response.write('404');
        response.end();
    }
});
//监听，开始等待客户端的连接 端口号 ctrl+c 命令行终止
server.listen(8080);

