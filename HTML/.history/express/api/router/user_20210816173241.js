//用户
//  https://github.com/gothinkster/realworld/tree/master/api
// POST /api/users/login

const express = require('express');
const userCtrl = require('../controller/user')

const router = express.Router()
//用户登录
router.post('/users/login',userCtrl.login)
//用户注册
router.post('/users',)
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
module.exports = router;