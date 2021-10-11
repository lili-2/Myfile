(function (global) {
    global.jsonp = function (url, params, callback) {
      let queryParamArr = []
      for (let key in params) {
        if (params.hasOwnProperty(key))
          queryParamArr.push(`${key}=${params[key]}`)
      }
      let callbackFunctionName = 'jsonp_' + Math.random().toString().replace('.', '')
      queryParamArr.push(callbackFunctionName)
  
      let script = document.createElement('script')
      script.src = queryParamArr.join('&')
      document.body.appendChild(script)
  
      global[callbackFunctionName] = function (param) {
        callback(param)
        document.body.removeChild(script)
      }
    }
    jsonp(`https://wis.qq.com/city/like`,{source :source,city=西安)
  })(window)
  