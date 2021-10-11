var sd = require('silly-datetime');
console.log(new Date());

var date = sd.format(new Date(), 'YYYY-MM-DD HH:mm');
console.log(date);
 
// sd.fromNow(+new Date() - 2000);