const express = require('express')

const router = express.Router()

const article = require('../midderware/article')

router.post('/mylist',article.)

module.exports = router;