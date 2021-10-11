const express = require('express');

const app = express();

//当用户以get请求 路径/的时候 调用该处理函数 req请求对象 获取客户端请求   res响应对象 处理请求之后给客户端发送响应
app.get('/',(req,res)=>{
    res.send('Hello World');
})

app.listen(3000,()=>{
    console.log('Sever running at http//127.0.0.1/3000/')
})
//路由是指确定应用程序如何响应客户端对特定端点的请求 该特定端点的是URL（或路径）和特定的HTTP请求方法
//每个路由可以具有一个或多个