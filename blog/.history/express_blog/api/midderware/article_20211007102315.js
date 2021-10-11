const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')
const pool = mysql.createPool(dbConfig.mysql);
//获取
exports.getAllArticle = (req,res) => {
 
    pool.getConnection((err, connection) => {  
        connection.query(userSQL.findAllAriticle, [], function(err, result) {
            if(err){
                console.log(err)
            }
            res.json({'list':data});
            console.log(data)
            connection.release();  
        });
    });
}
