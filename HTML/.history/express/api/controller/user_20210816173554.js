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
        //2.数据验证
        //3.验证通过。将数据保存到数据可以
        //4.发送成功响应
        res.send('post /users');
    } catch (err) {
        next(err);
    }
}
//获取当前登录用户
exports.getCurrentUsers = async(req,res,next) => {
    try {
        res.send('getCurrentUsers');
    } catch (err) {
        next(err);
    }
}
//更新当前登录用户
exports.updataCurrentUsers = async(req,res,next) => {
    try {
        res.send('getCurrentUsers');
    } catch (err) {
        next(err);
    }
}