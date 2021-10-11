const expree = require('express')
const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')
const pool = mysql.createPool(dbConfig.mysql);

exports.checkLogin = async(req,res,next) => {
    // 从连接池获取连接 
    const {userName,password} = req.body;
    pool.getConnection((err, connection) => {  
        connection.query(userSQL.find, [userName,password], function(err, result) {
            if(err){
                console.log(err)
            }
            if(result.length == 0){
                res.json({data:"账号或密码错误"})
            }else{
                res.json({data:"登陆成功"});
            }
            connection.release();  
        });
    });
}
