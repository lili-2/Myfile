const express = require('express');

const app = express()

app.get('/', (req, res) => {
    res.send('get /');
})
app.get('/about', (req, res) => {
    res.send('get /about');
})
app.get('/login', (req, res) => {
    res.send('get /');
})
app.get('/', (req, res) => {
    res.send('get /');
})
app.listen(port, () => console.log(`Example app listening on port port!`))