import { Link } from 'react-router-dom'
import {Menu} from 'antd'
import 'antd/dist/antd.css'
import '../static/css/header.css'

function  Header(){
    return (
        <Menu mode="horizontal" className="header">
            <Menu.Item key="1">
                <Link to="/mylist">我的纸条</Link>          
            </Menu.Item>
            <Menu.Item key="2">
                <Link to="/choose">抽个对象</Link>
            </Menu.Item>
        </Menu>
    )
}
export default Header