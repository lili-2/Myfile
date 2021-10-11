const express = require('express');

const app = express()

app.get('/', (req, res) => {
    console.log(req.method,req)
    res.send('get /');
})
app.get('/about', (req, res) => {
    res.send('get /about');
})
app.post('/login', (req, res) => {
    res.send('get /login');
})
app.listen(3000, () => {
    console.log(`Sever running at 3000`)
})