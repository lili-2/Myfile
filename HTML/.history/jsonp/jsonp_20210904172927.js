window.onload = function(){
     //http://www.baidu.com?aa=11&callback=my_jsonp04349289664328899
 var jsonp = function(url,param,callback){
    //处理url地址,查找？，如果没有？这个变量就有一个"?"，有？这个变量接收一个&
    var querystring = url.indexOf("?") == -1?"?":"&";

    //处理参数{xx:xx}
    for(var k in param) {
        querystring += k + "=" + param[k] + '&';//?k=para[k]
    }

    //处理回调函数名
    var random = Math.random().toString().replace(".","");
    var cbval = "my_jsonp" + random;
    var cb = "callback="+cbval;

    querystring += cb;

    var script = document.createElement("script");
    script.src = url + querystring;

    //把回调函数的名字附给window
    window[cbval] = function(param) {
        //这里执行回调的操作，用回调来处理参数
      callback(param);
      //拿到了就删掉这个script
      document.body.removeChild(script);
    };
    document.body.appendChild(script);
}

jsonp(
    "https://www.baidu.com",
    {aa:11},
    function(){
        console.log(param);
    }
    );
}