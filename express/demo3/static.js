const express = require('express');
const expressStatic = require('express-static')
const server = express();

server.listen(8080);
server.use(expressStatic('./www'));