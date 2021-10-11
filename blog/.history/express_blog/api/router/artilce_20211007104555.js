const express = require('express')

const router = express.Router()

// const article = require('../midderware/article')

// router.get('/',article.getAllArticle )
router.get('/',(req,res,next) => {
    (req,res,next) => {
        console.log("执行");
        res.json({'list':"你好"});
})

module.exports = router;