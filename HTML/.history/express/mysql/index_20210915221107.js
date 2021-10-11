const express = require('express');
const { data } = require('jquery');
const router = express.Router();
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: '123abc',
    database: 'testdata'
});
connection.connect();
// connection.query()
connection.query('show tables',[],function(err,result){
    if(err) console.log(err,'数据库连接错误');
    console.log('数据库连接成功',data);
});

// app.listen(port, () => console.log(`Example app listening on port port!`))