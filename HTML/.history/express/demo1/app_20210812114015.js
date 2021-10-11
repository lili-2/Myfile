const express = require('express');

const app = express();

//当用户以get请求 路径/的时候
app.get('/',(req,res)=>{
    res.send('Hello World');
})