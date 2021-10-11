import axios from 'axios'
 const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(
        console.log(data)
    )
}
expor default getArticle