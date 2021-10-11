//用户
//  https://github.com/gothinkster/realworld/tree/master/api
// POST /api/users/login

// Example request body:

// {
//   "user":{
//     "email": "jake@jake.jake",
//     "password": "jakejake"
//   }
// }
const express = require('express');

const router = express.Router()
//用户登录
router.post('/users/login',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /users/login');
    } catch (err) {
        next(err);
    }
})
//用户注册
router.post('/users',async(req,res,next) => {
    try {
        //1.获取请求体数据
        //2.数据验证
        //3.验证通过。将数据保存到数据可以
        //4.发送成功响应
        res.send('post /users');
    } catch (err) {
        next(err);
    }
})
//获取当前登录用户
router.get('/user',async(req,res,next) => {
    try {
        // JSON.parse('dsdasdad');//错误测试
        //处理请求
        res.send('get /user');
    } catch (err) {
        next(err);
    }
})
//更新当前登录用户
router.put('/user',async(req,res,next) => {
    try {
        //处理请求
        res.send('put /user');
    } catch (err) {
        next(err);
    }
})
module.exports = router;De