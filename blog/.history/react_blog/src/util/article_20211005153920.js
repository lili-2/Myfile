import axios from 'axios'
 const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(res => 
        cp
        console.log(res.data)
    )
}
export default getArticle