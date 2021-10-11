var tools = (function (){
    function tplReplace(tpl,replaceObj){
        return tpl.replace(/\{\{(.*?)\}\}/g,function(node,key){
            return replaceObj[key.trim()];       
        }) 
    } 
    //返回一个对象
    return {
        tplReplace : tplReplace
    }
})();