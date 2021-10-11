const mysql = require('mysql');
module.exports = {
    config:{
        host: 'localhost',
        // port:'3306',
        user:'root',
        password: '123456',
        database: 'react_blog'
    },
    //连接池对象
    sqlConnect: function(sql,sqlArr,callBack){
        var pool = mysql.createPool(this.config)
        pool.getConnection((err,conn) => {
            console.log('123456')
            if(err){
                console.log('连接失败')
                return;
            }
        })
        conn.query(sql,sqlArr,callBack);
        conn.release
    }
    //事件驱动回调

}