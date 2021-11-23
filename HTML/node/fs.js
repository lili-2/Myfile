"use strict";
exports.__esModule = true;
var fs = require("fs");
var tree = {};
var fsPath = '../../HTML/practive';
var myfs = function (fsPath, tree) {
    var list = fs.readdirSync(fsPath);
    list.forEach(function (i, index) {
        var statu = fs.statSync(fsPath + "/" + i);
        if (statu.isDirectory()) {
            tree[i] = {};
            tree[i] = myfs(fsPath + "/" + i, tree[i]);
        }
        else {
            tree[index] = i;
        }
    });
    return tree;
};
console.log('hello');
console.log(myfs(fsPath, tree));
console.log(myfs(fsPath, tree).css);
