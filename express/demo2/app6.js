const express = require('express')

const app = express();

app.get('/',(req,res,next) => {
    res.redirect("/mylist")
})

app.listen(5000,function(){console.log("nihao")})