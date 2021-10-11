const express = require('express')

const router = express.Router()

const article = require('../midderware/article')

router.post('/',article.getAllArticle )

module.exports = router;