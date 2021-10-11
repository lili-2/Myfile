//错误未打印 原因 他的cuo'wu
module.exports = () => {
    return (err,req,res,next) => {
        res.status(500).json({
            error: err
        })
    }
}