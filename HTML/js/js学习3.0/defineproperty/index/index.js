import {observer} from './observes'
;(function(doc){
    var oUsername = doc.querySelector('#username');
    var oAge = doc.querySelector('#age');
    var oEmail = doc.querySelector('#Email');
    var oTel = doc.querySelector('#Tel');
    var oSubmitBtn = doc.querySelector('#submitBtn');
    var oInfoTable = doc.querySelector('#infoTable');

    var userInfo = observer({
        username: '',
        age: '',
        email: '',
        tel: ''
    },oInfoTable);

    console.log(userInfo);
    console.log('hello')
    var init = function(){
        bindEvent();
    }

    function bindEvent(){
        oSubmitBtn.addEventListener('click',handleSunmitBtnClick,false);
    }

    function handleSunmitBtnClick(){
        var _username = oUsername.value.trim();
        var _age = oAge.value.trim();
        var _email = oEmail.value.trim();
        var _tel = oTel.value.trim();

        _username && (_username !== userInfo.username) && (userInfo.username = _username);
        oUsername.value = '';
    }
    init();
})(document);