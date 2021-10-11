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
    const {userName,password} = req.body

    pool.getConnection((err, connection) => { 
      
        connection.query(userSQL.find, [userName,password], function(err, result) {
                if(err){
                    console.log(err)
                }
                console.log("jie")
                res.json({data:"登陆成功"});   
                connection.release();  
        });
    });
}
