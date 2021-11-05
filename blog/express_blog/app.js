const express = require('express')
const bodyParser = require('body-parser')
const app = express()
const jwt = require('jsonwebtoken')
const user = require('./api/router/login')
const articles = require('./api/router/artilce')
const detailed = require('./api/router/detailed')
const auth = require('./api/util/auth')

app.all('*', function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "*");
  res.header("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
  res.header("Content-Type", "application/json;charset=utf-8");
  if (req.method == "OPTIONS") {
    res.sendStatus(200);
  }
  else {
    next();
  }
});

app.use(bodyParser.json())

app.use('/checkLogin',user);

app.use('/mylist',auth,articles);

app.use('/detailed',detailed);

app.listen(3000,() => {
    console.log('Sever running at http://127.0.0.1:3000/')
})


// `https://github.com/lovebaihezi/_ysdn/tree/main/vite-ysdn/src`


