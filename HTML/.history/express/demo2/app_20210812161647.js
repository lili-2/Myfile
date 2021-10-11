const express = require('express');

const app = express()

// const myLogger = (req) => { 
//     console.log(req.method,req.url,Date.now());
// }

// app.use(express.json());
// app.use(express.urlencoded());

app.get('/', (req, res) => {
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