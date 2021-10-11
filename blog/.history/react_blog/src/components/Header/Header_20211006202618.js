import React from 'react'
import {Link} from 'react-router-dom'
import { Row, Col, Menu, Input, Space } from 'antd'
import { SnippetsFilled,HomeFilled, EditFilled ,FundFilled} from '@ant-design/icons';
import './Header.css'
const { Search } = Input

function Header() {

    const onSearch = value => console.log(value);

    return (
        <div className="header">
            <Row type="flex" justify="center" align="middle">
                <Col className="header_item">
                </Col>
                <Col className="header_item">
                    <Space direction="vertical">
                        <Search placeholder="请输入关键字" enterButton="Search" size="large" onSearch={onSearch}/>
                    </Space>
                </Col>
                <Col className="header_item header_right">
                    <Menu mode="horizontal">
                        <Link to="/mylist">
                            <Menu.Item key="home"><HomeFilled /> 首页</Menu.Item>
                        </Link>
                        <Link to="/visit">
                            <Menu.Item key="visit"><FundFilled /> 访客记录</Menu.Item>
                        </Link>
                        <Link to="/mylist/write">
                            <Menu.Item key="write "><EditFilled /> 创作中心</Menu.Item>
                        </Link>
                        <Link to="/article">
                            <Menu.Item key="article"><SnippetsFilled /> 内容管理</Menu.Item>
                        </Link>
                    </Menu>
                </Col>
            </Row>
        </div>
    )
}

export default Header