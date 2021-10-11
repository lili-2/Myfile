const express = require('express')

const admin = express.Router();

admin.get('/ad',(req,res) => {
    res.send("welcome blog admin");
});

module.exports = admin;