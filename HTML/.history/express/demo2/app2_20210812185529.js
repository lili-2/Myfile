//中间件分类
// 应用程序级别的中间件
// 路由级别的中间件
// 错误处理中间件
// 内置中间件
// 第三方中间件
const express = require('express');

const app = express()

// //不做任何修饰的和中间件
// app.use(function(req,res,next){
//     console.log('Time:',Date.now());
//     next();
// })

// // 限定请求路径
// app.use('/user/:id',function(req,res,next){
//     console.log('Time:',Date.now());
//     next();
// })

//限定请求方法 + 请求路径 == 路由
// app.get('/', (req, res) => {
//     res.send('Hello World!')
// })
//app.post put patch delete

//多个处理函数
app.use('/user/:id',function(req,res,next){
    console.log('Request URL',req.originalUrl);
    next();
},function(req,res,next){
    console.log('Request Type')
})


app.listen(3000, () => {
    console.log(`3000`)
})