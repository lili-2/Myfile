var sd = require('silly-datetime');
console.log(new Date());

var sd.format(new Date(), 'YYYY-MM-DD HH:mm');
console.log()
 
// sd.fromNow(+new Date() - 2000);