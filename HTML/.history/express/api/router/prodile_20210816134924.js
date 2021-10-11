const express = require('express');

const router = express.Router()
//用户登录
router.get('/profiles/:username',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /profiles/:username');
    } catch (err) {
        next(err);
    }
})