const express = require('express');

const router = express.Router()

// router.get('/', (req, res) => {
//     res.send('Hello World!')
// })

// router.post('/',(req,res) => {
//     console.log(req.body);
//     res.send('Hello world');
// })
//用户相关路由
router.use(require('./user'))
//用户资料相关
router.use(require('/profiles','./prodile'));

module.exports = router;