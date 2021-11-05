import { useState } from 'react'
import { Link, useHistory } from 'react-router-dom'
import { Row, Col, Menu, Input, Space } from 'antd'
import { SnippetsFilled, EditFilled } from '@ant-design/icons';
import myAxios from '../../../../util/MyAxios';
import './index.css'
import MySearch from  '../../../../components/Search'
import { Articles } from '../../../../interface';
const { Search } = Input


const Header = () => {

    const [searchCon, setSearchCon] = useState<Articles[] | ''>('')

    const SearchContents = async (content: string) => {
        if(content.trim() == '') return ""
        const result = await myAxios.get(`http://localhost:3000/mylist/search?searchReq=${content}`).then(
            (res) => {
                return res.data
            }
        )
        return result;
    }

    const onSearch = (content: string) => {
        SearchContents(content).then(
            result => {
                setSearchCon(result)
            }
        );
    }

  

    return (

        <Row className="header">
            <Col className="header_item header_title">
                Blog
            </Col>
            <Col className="header_item">
                <Space direction="vertical" className="search_item">
                    <Search placeholder="请输入关键字" enterButton="Search" size="large" onSearch={onSearch} />
                    <MySearch content={searchCon}/>
                </Space>
            </Col>
            <Col className="header_item header_right">
                <Menu mode="horizontal">
                    <Menu.Item key="1">
                        <Link to="/mylist">首页</Link>
                    </Menu.Item>
                    <Menu.Item key="3"><EditFilled />
                        <Link to="/mylist/write">创作中心</Link>
                    </Menu.Item>
                    <Menu.Item key="4"><SnippetsFilled />
                        <Link to="/mylist/article">内容管理</Link>
                    </Menu.Item>
                </Menu>
            </Col>
        </Row>

    )
}
export default Header