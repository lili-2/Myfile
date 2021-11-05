//提供 sql语句
var UserSQL = {  
    find: 'SELECT * FROM admin_user WHERE userName = ? And password = ?',
    insert:'INSERT INTO User(userName,password) VALUES(?,?)', 
    findAllAriticle: 'SELECT * FROM blog_content order by id desc',
    findOneAriticle: 'SELECT * FROM blog_content WHERE id = ?',
    insertArticle: ' insert into blog_content(title,content,time,likes) values (?,?,"2021-10-12 11:30",0)',
    deleteArticle: 'delete from blog_content where id = ?;',
    // searchArticle: 'select * from blog_content where title = ?'
    searchArticle: 'select * from blog_content where content like ? or content like ?;'
  };
module.exports = UserSQL;