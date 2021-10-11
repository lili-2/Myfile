import React, { useState ,useEffect} from "react"
import axios from "axios"
import {Row,Col,Affix} from "antd"
import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import Header from "../components/Header/Header"
import Footer from "../components/Footer/Footer"
import '../static/css/detailed.css'

function Detailed(){

    const [article, setArticle] = useState()
    const [articleTitle,setArticleTitle] = useState()

    const getArticle = async () => {
        const result = await axios.get('http://localhost:3000/mylist').then(
            response => response.data.list[1]
        )
        setArticleTitle(result.title)
        setArticle(result.content)
    }
    
    useEffect(() => {
        getArticle();
    },[])

    return (
        <>
            <Header ></Header>
            <Row className="comm-main" type="flex" justify="center">
                <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                    <div>
                        <div className="detailed-title" children={articleTitle}>
                        </div>
                        <div className="list-icon center">
                            <span><CalendarFilled />2020-10-1</span>
                            <span><HeartFilled />点赞</span>
                            <span><MessageFilled />评论</span>
                        </div>
                        <div className="detailed-content">
                            <div children={article}></div>
                        </div>
                    </div>
                </Col>
                <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
                    <Affix offsetTop= {5}>
                        <div className="detailed-nav comm-box">
                            <div className="nav-title">文章目录</div>
                        </div>
                    </Affix>
                </Col>
            </Row>
            <Footer/>
        </>
    );
}
export default Detailed;