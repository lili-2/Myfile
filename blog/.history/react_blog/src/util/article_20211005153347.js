import axios from 'axios'
export.de const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(
        console.log(data)
    )
}