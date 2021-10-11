const express = require('express')

const router = express.Router()

const article = require('../midderware/article')

router.get('/',article.getAllArticle )

module.exports = router;