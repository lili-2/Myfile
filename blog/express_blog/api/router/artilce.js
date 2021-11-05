const express = require('express')

const router = express.Router()

const article = require('../util/article')

router.post('/write',article.insertArticle);

router.get('/article',article.deleteArticle);

router.get('/search',article.searchArticle);

router.get('/',article.getAllArticle);

module.exports = router;