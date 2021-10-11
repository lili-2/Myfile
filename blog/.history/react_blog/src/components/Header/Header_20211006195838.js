import React from 'react'
import { Row, Col, Menu, Input, Space } from 'antd'
import { SnippetsFilled,HomeFilled, EditFilled, AudioOutlined ,FundFilled} from '@ant-design/icons';
import './Header.css'
const { Search } = Input;

const suffix = (
    <AudioOutlined
        style={{
            fontSize: 16,
            color: '#1890ff',
        }}
    />
);

function Header() {

    const onSearch = value => console.log(value);

    return (
        <div className="header">
            <Row type="flex" justify="center" align="middle">
                <Col className="header_item">
                </Col>
                <Col className="header_item">
                    <Space direction="vertical">
                        <Search placeholder="请输入关键字" enterButton="Search" size="large" suffix={suffix} onSearch={onSearch}/>
                    </Space>
                </Col>
                <Col className="header_item">
                    <Menu mode="horizontal">
                        <Menu.Item key="home"><HomeFilled /> 首页</Menu.Item>
                        <Menu.Item key="visit"><FundFilled /> 访客记录</Menu.Item>
                        <Menu.Item key="write "><EditFilled /> 创作中心</Menu.Item>
                        <Menu.Item key="article"><SnippetsFilled /> 内容管理</Menu.Item>
                    </Menu>
                </Col>
            </Row>
        </div>
    )
}

export default Header