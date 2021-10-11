//拼接路径
const path = require('path');
//webpack 中所有的配置信息都应该写在module.exports中
module.exports = {
    //指定入口文件
    entry:"./ts/class.ts",
    //mode模式 
    output: {
        //拼出路径
        path: path.resolve(__dirname,'dist'),
        filename: 'bundle.js',
    },
    //指定打包文件所在目录
    // output: {
    //     path: path.resolve(__)
    // }
    mode : 'development',

    //指定webpack打包时要使用的模块
    module :{
        rules: [
            {
                //test指定的是规则生效的文件
                test: /\.ts$/,
                //要使用的loader
                use: 'ts-loader',
                //要排除的文件
                exclude: /node_modules/
            }
        ]
    }
}

// ocaml reason elm haskell coq agda c++ go rust 
// mongo sql 
// react fp life cycle


//  koa => mysql => 个人博客系统  
