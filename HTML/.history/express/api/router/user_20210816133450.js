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

router.post('/users/login')

module.exports = router;