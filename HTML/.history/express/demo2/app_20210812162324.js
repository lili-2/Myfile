const express = require('express');

const app = express()

// const myLogger = (req) => { 
//     console.log(req.method,req.url,Date.now());
// }

// app.use(express.json());
// app.use(express.urlencoded());

//所有请求都要进入他 要放行 否则会一直卡在这
//三个参数 req 请求对象 res 响应对象 
app.use(() => {
    console.log('hello');
})

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