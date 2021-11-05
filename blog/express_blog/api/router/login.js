const express = require('express')

const router = express.Router()

const login = require('../util/login')

router.post('/',login.checkLogin)

module.exports = router;