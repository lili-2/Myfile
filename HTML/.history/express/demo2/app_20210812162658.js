const express = require('express');

const app = express()

// const myLogger = (req) => { 
//     console.log(req.method,req.url,Date.now());
// }

// app.use(express.json());
// app.use(express.urlencoded());

//所有请求都要进入他 要放行 否则会一直卡在这
//三个参数 req 当前请求的请求对象 res 当前请求的响应对象 next 函数，调用它就是调用下一个中间件
//它可以匹配所有的请求
app.use((req, res, next) => {
    // console.log('hello');
    console.log(req.method,req.url,Date.now());
    //往后继续执行
    next();//next 调用下一个匹配的中间件
})

app.get('/', (req, res) => {
    res.send('get /');
})
app.get('/about', (req, res) => {
    res.send('get /about');
})
app.post('/login', (req, res) => {
    res.send('get /login');
})
app.listen(3000, () => {
    console.log(`Sever running at 3000`)
})