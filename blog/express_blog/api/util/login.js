const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')
const pool = mysql.createPool(dbConfig.mysql);

const jwt = require('jsonwebtoken')

exports.checkLogin = async(req,res,next) => {
    const {username,password} = req.body;
    pool.getConnection((err, connection) => {  
        connection.query(userSQL.find, [username,password], function(err, result) {
            if(err){
                console.log(err)
            }
            if(result.length == 0){
                res.json({data:"账号或密码错误"})
            }else{
                let token = jwt.sign({
                                userName:result[0].userName
                            },"aaa",{
                                expiresIn: 60
                            })
                res.json({data:"登陆成功",token:{err:0,msg:'验证成功'},token});
            }
            connection.release();  
        });
    });
}
