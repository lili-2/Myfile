const express = require('express');

const router = express.router()

router.get('/', (req, res) => {
    res.send('Hello World!')
})

router.post('/',(req,res) => {
    console.log(req.body);
    res.send('Hello world');
})


module.exports = router;