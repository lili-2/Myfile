const express = require('express')
const bodyParser = require('body-parser')
const app = express()
const user = require('./api/router/login')
// const bd = require('./api/controller/bdcontroller')
const articles = require('./api/router/artilce')

app.all('*', function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "*");
  res.header("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
  res.header("Content-Type", "application/json;charset=utf-8");
  next();
});

app.use(bodyParser.json())
app.get('/mylist',articles);
app.use('/',router)

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})