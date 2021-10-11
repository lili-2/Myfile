const express = require('express')
const app = express()
const router = express.Router()
const bd = require('./api/controller/bdcontroller')
app.use((req,res,next) => {
    res.header('Access-Control-Allow-Origin', '*');
    next();
})
app.get('/',bd.getDb);

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})