const express = require('express')

const home = express.Router();

home.get('/',(req,res) => {
    res.send("welcome blog home");
});

module.exports = home;