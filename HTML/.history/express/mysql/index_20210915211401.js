const express = require('express')
const router = express.Router();
const mysql = require('mysql');
//连接数据库
const connection = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: 'abc123',
    database: 'user'
});
connection.connect();
// connection.query()
connection.query(sql,[],function(err,result){
    if(err) console.log(err);
    console.log(result)
});


app.get('/', (req, res) => res.send('Hello World!'))
app.listen(port, () => console.log(`Example app listening on port port!`))