import axios from 'axios'
 const getArticle = () => {
    axios.get('http://localhost:3000').then(
        response => {
            data = response.data;
            console.log('成功了',response.data)
        },
        error => {console.log('失败了')}
    )
    return data;
}
export default getArticle