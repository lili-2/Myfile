
    (function (global) {
       window.onload = function(global){
        global.jsonp = function (url, params, callback) {

        
            let script = document.createElement('script')
            document.body.appendChild(script)
        
            // global[callbackFunctionName] = function (param) {
            //   callback(param)
            //   document.body.removeChild(script)
            // }
          }
          global.jsonp(`https://wis.qq.com/city/like?source=pc&city=西安`,{},function(data){console.log(data)})
       }
      })(window)
      