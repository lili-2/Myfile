import axios from 'axios'
 const getArticle = () => {
    // axios({
    //     method: 'get',
    //     url:`localhost://3000`,
    //     // withCredentials:true
    // }).then(res => 
    //     {
    //         console.log("hello")
    //         console.log(res);
    //         console.log(res.data)
    //     }
    // )
    axios.get('http://localhost:3000').then(
        response => {console.log('成功了',response.data);},
        error => {console.log('失败了')}
        return 
    )
}
export default getArticle