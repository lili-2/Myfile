const express = require('express')

const admin = express.Router();

admin.get('/',(req,res) => {
    res.send("welcome blog home");
});

module.exports = home;