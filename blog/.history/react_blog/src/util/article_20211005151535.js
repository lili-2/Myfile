import axios from 'axios'
const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://30`,
        withCredentials:true
    })
}