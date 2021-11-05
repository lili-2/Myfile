module.exports = async (req, res, next) => {
    const token = req.headers.authorization
    if (token !== undefined) {
        // jwt.verify(token, "aaa",
        //     (err, data) => {
        //         console.log('jwt ' + data);
        //         console.log('err'+err);
        //     })
        next();
    }else{
        // return res.redirect('https://www.thinbug.com/q/35122941')
        res.send('res')        
    }
}