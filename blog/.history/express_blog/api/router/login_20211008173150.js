const express = require('express')
const jwt

const router = express.Router()

const login = require('../midderware/login')

router.post('/',login.checkLogin)

module.exports = router;