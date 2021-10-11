const express = require('express');

const app = express();

//dan
app.get('/',(req,res)=>{
    res.send('Hello World');
})