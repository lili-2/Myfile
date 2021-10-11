// const express = require('express');
// const mysql = require('mysql');
// //连接数据库
// const connection = mysql.createConnection({
//     host: 'localhost',
//     user:'root',
//     password: 'root',
//     database: 'test'
// });
// connection.connect();
// // connection.query()
// connection.query('show tables',[],function(err,result){
//     if(err) console.log(err,'数据库连接错误');
//     else console.log('数据库连接成功',result);
// });
// // app.listen(port, () => console.log(`Example app listening on port port!`))
const express = require('express');
const app = express();
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: '123456',
    database: 'new_schema'
});
connection.connect();
// connection.query()
connection.query('show tables',[],function(err,result){
    if(err) console.log(err,'数据库连接错误');
    else console.log('数据库连接成功',result);
});
app.listen(port, () => console.log(`Example app listening on port port!`))