const express = require('express')
const app = express();
const dbCongif = require('./util/dbconfig')
app.get('/',(req,res,next) => {
    const sql = "SELECT * FROM blog_content";
    const sqlArr = [];
    const callback = (err,data) => {
        if(err) console.log('连接错误');
        else{
            res.send({
                'list':data
            })
        }
    }
    dbCongif.sqlConnect(sql,sqlArr,callback);
});

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})