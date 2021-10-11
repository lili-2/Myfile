import { React, useState } from 'react'
import { Card, Input, Button ,Spin ,message} from 'antd'
import axios from "axios"
import '../static/css/Login.css'
import 'antd/dist/antd.css'

function Login(props) {

    const [userName , setUserName] = useState('')
    const [password , setPassword] = useState('')
    const [isLoading, setIsLoading] = useState(false)

    const checkLogin = ()=>{
        setIsLoading(true)
        if(!userName){
            message.error('用户名不能为空')
            setTimeout(() => setIsLoading(false),500)
            return false;
        }else if(!password){
            message.error('密码不能为空')
            setTimeout(() => setIsLoading(false),500)
            return false;
        }
        let dataProps = {
            'userName' : userName,
            'password' : password
        }
        axios({
            method:'post',
            url:"http://localhost:3000/checkLogin",
            data:dataProps
        }).then(
            res => {
                setIsLoading(false)
                if(res.data.data == "登陆成功"){
                    // localStorage.setItem("")
                    props.history.push('/index')
                }else{
                    message.error('用户名密码错误')
                }
            }
        )
    }

    return (
        <div className="login-div">
            <Spin tip="Loading..." spinning={isLoading}>
                <Card title="" bordered={true} style={{ width: 400 }} >
                    <Input id="userName" size="large" placeholder="请输入用户名" onChange={(e)=>{setUserName(e.target.value)}}/> 
                    <br/><br/>
                    <Input.Password id="password" size="large" placeholder="请输入密码" onChange={(e)=>{setPassword(e.target.value)}}/>     
                    <br/><br/>
                    <Button type="primary" size="large" block onClick={checkLogin} > 登录 </Button>
                </Card>
            </Spin>
        </div>
    );
};
export default Login;
