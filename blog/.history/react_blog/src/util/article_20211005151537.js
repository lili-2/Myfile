import axios from 'axios'
const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://300`,
        withCredentials:true
    })
}