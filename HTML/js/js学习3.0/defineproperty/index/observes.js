export function observer (userInfo,viewDom){

    var _storageInfo = JSON.parse(localStorage.getItem('userInfo') || '{}');
    var _retInfo = {};

    var init = function(){
        initData(_storageInfo,_retInfo,userInfo);
    }

    var initData = function(storageInfo,retInfo,userInfo){
        for(let k in storageInfo){
            if(!userInfo[k]){
                userInfo[k] = storageInfo[k];
            }
        }
        for(let k in userInfo){
            (function(k){
                Object.defineProperty(retInfo,k,{
                    get(){
                        return userInfo[k];
                    },
                    set (newValue){
                        userInfo[k] = newValue;
                        localStorage.setItem('userInfo',JSON.stringify(userInfo));
                    }
                })
            })(k);
        }
    }

    init();
    return _retInfo; 
}