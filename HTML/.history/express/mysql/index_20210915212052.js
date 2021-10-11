const express = require('express')
const router = express.Router();
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: '123abc',
    database: 'user'
});
connection.connect();
// connection.query()
connection.query('show tables',[],function(err,result){
    if(err) console.log(err,'数据库连接错误');
    console.log(result);
});

// app.listen(port, () => console.log(`Example app listening on port port!`))