const express = require('express')
const app = express()

const router = require('./api/router/login')

// const bd = require('./api/controller/bdcontroller')

app.options("/",(req,res,next) => {
    res.setHeader("Access-Control-Allow-Origin","*")
    res.setHeader("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
    res.setHeader("Access-Control-Expose-Headers", "*");
    res.setHeader("Access-Control-Allow-Headers", "*");
        next();
})
// app.get('/',bd.getDb);
app.use('/',router)

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})