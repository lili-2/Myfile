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
            url:"localhost.checkLogin",
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
                <Card title="JSPang Blog  System" bordered={true} style={{ width: 400 }} >
                    <Input
                        id="userName"
                        size="large"
                        placeholder="Enter your userName"
                        // prefix={<Icon type="user" style={{color:'rgba(0,0,0,.25)'}} />}
                        onChange={(e)=>{setUserName(e.target.value)}}
                    /> 
                    <br/><br/>
                    <Input.Password
                        id="password"
                        size="large"
                        placeholder="Enter your password"
                        // prefix={<Icon type="key" style={{color:'rgba(0,0,0,.25)'}} />}
                        onChange={(e)=>{setPassword(e.target.value)}}
                    />     
                    <br/><br/>
                    <Button type="primary" size="large" block onClick={checkLogin} > Login in </Button>
                </Card>
            </Spin>
        </div>
    );
};
export default Login;
// ReactDOM.render(<Demo />, mountNode);
