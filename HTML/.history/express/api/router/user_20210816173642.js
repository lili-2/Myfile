//用户
//  https://github.com/gothinkster/realworld/tree/master/api
// POST /api/users/login

const express = require('express');
const userCtrl = require('../controller/user')

const router = express.Router()
//用户登录
router.post('/users/login',userCtrl.login)
//用户注册
router.post('/users',userCtrl.login)
//获取当前登录用户
router.get('/user',userCtrl.getCurrentUser)
//更新当前登录用户
router.put('/user',userCtrl.)
module.exports = router;