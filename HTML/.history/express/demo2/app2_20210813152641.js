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

//多个处理函数 都被调用 
// app.use('/user/:id',function(req,res,next){
//     console.log('Request URL',req.originalUrl);//获取原始地址
//     next();//就是下一个函数
// },function(req,res,next){
//     console.log('Request Type:',req.method);
//     next();//这个next会脱离当前处理栈 往后查找匹配调用
// })
// app.get('/user/:id', (req, res) => {
//     res.send('get /user/:id')
// })

//为同一个路径定义多个处理中间件
// app.get('/user/:id',
//     function(req,res,next){
//         console.log('ID',req.params.id);
//         next();
//     },function(req,res,next){
//         res.end('user Info'); // 结束响应发送数据 已经结束
//         next();// 不加next() 则下面的函数不会被执行
//     })
// app.get('/user/:id', (req, res) => {
//     console.log(123);
//     res.send(req.params.id);//上面的send已经结束响应 
//     //有next会输出 123 但是会报错 不让发响应的话 不会报错 123可以输出
// })


//要从路由器中间件堆栈中跳过其余中间件功能时 请调用next('route')将控制权传递给下一条路由
//

app.listen(3000, () => {
    console.log(`3000`)
})