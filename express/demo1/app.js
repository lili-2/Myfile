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

//__________________________________________________________________________________
//案例
// const express = require('express');
// const fs = require('fs');
// const app = express();

// app.get('/todos',(req,res)=>{
//     fs.readFile('./db.json','utf8',(err,data)=>{
//         if(err){
//             return res.status(500).json({
//                 error: err
//             });
//         }

//         const db = JSON.parse(data);
//         res.status(200).json(db.todos);
//     })
// })
// //：id是任意的 123 都行 只要前面有： 说明是任意的
// app.get('/todos/:id',(req,res)=>{
//     // res.send(`get /todos/${req.params.id}`)

//     fs.readFile('./db.json','utf8',(err,data)=>{
//         if(err){
//             return res.status(500).json({
//                 error: err
//             });
//         }
//         const db = JSON.parse(data);

//         // console.log(typeof req.params.id);//string
//         const todo = db.todos.find(todo => todo.id === Number.parseInt(req.params.id));//查找元素
//         // console.log(todo);
//         if(!todo){
//             return res.status(404).end();
//         }
//         res.status(200).json(todo);
//     })
// })
// app.post('/todos',(req,res)=>{
//     res.send('post /todos')
// })
// //修改
// app.patch('/todos/:id',(req,res)=>{
//     res.send(`patch /todos/${req.params.id}`)
// })
// app.delete('/todos/:id',(req,res)=>{
//     res.send(`delete /todos/${req.params.id}`)
// })
// app.listen(3000,()=>{
//     console.log('Sever running at http://127.0.0.1:3000/')
// })


//_______________________________________________________________________________________
//升级
const express = require('express');
const fs = require('fs');
const { getDb, saveDb } = require('./db');

const app = express();

// app.use(express.json());//配置解析解析表单请求体 json  把json转化成对象 application/json
// // app.use(express.urlencoded());// application/x-www-form-urlencoded

app.get('/todos', async (req, res) => {
    try {
        const db = await getDb();
        res.status(200).json(db.todos);
    } catch (err) {
        res.status(500).json({
            error: err.message
        });
    }
    // fs.readFile('./db.json','utf8',(err,data)=>{
    //     if(err){
    //         return res.status(500).json({
    //             error: err
    //         });
    //     }

    //     const db = JSON.parse(data);
    //     res.status(200).json(db.todos);
    // })
})
//：id是任意的 123 都行 只要前面有： 说明是任意的
app.get('/todos/:id', (req, res) => {
    // res.send(`get /todos/${req.params.id}`)

    fs.readFile('./db.json', 'utf8', async (err, data) => {
        try { 
            const db = await getDb();
            const todo = db.todos.find(todo => todo.id === Number.parseInt(req.params.id));
            if (!todo) {
                return res.status(404).end();
            }
            res.status(200).json(todo);

        } catch (err) {

            res.status(500).json({
                error: err
            });
        }
    })
})
app.use(express.json());//配置解析解析表单请求体 json  把json转化成对象 application/json
// app.use(express.urlencoded());// application/x-www-form-urlencoded
//添加任务 1：获取客户端请求体参数  2：数据验证 3：把数据存储到db中
app.post('/todos', async(req, res) => {
    try {
        // console.log(req.body);
        //1：获取客户端请求体参数
        const todo = req.body;

        // 2：数据验证
        if (!todo) {
            return res.status(422).json({
                error: 'the field title is required'
            })
        }
        //3：把数据存储到db中
        const db = await getDb();

        const lastTodo = db.todos[db.todos.lenght - 1].id;
        // todo.id = lastTodo ? lastTodo + 1 : 1;
        // dp.todos.push(todo);
        db.todos.push({
            id: lastTodo ? lastTodo.id+1 : 1,
            title: todo.title
        })//重新覆盖 
        await saveDb();
        res.status(200).json(todo);
    } catch (err) { 
        res.status(500).json(err.message);
    }
})
//修改
app.patch('/todos/:id', async (req, res) => {
    // res.send(`patch /todos/${req.params.id}`)
    try {
        const todo = req.body;
        const db = await getDb(); 
        const ret = db.todos.find(todo => todo.id === Math.parseInt(req.params.id));

        if(!ret){
            return res.status(404).end();
        }
        //合并 有就替换 没有就添加
        Object.assign(ret,todo);

        await saveDb(db);

        res.status(200).json(ret);
        
    } catch (err) {
        res.status(500).json(err.message);
    }
})
app.delete('/todos/:id', (req, res) => {
    // res.send(`delete /todos/${req.params.id}`)
    try {
        const todoId = Math.parseInt(req.params.id);
        const db = await getDb();
        const todo = db.todos.findIndex(todo => todo.id === todoId);
        if(index === -1){
            return res.status(404).end();
        }
        db.todos.splice(index,1);

        await saveDb(db);

        res.status(204).end();
        
    } catch (err) {
        res.status(500).json(err.message);
    }
})
app.listen(3000, () => {
    console.log('Sever running at http://127.0.0.1:3000/')
})