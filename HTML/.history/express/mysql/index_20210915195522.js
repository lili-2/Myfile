const express = require('express')
const router = express.Router();
const mysql = require('mysql');
//连接数据库
const bd = mysql.createConnection({
    host:
})
app.get('/', (req, res) => res.send('Hello World!'))
app.listen(port, () => console.log(`Example app listening on port port!`))