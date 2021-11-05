import axios from 'axios'

const myAxios = axios.create({
    headers:{'Content-Type': 'application/json'},
    baseURL: "http://localhost:3000"
})

//请求响应器
myAxios.interceptors.request.use(
    config => {
        const token = localStorage.getItem('token')
        if(token) {
            config.headers!.authorization = token;
        }
        return config;
    },
    err => {
        return Promise.reject(err);
    }
)

// 响应拦截器
myAxios.interceptors.response.use(
    response => {
        if(response.data === 'undefined'){

        }
        return response.data
    },
    err => {
        return Promise.reject(err);
    }
)

export default myAxios;