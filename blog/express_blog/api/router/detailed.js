const express = require("express")

const router = express.Router()

const article = require('../util/article')

router.get('/',article.getOneArticle)

module.exports = router;