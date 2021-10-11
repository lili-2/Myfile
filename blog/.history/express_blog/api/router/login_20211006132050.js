const express = require('express')

const router = express.Router()
const login = require('../midderware')
moudle.expoets = app => {
    router.get('/admin/index',login.login)
}