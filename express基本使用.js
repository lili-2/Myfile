//1. 引入express
const express = require('express');
const { request } = require('http');

//2. 创建应用对象
const app = express();

//3.创建路由归责 request 是对请求报文的封装 response 是对响应报文的封装

app.get('/',(request,response) => {
    //设置响应
    response.send('hello express');
});

//监听端口启动服务
app.listen(8000, ()=>{
    console.log("服务已经启动，8000 端口监听中...");
})

app.get('/delay',(request,response) => {
    //设置响应头，允许跨域
    setTimeout(() => {
        response.send('延时响应');
    },3000)
});