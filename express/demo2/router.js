//路由模块
const express = require('express');
const { getDb, saveDb } = require('./db');
const fs = require('fs');
//创建路由实例  路由实例其实就相当于一个 mini Express 实例
const router = express.Router();

// app.get();
// app.post();


router.get('/', async (req, res,next) => {
    try {
        const db = await getDb();
        res.status(200).json(db.todos);
    } catch (err) {
        // res.status(500).json({
        //     error: err.message
        // });
        //如果将任何内容传递给next()函数(字符串'route'除外)express将其视为错误 
        //并且跳过所有剩余的无错误处理路由和中间件函数
        //next() 往后匹配下一个中间件
        //next('route') 往后匹配当前中间件堆栈中的下一个
        //next(任意数据) 将其视为错误 指的是挂载顺序
        next(err);//其余错误都可以这样改 但要注意传参
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
router.get('/:id', (req, res) => {
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
//添加任务 1：获取客户端请求体参数  2：数据验证 3：把数据存储到db中
router.post('/', async(req, res) => {
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
        todo.id = lastTodo ? lastTodo + 1 : 1;
        dp.todos.push(todo);

        await saveDb();
        res.status(200).json(todo);
    } catch (err) {
        res.status(500).json(err.message);
    }
})
//修改
router.patch('/:id', async (req, res) => {
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
router.delete('/:id', async(req, res) => {
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

















// //配置路由
// router.get('/foo',(req,res) => {
//     res.send('get /foo');
// })

// router.post('/foo',(req,res) => {
//     res.send('post /foo');
// })

//3. 导出路由实例
//ES6 相当于 export default router
module.exports = router;

//4.将路由挂载集成到Express实例应用中