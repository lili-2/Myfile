let a = 1;
let b = 2;
let c = 3;
let s1 = {username:"xuesheg"}
// console.log(s1)
//系统默认 设置exports = module.exports;
//使用exports的时候 只能单个设置属性 exports.a = a;
//使用module.exports 可以单个设计属性，也可以整个赋
exports.a = a;
module.exports.c = c;
exports = module.exports;
// module.exports = {user: 'xiaomin'}