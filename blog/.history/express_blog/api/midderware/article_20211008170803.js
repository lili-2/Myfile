const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')

const pool = mysql.createPool(dbConfig.mysql)
//获取
exports.getAllArticle = (req,res,next) => {
    pool.getConnection((err, connection) => {
        if(err) console.log(err)  
        connection.query(userSQL.findAllAriticle, [], function(err, data) {
            if(err){
                console.log(err)
            }
            res.json({'list':data});
            connection.release();  
        });
    });
}
