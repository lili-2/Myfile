const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')

const pool = mysql.createPool(dbConfig.mysql);

exports.login = async (req,res,next) => {
    try{
        res.send('post')
    }catch{
        res.send(err)
    }
}
// exports.checkLogin = async(req,res,next) => {
//     const {userName,password} = req.body
//     const sql = `SELECT userName FROM admin_user WHERE userName = ${userName} And password = ${password}`
//     const res = await 
// }
exports.checkLogin = async(req,res,next) => {
    // 从连接池获取连接 
    console.log(req.body)
    const {userName,password} = req.body
    pool.getConnection(function(err, connection) { 
  
        const param = req.query || req.params;   
        // 建立连接 增加一个用户信息 
        connection.query(userSQL.find, [param.userName,param.password], function(err, result) {
                // if(result) {      
                //     result = {code: 200,msg:'增加成功'};  
                // }     
                if(err){
                    console.log(err)
                }
            // 以json形式，把操作结果返回给前台页面     
                res.send({data:"登陆成功"});   
            // 释放连接  
                connection.release();  
        });
    });
}
