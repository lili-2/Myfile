const express = require('express')

const admin = express.Router();

admin.get('/admin',(req,res) => {
    res.send("welcome blog admin");
});

module.exports = admin;