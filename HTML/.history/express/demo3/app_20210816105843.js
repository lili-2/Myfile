const express = require('express')

const app = express()

app.use(express.json())

const port = process.env.PORT || 3000 //process.env.port 通过环境变量读取端口号

app.get('/', (req, res) => {
    res.send('Hello World!')
})
app.listen(port, () =>{
    console.log(`Example app listening on port port! ${port}`)
})