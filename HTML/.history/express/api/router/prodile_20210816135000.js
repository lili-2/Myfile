const express = require('express');

const router = express.Router()
//获取指定用户资料
router.get('/profiles/:username',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /profiles/:username');
    } catch (err) {
        next(err);
    }
})
//关注用户
router.get('/profiles/:username',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /profiles/:username');
    } catch (err) {
        next(err);
    }
})
//取消用户
router.get('/profiles/:username',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /profiles/:username');
    } catch (err) {
        next(err);
    }
})