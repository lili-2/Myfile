var sd = require('silly-datetime');
sd.format(new Date(), 'YYYY-MM-DD HH:mm');
// 2015-07-06 15:10
 
sd.fromNow(+new Date() - 2000);