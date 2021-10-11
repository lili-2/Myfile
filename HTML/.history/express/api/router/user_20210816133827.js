//用户
//  https://github.com/gothinkster/realworld/tree/master/api
// POST /api/users/login

// Example request body:

// {
//   "user":{
//     "email": "jake@jake.jake",
//     "password": "jakejake"
//   }
// }
const express = require('express');

const router = express.Router()

router.post('/users/login',async(req,res,next) => {
    try {
        //处理请求
        res.send('post /user/login');
    } catch (err) {
        next(err);
    }
})

module.exports = router;