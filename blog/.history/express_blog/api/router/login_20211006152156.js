const express = require('express')

const router = express.Router()

const login = require('../midderware/login')

router.get('/login',login.login)
router.get('/checkLogin',(req,res,next))
// router.post('/checkLogin',login.checkLogin)

module.exports = router;