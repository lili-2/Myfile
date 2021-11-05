import React, { useState ,useEffect} from "react"
import {Link} from "react-router-dom"
import { Row, Col, List,message} from "antd"
import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import myAxios from "../../../util/MyAxios"
import {Articles} from '../../../interface'
import './MyArticle.css'

function MyArticle() {
    const [mylist,setMylist] = useState<Articles[]>()

    useEffect(() => {
        getAllArticles().then(
            result => setMylist(result)
        );
    },[])

    const getAllArticles = async () => {
        const result = await myAxios.get('http://localhost:3000/mylist').then(
            response => {
                console.log(myAxios);
                return response.data;
            }
        )
        return result;
    }

    const deleteArticle = async (id:number) => {
        const result = await myAxios.get(`/mylist/article?id=${id}`).then(
            response => {
                
                return response.data;
            }
        )
        console.log(result);
        message.success("删除成功")
    }

    const alterArticle = (id:number) => {
        console.log(id)
    }

    return (
        <>
            <Row className="comm-main">
                <Col className="comm-left"  span={20}>
                    <List itemLayout="vertical" dataSource={mylist} 
                        renderItem={item => ( <List.Item>
                                                    <Link to={`/mylist/detailed/${item.id}`}>
                                                        <div className="list-title">{item.title}</div>
                                                    </Link>
                                                    <div className="list-icon">
                                                        <span><CalendarFilled />{item.time}</span>
                                                        <span><HeartFilled />{item.likes}</span>
                                                        <span><MessageFilled />评论</span>
                                                        <div className="art-manager">
                                                            <button className="delete" onClick={() => deleteArticle(item.id)}>删除</button>
                                                            <button className="alter" onClick={() => alterArticle(item.id)}>修改</button>
                                                        </div>
                                                    </div>
                                                    <div className="list-context">{item.content}</div>
                                                </List.Item>
                                            )}/>
                </Col>
            </Row>
        </>
    );
}

export default MyArticle;