import { FC, ReactElement } from "react"
import { Form, Input, Button} from 'antd';
import { UserOutlined, UnlockFilled } from '@ant-design/icons'
import { userInfor } from '../../../interface'



interface Froms {
    switchFrom: (value: string) => void
}
const RegisterFrom: FC<Froms> = ({
    switchFrom
}): ReactElement => {

    const onFinish = (values: userInfor) => {
        // const { username, password } = values
    };

    const onFinishFailed = (err:any) => {
        //     console.log('Failed:', err);
    };

    const toggleForm = () => {
        switchFrom('login');
    }

    return (
        <>
            <div className="from-header">
                <span>注册</span>
                <span onClick={toggleForm}>账号登录</span>
            </div>
            <div className="from-content">
                <Form className="login-div" name="basic"
                    onFinish={onFinish}
                    onFinishFailed={onFinishFailed}
                    autoComplete="off"
                >
                    <Form.Item name="username"
                        rules={[{ required: true, message: 'Please input your username!', },]}
                    >
                        <Input prefix={<UserOutlined />} placeholder="Username" />
                    </Form.Item>

                    <Form.Item name="password"
                        rules={[{ required: true, message: 'Please input your password!', },]}
                    >
                        <Input.Password prefix={<UnlockFilled />} placeholder="password" />
                    </Form.Item>
                    <Form.Item name="password2"
                        rules={[{ required: true, message: 'Please confirm the password!', },]}
                    >
                        <Input.Password prefix={<UnlockFilled />} placeholder="Confirm password" />
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

export default RegisterFrom