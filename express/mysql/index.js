const express = require('express');
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: 'root',
    database: 'test'
});
connection.connect();
connection.query('show variables like "port";',[],function(err,result){
    if(err) console.log(err,'数据库连接错误');
    else console.log('数据库连接成功',result);
});
// connection.connect().then(() => {console.log("连接成功")})
//                     .catch(() => {console.log("失败")})
// app.listen(port, () => console.log(`Example app listening on port port!`))