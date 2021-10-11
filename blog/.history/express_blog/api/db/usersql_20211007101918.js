//提供 sql语句
var UserSQL = {  
    find: 'SELECT * FROM admin_user WHERE userName = ? And password = ?',
    insert:'INSERT INTO User(userName,password) VALUES(?,?)', 
    findAriticle: 'SELECT * FROM blog_content'
  };
module.exports = UserSQL;