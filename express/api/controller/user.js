//用户登录
exports.login = async(req,res,next) => {
    try {
        //处理请求
        res.send('post /users/login');
    } catch (err) {
        next(err);
    }
}
//用户注册
exports.register = async(req,res,next) => {
    try {
        //1.获取请求体数据
        console.log(req.body)
        //2.数据验证  
        //2.1 基本数据验证
        //2.2 业务数据验证

        //3.验证通过。将数据保存到数据库
        
        //4.发送成功响应
        res.send('register')
    } catch (err) {
        next(err);
    }
}
//获取当前登录用户
exports.getCurrentUser = async(req,res,next) => {
    try {
        res.send('getCurrentUser');
    } catch (err) {
        next(err);
    }
}
//更新当前登录用户
exports.updateCurrentUser = async(req,res,next) => {
    try {
        res.send('updateCurrentUser');
    } catch (err) {
        next(err);
    }
}