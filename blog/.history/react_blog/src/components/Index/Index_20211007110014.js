import React, { useState ,useEffect} from "react"
import {Link} from "react-router-dom"
import axios from "axios"
import { Row, Col, List} from "antd"
import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import Author from './Author/Author'
import './Index.css'
function Index() {

    const getAllArticles = async () => {
        const result = await axios.get('http://localhost:3000/mylist').then(
            response => response.data.list
        )
        setMylist(result)
    }

    useEffect(() => {
        getAllArticles()
    },[])

    const [mylist,setMylist] = useState('')
    return (
        <>
            <Row className="comm-main" type="flex" justify="center">
                <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                    <List  header={<div>最新日志</div>} itemLayout="vertical" dataSource={mylist} 
                        renderItem={item => (<List.Item>
                                                <Link to='./detailed'>
                                                    <div className="list-title">{item.title}</div>
                                                </Link>
                                                        <div className="list-icon">
                                                            <span><CalendarFilled />2020-10-1</span>
                                                            <span><HeartFilled />点赞</span>
                                                            <span><MessageFilled />评论</span>
                                                        </div>
                                                        
                                                        {/* <div className="list-context">{item.content}</div> </List.Item>)}/> */}
                </Col>
                <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
                    <Author/>
                </Col>
            </Row>
        </>
    );
}

export default Index;