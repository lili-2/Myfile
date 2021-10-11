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
   // const sql = "SELECT * FROM blog_content";
    // const sqlArr = [];
    // const callback = (err,data) => {
    //     if(err) console.log('连接错误');
    //     else{

    //         res.json({
    //             'list':data
    //         })
    //     }
    // }
    // dbCongif.sqlConnect(sql,sqlArr,callback);