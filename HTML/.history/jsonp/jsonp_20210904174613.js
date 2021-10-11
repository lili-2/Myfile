<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>百度跨域获取数据</title>
    <style>
        * {
            margin: 0;
            padding: 0;
        }
        ul {
            list-style: none;
        }
        #logo {
            margin: 30px auto;
            display: block;
            width:280px;
        }
        form[name="search-form"] {
            display: block;
            margin: 10px auto 0;
            width: 600px;
            font-size: 0;
        }
        input[name="search-content"] {
            width: 500px;
            height: 40px;
            padding: 0 10px;
            border: 1px solid #ccc;
            outline: none;
            box-sizing: border-box;
            vertical-align: bottom;
        }
        input[name="search-content"]:focus {
            border-color: #3385ff;
        }
         input[type="submit"] {
            width: 100px;
            height: 40px;
            border: none;
            outline: none;
            color: #fff;
            background: #3385ff;
        }
        #search-list {
            margin: 0 auto;
            width: 600px;
        }
        #search-list li {
            padding: 0 10px;
            line-height: 30px;
            background: #eee;
            border-bottom: 1px dashed #ccc;
        }
    </style>
</head>
<body>
    <img src="logo.png" id="logo">
    <form action="javascript:;" name="search-form">
        <input type="text" name="search-content">
        <input type="submit" value="百度一下">
    </form>
    <ul id="search-list">
		
	</ul>
    <script>
        var oSearchList = document.getElementById('search-list');
        var oSearchForm = document.forms['search-form'];
        var oSearchContent = oSearchForm.elements['search-content'];
 
        oSearchContent.oninput = function () {
            var sVal = this.value;
            oSearchList.innerHTML = '';
            if(sVal !== '') {
                var oScript = document.createElement('script');
                oScript.src = 'https://sp0.baidu.com/5a1Fazu8AA54nxGko9WTAnF6hhy/su?wd=' + sVal + '&json=1&p=3&sid=1438_24869_21080_18560_17001_25177_22160&req=2&bs=1%2B&pbs=1%2B&csor=2&pwd=1%3D&cb=callback&_=1511334117083';
                document.body.appendChild(oScript);
            }
        };
		
        // 声明回调函数
        function callback(data) {
			console.log(data);
            data.s.forEach((v) => {
                var oLi = document.createElement('li');
                oLi.innerHTML = v;
                oSearchList.appendChild(oLi);
            });
        }
    </script>
</body>
</html>