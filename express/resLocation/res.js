const express = require('express');
const server = express();

server.use('/',(req,res,next) => {
    return res.location('http://itbilu.com')
})

server.listen(8080,() => console.log('8080 开启'));