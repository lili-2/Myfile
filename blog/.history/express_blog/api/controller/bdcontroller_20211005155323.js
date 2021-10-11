const dbCongif = require('../util/dbconfig')
//获取
getDb = (req,res) => {
    const sql = "SELECT * FROM blog_content";
    const sqlArr = [];
    const callback = (err,data) => {
        if(err) console.log('连接错误');
        else{
            res.send()
            res.json({
                'list':data
            })
        }
    }
    dbCongif.sqlConnect(sql,sqlArr,callback);
}
module.exports = {
    getDb
}