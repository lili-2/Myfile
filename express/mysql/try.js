const http=require('http'); 

var server = http.createServer(function(){
    console.log('有人来啦!!!');
});

//监听---等着
//端口---数字
server.listen(8080);


