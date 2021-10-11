//错误未打印 原因 他的错误信息是在原型上的 但json只能识别本身上的 解决
const util = require('util');
module.exports = () => {
    return (err,req,res,next) => {
        res.status(500).json({
            // error: err
            err
        })
    }
}