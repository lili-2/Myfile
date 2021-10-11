//中间件分类
// 应用程序级别的中间件
// 路由级别的中间件
// 错误处理中间件
// 内置中间件
// 第三方中间件
const express = require('express');

const app = express()

app.get('/', (req, res) => {res.send('Hello World!'))
app.listen(port, () => console.log(`Example app listening on port port!`))