import axios from 'axios'
 const getArticle = () => {
    axios({
        method: 'get',
        url:`localhost://3000`,
        // withCredentials:true
    }).then(res => 
        {
            console.log("hello")
            console.log(res);
            console.log(res.data)
        }
    )
}
export default getArticle