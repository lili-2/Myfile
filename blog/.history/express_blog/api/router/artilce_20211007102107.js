const express = require('express')

const router = express.Router()

const login = require('../midderware/article')

router.post('/mylist',login.checkLogin)

module.exports = router;