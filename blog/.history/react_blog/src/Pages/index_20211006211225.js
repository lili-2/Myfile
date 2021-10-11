// import { Link, Route } from 'react-router-dom'
// import React, { useState, useEffect } from "react"
// import { Row, Col, List } from "antd"
// import { CalendarFilled, HeartFilled, MessageFilled } from "@ant-design/icons"


// import 'antd/dist/antd.css'
// import Header from "../components/Header/Header"
// import Author from "../components/Index/Author/Author"
// import Footer from '../components/Footer/Footer'
// import Detailed from './detailed'
// import axios from 'axios'
// import '../static/css/index.css'

// function Index() {

    // const getArticle = async () => {
    //     const result = await axios.get('http://localhost:3000').then(
    //         response => response.data.list
    //     )
    //     setMylist(result)
    // }

    // useEffect(() => {
    //     getArticle();
    // }, [])

    // const [mylist, setMylist] = useState('')

    // // const handleClick = () => {
    // //         Router.push('')
    // // }

//     return (
//         <>
//             <Header ></Header>
//             <Row className="comm-main" type="flex" justify="center">
//                 <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
//                     <List header={<div>最新日志</div>} itemLayout="vertical" dataSource={mylist}
//                         renderItem={item => (
//                             <List.Item>
//                                 {/* <Link to="./detailed"> */}
//                                 <Link href="./detailed">
//                                     <div className="list-title">{item.title}</div>
//                                 </Link>
//                                 {/* </Link> */}
//                                 <div className="list-icon">
//                                     <span><CalendarFilled />2020-10-1</span>
//                                     <span><HeartFilled />点赞</span>
//                                     <span><MessageFilled />评论</span>
//                                 </div>
//                                 {/* <Route path='/detailed' component={Detailed} /> */}
//                                 <div className="list-context">{item.content.slice(0, 200)}</div>
//                             </List.Item>
//                         )} />

//                 </Col>
//                 <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
//                     <Author />
//                 </Col>
//             </Row>
//             <Footer></Footer>
//         </>
//     );
// }

// export default Index;
