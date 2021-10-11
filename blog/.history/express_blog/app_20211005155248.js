const express = require('express')
const app = express();
const bd = require('./api/controller/bdcontroller')
app.get('/',(req,res) => {
    res.setHeader('Access-Control-Allow-Origin','*');
    res.bd.getDb()
    res.end()
});

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})