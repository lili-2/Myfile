const express = require('express')
const app = express()

const router = require('./api/router/login')

// const bd = require('./api/controller/bdcontroller')

app.options("/",(req,res,next) => {
    res.setHeader("Access-Control-Allow-Origin","*")
    res.setHeader("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
    res.setHeader("Access-Control-Expose-Headers", "*");
    res.setHeader("Access-Control-Allow-Headers", "*");
————————————————
版权声明：本文为CSDN博主「weixin_47833269」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_47833269/article/details/115208681
        next();
})
// app.get('/',bd.getDb);
app.use('/',router)

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})