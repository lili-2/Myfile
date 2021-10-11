//提供 sql语句
var UserSQL = {  
    find: 'SELECT * FROM admin_user WHERE userName = ? And password = ?',
    insert:'INSERT INTO User(uid,userName) VALUES(?,?)', 
    queryAll:'SELECT * FROM User',  
    getUserById:'SELECT * FROM User WHERE uid = ? ',
    findAriticle: ''
  };
module.exports = UserSQL;