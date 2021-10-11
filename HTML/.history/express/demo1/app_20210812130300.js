// const express = require('express');

// const app = express();

// //当用户以get请求 路径/的时候 调用该处理函数 req请求对象 获取客户端请求   res响应对象 处理请求之后给客户端发送响应
// app.get('/',(req,res)=>{
//     console.log(req.url);
//     console.log(req.method);
//     console.log(req.headers);
//     console.log(`请求参数  ${req.query}`);
//     res.send('Hello World');
// })
// app.post('/',(req,res)=>{
//     res.send('post /');
// })
// app.listen(3000,()=>{
//     console.log('Sever running at http://127.0.0.1:3000/')
// })
// //路由是指确定应用程序如何响应客户端对特定端点的请求 该特定端点的是URL（或路径）和特定的HTTP请求方法
// //每个路由可以具有一个或多个处理程序函数 这些函数在匹配路由时执行 路由定义采用 app.get()两个参数 第一个路径 第二个函数


// const express = require('express');

// const app = express();

//当用户以get请求 路径/的时候 调用该处理函数 req请求对象 获取客户端请求   res响应对象 处理请求之后给客户端发送响应
// app.get('/',(req,res)=>{
//     // res.statusCode = 201;

//     // res.write('a');
//     // res.write('b');
//     // res.write('c');
//     // res.end();
//     res.cookie('a','123');
//     res.status(201).send('OK');
// })
// app.post('/',(req,res)=>{
//     res.send('post /');
// })
// app.listen(3000,()=>{
//     console.log('Sever running at http://127.0.0.1:3000/')
// })

//案例
const express = require('express');
const fs = require('fs');

const app = express();

app.get('/todos',(req,res)=>{
    fs.readFile('./db/json','utf8',(err,data)=>{
        if(err){
            return res.status(500).json({
                error: err
            });
        }

        const db = JSON.parse(data);
        res.status(200).json(db.json)
    })
    res.send('get /todos')
})
//：id是任意的 123 都行 只要前面有： 说明是任意的
app.get('/todos/:id',(req,res)=>{
    res.send(`get /todos/${req.params.id}`)
})
app.post('/todos',(req,res)=>{
    res.send('post /todos')
})
//修改
app.patch('/todos/:id',(req,res)=>{
    res.send(`patch /todos/${req.params.id}`)
})
app.delete('/todos/:id',(req,res)=>{
    res.send(`delete /todos/${req.params.id}`)
})
app.listen(3000,()=>{
    console.log('Sever running at http://127.0.0.1:3000/')
})