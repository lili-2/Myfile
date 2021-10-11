const express = require('express')
const morgan = require('morgan')
const cors = require('cors'); 
const router = require('./router')

const app = express()

app.use(morgan('dev'))

app.use(express.json()); //解析请求体 日志输出 Morgan 为客户端提供跨域资源请求 cors

app.use(cors())

const port = process.env.PORT || 3000 //process.env.port 通过环境变量读取端口号

//挂在路由
app.use('/api',router);

//挂载统一处理服务端错误
app.use((req,re))
app.listen(port, () =>{
    console.log(`Example app listening on port port! ${port}`)
})