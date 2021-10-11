import axios from 'axios'
 const getArticle = () => {
    const data;
    axios.get('http://localhost:3000').then(
        response => {
            console.log('成功了',response.data)
        },
        error => {console.log('失败了')}
    )
}
export default getArticle