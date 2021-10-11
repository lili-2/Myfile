const express = require('express')
const app = express()

const router = require('./api/router/login')


// const bd = require('./api/controller/bdcontroller')

app.use((req,res,next) => {
    res.header('Access-Control-Allow-Origin', '*');
    res.header("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
    next();
})
// app.get('/',bd.getDb);
app.use('/',router)

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})