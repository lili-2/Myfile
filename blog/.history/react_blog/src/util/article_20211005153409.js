import axios from 'axios'
expor de const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(
        console.log(data)
    )
}