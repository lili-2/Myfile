module.exports = async (req, res, next) => {
    const token = req.headers.authorization
    console.log(req.url)
    if (req.url !== '/mylist' && token !== undefined) {
        jwt.verify(token, "aaa",
            (err, data) => {
                console.log('jwt ' + data);
                console.log('err'+err);
            })
        next();
    }else{
        console.log("nihao")
        return res.redirect('/mylist/write')
        // res.send('res');       
    }
}