const event = require('events');
//创建eventEmitter对象
const eventEmitter = new events.eventEmitter();
const connectHandler = function connected(){
    console.log('连接成功');
    event
}