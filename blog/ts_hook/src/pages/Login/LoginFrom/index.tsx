import { FC, ReactElement } from "react"
import axios from 'axios'
import { useHistory } from 'react-router';
import { Form, Input, Button, message } from 'antd';
import { UserOutlined, UnlockFilled } from '@ant-design/icons'
import { userInfor } from '../../../interface'

interface Froms {
    switchFrom: (value: string) => void
}
const LoginFrom: FC<Froms> = ({
    switchFrom
}): ReactElement => {

    const history = useHistory()

    const onFinish = (values: userInfor) => {
        const { username, password } = values
        axios.post('http://localhost:3000/checkLogin',
            { username, password },
        ).then(res => {
            if (res.data.data === "登陆成功") {
                localStorage.setItem("token", res.data.token)
                localStorage.setItem("user", username)
                history.push('/mylist')
            } else {
                message.error('用户名密码错误')
            }
        })
    };

    const onFinishFailed = (err: any) => {
        console.log('Failed:', err);
    };

    const toggleForm = () => {
        switchFrom('register');
    }

    return (
        <>
            <div className="from-header">
                <span>登录</span>
                <span onClick={toggleForm}>账号注册</span>
            </div>
            <div className="from-content">
                <Form className="login-div" name="basic"
                    onFinish={onFinish}
                    onFinishFailed={onFinishFailed}
                    autoComplete="off">

                    <Form.Item name="username"
                        rules={[{ required: true, message: 'Please input your username!', },]}>
                        <Input prefix={<UserOutlined />} placeholder="Username" />
                    </Form.Item>

                    <Form.Item name="password"
                        rules={[{ required: true, message: 'Please input your password!', },]}>
                        <Input.Password prefix={<UnlockFilled />} placeholder="password" />
                    </Form.Item>

                    <Form.Item>
                        <Button type="primary" htmlType="submit" block >
                            Submit
                        </Button>
                    </Form.Item>
                </Form>
            </div>
        </>
    )
}
export default LoginFrom