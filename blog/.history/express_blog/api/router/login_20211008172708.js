const express = require('express')
const cookieSession = require('cookie-session')

const router = express.Router()

router.use(cookieSession({
    name:'mycookie',//后端给前端种的cookie 
    keys: ['aaa'],//加密层级
    maxAge: 1000*30
}))

const login = require('../midderware/login')

router.post('/',login.checkLogin)

module.exports = router;