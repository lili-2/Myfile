const express = require('express')

const router = express.Router()

const login = require('../midderware/article')

router.post('/',login.checkLogin)

module.exports = router;