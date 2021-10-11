//路由器级别中间件
//141 错误处理中间件  以与其他中间件函数相同的方式定义错误处理中间件函数，始终使用四个参数
//136  404处理 默认页面显示 Cannot GET /abc 自定义 

const express = require('express');
// const fs = require('fs');
// const { getDb, saveDb } = require('./db');
const router = require('./router');

const app = express();

app.use(express.json());//配置解析解析表单请求体 json  把json转化成对象 application/json
// app.use(express.urlencoded());// application/x-www-form-urlencoded

// app.get('/todos', async (req, res) => {
//     try {
//         const db = await getDb();
//         res.status(200).json(db.todos);
//     } catch (err) {
//         res.status(500).json({
//             error: err.message
//         });
//     }
//     // fs.readFile('./db.json','utf8',(err,data)=>{
//     //     if(err){
//     //         return res.status(500).json({
//     //             error: err
//     //         });
//     //     }
//     //     const db = JSON.parse(data);
//     //     res.status(200).json(db.todos);
//     // })
// })
// //：id是任意的 123 都行 只要前面有： 说明是任意的
// app.get('/todos/:id', (req, res) => {
//     // res.send(`get /todos/${req.params.id}`)

//     fs.readFile('./db.json', 'utf8', async (err, data) => {
//         try {

//             const db = await getDb();
//             const todo = db.todos.find(todo => todo.id === Number.parseInt(req.params.id));
//             if (!todo) {
//                 return res.status(404).end();
//             }
//             res.status(200).json(todo);

//         } catch (err) {

//             res.status(500).json({
//                 error: err
//             });
//         }
//     })
// })
// //添加任务 1：获取客户端请求体参数  2：数据验证 3：把数据存储到db中
// app.post('/todos', async(req, res) => {
//     try {
//         // console.log(req.body);
//         //1：获取客户端请求体参数
//         const todo = req.body;

//         // 2：数据验证
//         if (!todo) {
//             return res.status(422).json({
//                 error: 'the field title is required'
//             })
//         }
//         //3：把数据存储到db中
//         const db = await getDb();

//         const lastTodo = db.todos[db.todos.lenght - 1].id;
//         todo.id = lastTodo ? lastTodo + 1 : 1;
//         dp.todos.push(todo);

//         await saveDb();
//         res.status(200).json(todo);
//     } catch (err) {
//         res.status(500).json(err.message);
//     }
// })
// //修改
// app.patch('/todos/:id', async (req, res) => {
//     // res.send(`patch /todos/${req.params.id}`)
//     try {
//         const todo = req.body;
//         const db = await getDb();
//         const ret = db.todos.find(todo => todo.id === Math.parseInt(req.params.id));

//         if(!ret){
//             return res.status(404).end();
//         }
//         //合并 有就替换 没有就添加
//         Object.assign(ret,todo);

//         await saveDb(db);

//         res.status(200).json(ret);
        
//     } catch (err) {
//         res.status(500).json(err.message);
//     }
// })
// app.delete('/todos/:id', async(req, res) => {
//     // res.send(`delete /todos/${req.params.id}`)
//     try {
//         const todoId = Math.parseInt(req.params.id);
//         const db = await getDb();
//         const todo = db.todos.findIndex(todo => todo.id === todoId);
//         if(index === -1){
//             return res.status(404).end();
//         }
//         db.todos.splice(index,1);

//         await saveDb(db);

//         res.status(204).end();
        
//     } catch (err) {
//         res.status(500).json(err.message);
//     }
// })

//___________________________________________________________________________________________________________
//挂载路由  这就是路由器级别的中间件 
// //router.js中路径写的是什么就是什么
// app.use(router);
//通过这种方法也能添加中间件 通过这种方式添加和通过express实例添加是一样的

//给路由限定访问前缀  相当于给router.js中的路径每个都添加了前缀
// app.use('/abc',router);
//可以把以上的代码 改成这种形式 代码移入router 加前缀 /todos
app.use('/todos',router);

//通常会在所有的路由之后 配置处理404的  请求进来从上到下一次匹配
app.use((req,res,next) => {
    res.status(404).send('404 Not Found')
})//这个与错误处理是不一样的 错误处理：在之前的路由中调用next(err)
//404是上面匹配不到 才会匹配到这
app.use((err,req,res,next) => {
    console.log('错误',err);
    res.status(500).json({
        error: err.message
    })
});//在所有的中间件之后挂载错误处理中间件 必须使用四个参数
//错误处理中间件在最后被挂载
app.listen(3000, () => {
    console.log('Sever running at http://127.0.0.1:3000/')
})