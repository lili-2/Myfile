const express = require('express')
const cookieSession = require('cookie-session')

const router = express.Router()

router.

const login = require('../midderware/login')

router.post('/',login.checkLogin)

module.exports = router;