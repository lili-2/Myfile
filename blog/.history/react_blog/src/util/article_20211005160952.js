import axios from 'axios'
 const getArticle = () => {
    const data;
    axios.get('http://localhost:3000').then(
        response => {
            
        },
        error => {console.log('失败了')}
    )
}
export default getArticle