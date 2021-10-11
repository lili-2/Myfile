const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')
const pool = mysql.createPool(dbConfig.mysql);

exports.checkLogin = async(req,res,next) => {
    // 从连接池获取连接 
    pool.getConnection((err, connection) => {  
        connection.query(userSQL.find, [], function(err, result) {
            if(err){
                console.log(err)
            }
            if(result[0].userName === userName && result[0].password === password){
                res.json({data:"登陆成功"});   
            }
            connection.release();  
        });
    });
}