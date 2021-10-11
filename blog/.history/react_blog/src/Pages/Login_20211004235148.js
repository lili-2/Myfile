import { React, useState } from 'react'
import { Form, Input, Button, Spin } from 'antd';
import 'antd/dist/antd.css'
import '../static/css/Login.css'

function Login() {

    const [isLoading, setIsLoading] = useState(false)

    const checkLogin = () => {
        setIsLoading(true)
        setTimeout(() => {
            setIsLoading(false)
        }, 1000)
    }

    const onFinish = (values) => {
        console.log('Success:', values);
    };

    const onFinishFailed = (errorInfo) => {
        console.log('Failed:', errorInfo);
    };

    return (
        <div className="login-form">
            {/* // labelCol label 标签布局，同 <Col> 组件，设置 span offset 值，如 {span: 3, offset: 12}
            //onFinish 提交表单且数据验证成功后回调事件 initialValues	表单默认值，只有初始化以及重置时生效 */}
            <Form name="basic" labelCol={{ span: 6, }} wrapperCol={{ span: 16 }}  onFinish={onFinish} onFinishFailed={onFinishFailed}>
                <h1>欢迎来到登陆页面</h1>
                <Spin tip="Loading..." spinning={isLoading}>
                    <Form.Item label="Username" name="username"
                        rules={[{required: true, message: 'Please input your username!',},]}><Input />
                    </Form.Item>

                    <Form.Item label="Password" name="password"
                        rules={[{required: true,message: 'Please input your password!',},]}>
                        <Input.Password />
                    </Form.Item>

                    <Form.Item wrapperCol={{ offset: 10}}>
                        <Button type ="primary" htmlType="submit" onClick={checkLogin}>
                        Submit
                        </Button>
                    </Form.Item>
                </Spin>
            </Form>
        </div>
    );
};
export default Login;
// ReactDOM.render(<Demo />, mountNode);
