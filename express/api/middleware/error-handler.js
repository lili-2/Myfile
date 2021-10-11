//错误未打印 原因 他的错误信息是在原型上的 但json只能识别本身上的
// 解决 util自带的模块上的format 作用把error转换成一个字符串 会把原型上的检测出来进行转化
const util = require('util');
module.exports = () => {
    return (err,req,res,next) => {
        res.status(500).json({
            // error: err
            error: util.format(err)
        })
    }
}