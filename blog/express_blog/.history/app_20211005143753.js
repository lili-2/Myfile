const express = require('express')
const app = express();
const dbCongif = require('./util')
// app.get('/',(req,res) => {
//     res.send('hello express')
// })
// const express = require('express');
// const mysql = require('mysql');
app.get('/',(req,res,next) => {
    const sql = "SELECT * FROM blog_content";
    const sqlArr = [];
    const callback = (err,conn) => {
        if(err) console.log('连接错误');
        else{
            res.send({
                'list':data
            })
        }
    }
});
//连接数据库
// const connection = mysql.createConnection({
//     host: 'localhost',
//     user:'root',
//     // password: 'root',
//     password: '123456',
//     database: 'react_blog'
// });
// connection.connect();
// connection.query('SELECT * FROM blog_content',[],function(err,result){
//     if(err) console.log(err,'数据库连接错误');
//     else console.log('数据库连接成功',result);
// });


app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})