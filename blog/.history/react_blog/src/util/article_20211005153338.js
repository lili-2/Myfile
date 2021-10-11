import axios from 'axios'
export.define([
    'require',
    'dependency'
], function(require, factory) {
    'use strict';
    
}); const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(
        console.log(data)
    )
}