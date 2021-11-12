// CommonJS 语法
const path = require('path')

module.exports = {
    mode: 'development',
    //__dirname 当前文件所在目录 join帮我们拼接路径
    entry: path.join(__dirname,'src','index.js'),
    output: {
        path: path.join(__dirname,'dist'),
        filename: 'bundle.js'
    }
}