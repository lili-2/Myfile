const express = require('express')

const router = express.Router()

const login = require('../midderware/article')

router.post('/checkLogin',login.checkLogin)

module.exports = router;