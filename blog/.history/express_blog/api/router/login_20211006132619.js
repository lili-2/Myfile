const express = require('express')

const router = express.Router()

const login = require('../midderware/login')

router.get('/admin',login.login)

module.exports = router;