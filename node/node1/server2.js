const http = require('http');
const fs = require('fs');

let server = http.createServer(function(request,response){
    let {url} = request;
    fs.readFile('www'+url,(err,data) => {
        if(err){
            response.write('404');
        }else{
            response.write(data);
        }
        response.end();
    });
});
server.listen(8020);
