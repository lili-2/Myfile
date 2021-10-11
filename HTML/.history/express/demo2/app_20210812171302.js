const express = require('express');

const app = express()

// const myLogger = (req) => { 
//     console.log(req.method,req.url,Date.now());
// }

// app.use(express.json());
// app.use(express.urlencoded());
//加了这个 就可以用 req.body 获取请求体数据

//所有请求都要进入他 要放行 否则会一直卡在这
//三个参数 req 当前请求的请求对象 res 当前请求的响应对象 next 函数，调用它就是调用下一个中间件
//它可以匹配所有的请求
//顺序很重要 从上往下
//路由也是由中间件处理的  也有next函数

function json (options){
    return (req,res,next)=>{
        console.log(`hello ${options.message}`);
    }
}
app.use



app.use((req, res, next) => {
    // console.log('hello');
    req.foo = 'bar';
    //在整个响应的生命周期当中 后面所有的都可以访问到foo 
    //在同一次生命周期当中 共享的是同一个req res
    console.log(req.method, req.url, Date.now());
    //往后继续执行
    next();//next 调用下一个匹配的中间件
})
app.get('/', (req, res, next) => {
    // console.log(req.foo); //bar
    res.send('get /');
    // next(); 
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