const express = require('express')

const router = express.Router()

const article = require('../midderware/article')

router.('/',article.getAllArticle )

module.exports = router;