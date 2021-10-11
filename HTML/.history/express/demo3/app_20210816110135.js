const express = require('express')
const morgan = require('morgan')

const app = express()

app.use(morgan('dev'))
app.use(express.json()); //解析请求体 日志输出 Morgan 为客户端提供跨域资源请求 cors
app.use()

const port = process.env.PORT || 3000 //process.env.port 通过环境变量读取端口号

app.get('/', (req, res) => {
    res.send('Hello World!')
})
app.listen(port, () =>{
    console.log(`Example app listening on port port! ${port}`)
})