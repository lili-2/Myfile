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
            console.log(result)
            if()
            // if(result[0].userName === userName && result[0].password === password){
            //     res.json({data:"登陆成功"});   
            // }else{
            //     res.json({data:"账号或密码错误"})
            // }
            connection.release();  
        });
    });
}
