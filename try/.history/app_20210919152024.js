const express = require('express');
const app = express();
const home = require('./router/home');
const admin = require("./router/admin");

app.use('/home',home);
app.use('/damin',admin);
app.get('/', (req, res) => res.send('Hello World!'))
app.listen(80, () => console.log(`80`))