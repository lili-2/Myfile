const express = require('express');

const app = express();

//当用户以get请求 路径/的时候 调用该处理函数 req请求对象 res响应对象
app.get('/',(req,res)=>{
    res.send('Hello World');
})