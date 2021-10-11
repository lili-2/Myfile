const express = require('express');

const router = require.router()

router.get('/', (req, res) => {
    res.send('Hello World!')
})

app.post('/',(req,res) => {
    console.log(req.body);
    res.send('Hello world');
})


module.exports = router;