const express = require('express');

const app = express()

const myLogger = (req) => { 
    console.log(req.method,req.url,Date.now());
}
app.get('/', (req, res) => {
    myLogger(req)
    res.send('get /');
})
app.get('/about', (req, res) => {
    myLogger(req)
    res.send('get /about');
})
app.post('/login', (req, res) => {
    cmyLogger(req)
    res.send('get /login');
})
app.listen(3000, () => {
    console.log(`Sever running at 3000`)
})