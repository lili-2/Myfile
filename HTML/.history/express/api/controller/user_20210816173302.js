//
exports.login = async(req,res,next) => {
    try {
        //处理请求
        res.send('post /users/login');
    } catch (err) {
        next(err);
    }
}
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