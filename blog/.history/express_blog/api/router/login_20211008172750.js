const express = require('express')
const cookieSession = require('cookie-session')

const router = express.Router()

router.use(cookieSession({
    name:'mycookie',//后端给前端种的cookie 
    keys: ['aaa'],//加密层级
    maxAge: 1000*30//cookie 的失效时间 毫秒为单位
}))

const login = require('../midderware/login')

router.post('/',login.checkLogin)

module.exports = router;