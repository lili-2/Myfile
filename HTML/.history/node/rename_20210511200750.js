const fs = require('fs');
const path = require('path');
//文件的重命名
fs.readdir('aaa', (err, list) => {
    if (err) {
        console.log('目录读取失败', err.code);
    } else {
        for (let i = 0; i < list.length; i++) {
            //parse解析
            // console.log(path.parse(list[i]))
            let { name, ext } = path.parse(list[i]);
            if (ext.toLowerCase() == '.txt') {
                fs.rename(
                    'aaa/' + list[i],
                    'aaa/' + name + '.jpg',
                    err => {
                        console.log('重命名失败', err.code);
                    }
                )
            }
        }
    }
})