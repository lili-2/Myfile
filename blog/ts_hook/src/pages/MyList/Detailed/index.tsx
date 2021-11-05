import React, { useState ,useEffect} from "react"
import {Row,Col,Affix} from "antd"
import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import myAxios from "../../../util/MyAxios"
import './detailed.css'

interface ArtDetail{
    title: string,
    content: string
}

const Detailed = (props: { match: { params: { id: any } } }) => {

    const [article, setArticle] = useState<ArtDetail>({title:'',content:''})

    const getArticle = async () => {
        const id = props.match.params.id
        const result = await myAxios.get(`http://localhost:3000/detailed?id=${id}`).then(
            response => response.data[0]
        )
        return result;
    }
    
    useEffect(() => {
        getArticle().then(
            result => setArticle(result)
        );
    },[])

    return (
        <>
            <Row className="comm-main">
                <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                    <div>
                        <div className="detailed-title">{article!.title}</div>
                        <div className="list-icon center">
                            <span><CalendarFilled />2020-10-1</span>
                            <span><HeartFilled />点赞</span>
                            <span><MessageFilled />评论</span>
                        </div>
                        <div className="detailed-content">
                            <div>{article!.content}</div>
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
        </>
    );
}
export default Detailed;