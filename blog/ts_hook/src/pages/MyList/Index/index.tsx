import { useState, useEffect } from "react"
import { Link } from "react-router-dom"
// import { useHistory } from "react-router"
import { Row, Col, List } from "antd"
import 'antd/dist/antd.css'
import { CalendarFilled, HeartFilled, MessageFilled } from "@ant-design/icons"
import myAxios from "../../../util/MyAxios"
import Author from './Author/Author'
import './index.css'
import { Articles } from '../../../interface'
// interface Articles {
//     id: number,
//     title: string,
//     time: string,
//     likes: number,
//     content: string
// }
function Index() {
    // const history = useHistory()
    const [mylist, setMylist] = useState<Articles[] | undefined>()

    useEffect(() => {
        getAllArticles().then(
            result => setMylist(result)
        );
    }, [])

    const getAllArticles = async () => {
        const result = await myAxios.get('http://localhost:3000/mylist').then(
            response => {
                // if(response === 'res'){
                //     history.push('/')
                // }else{
                    console.log(myAxios);
                return response.data
                // }
            }
        )
        return result;
    }

    return (

        <Row className="comm-main">
            <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                <List header={<div>最新日志</div>} itemLayout="vertical" dataSource={mylist}
                    renderItem={item => (<List.Item>
                        <Link to={`/mylist/detailed/${item.id}`}>
                            <div className="list-title">{item.title}</div>
                        </Link>
                        <div className="list-icon">
                            <span><CalendarFilled />{item.time}</span>
                            <span><HeartFilled />{item.likes}</span>
                            <span><MessageFilled />评论</span>
                        </div>
                        <div className="list-context">{item.content}</div> </List.Item>)} />
            </Col>
            <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
                <Author />
            </Col>
        </Row>

    );
}

export default Index;