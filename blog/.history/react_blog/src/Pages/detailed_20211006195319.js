import React, { useState } from "react"
import { Row, Col ,Affix} from "antd"

import ReactMarkdown from "react-markdown"
import MarkNav from "markdown-navbar"
import 'markdown-navbar/dist/navbar.css'

import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import Header from "../components/Header/Header"
import Author from "../components/Index/Author/Author"
import Footer from "../components/Footer/Footer"
import '../static/css/detailed.css'

function Detailed() {
    // console.log(props.location.state)
    let markdown='
    '
    return (
        <>
            <Header ></Header>
            <Row className="comm-main" type="flex" justify="center">
                <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                    <div>
                        <div className="detailed-title">
                            React实战
                        </div>
                        <div className="list-icon center">
                            <span><CalendarFilled />2020-10-1</span>
                            <span><HeartFilled />点赞</span>
                            <span><MessageFilled />评论</span>
                        </div>
                        <div className="detailed-content">
                            <ReactMarkdown children={markdown} escapeHtml = {false} />
                        </div>
                    </div>
                </Col>
                <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
                    <Author/>
                    <Affix offsetTop= {5}>
                        <div className="detailed-nav comm-box">
                            <div className="nav-title">文章目录</div>
                            <MarkNav className="article-menu" source={markdown} ordered={false}></MarkNav>
                        </div>
                    </Affix>
                </Col>
            </Row>
            <Footer/>
        </>
    );
}

export default Detailed;
