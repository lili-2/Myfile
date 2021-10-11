const express = require('express')

const router = express.Router()

const login = require('../midderware')

router.get('/admin/index',login.)
// moudle.expoets = app => {
//     router.get('/admin/index',login.login)
// }