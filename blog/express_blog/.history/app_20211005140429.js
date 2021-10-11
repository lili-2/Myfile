const express = require('express')

const app = express();

// app.get('/',(req,res) => {
//     res.send('hello express')
// })
// const express = require('express');
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    // password: 'root',
    password: '123456'
    database: 'test'
});
connection.connect();
connection.query('show variables like "port";',[],function(err,result){
    if(err) console.log(err,'数据库连接错误');
    else console.log('数据库连接成功',result);
});


app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})