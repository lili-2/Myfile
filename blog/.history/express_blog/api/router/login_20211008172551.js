const express = require('express')
const cookieSession = require('cookie-session')

const router = express.Router()

router.use(cookieSession({
    name:'m'
}))

const login = require('../midderware/login')

router.post('/',login.checkLogin)

module.exports = router;