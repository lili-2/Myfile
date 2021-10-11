//错误未打印 原因 
module.exports = () => {
    return (err,req,res,next) => {
        res.status(500).json({
            error: err
        })
    }
}