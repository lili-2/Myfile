//内置中间件
//解析客户端的请求体
// 1. express.json(); 解析Content-Type 为 application/json格式的请求体 会把解析出来的数据挂载到request.body 上
// 2. express.urlencoded();  解析Content-Type 为 application/x-www-form-urlencoded格式的请求体 会把解析出来的数据挂载到request.body 上
// 3. express.raw();解析Content-Type 为 application/octet-stream格式的请求体
// 4. express.text();解析Content-Type 为 text/plain格式的请求体 最后两个很少使用

// 5. express.static();托管静态资源文件

//第三方中间件
//