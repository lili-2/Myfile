import { useRef ,useState} from "react";
import { Row, Col, Button, message } from "antd"
import myAxios from "../../../util/MyAxios"
import "./Addarticle.css"
// import axios from "axios";
// const {TextArea} = Input


function AddArticle() {

    const titleEl = useRef<HTMLInputElement>(null);
    const contentEl = useRef<HTMLTextAreaElement>(null);
    const [text, setText] = useState('');

    const publishArticle = () => {

        const title = titleEl.current!.value.trim();
        const content = contentEl.current!.value.trim();

        console.log(title, content)

        if (title && content) {
            myAxios.post('http://localhost:3000/mylist/write', {
                title,
                content
            }).then(
                data => message.success("发表成功"),
                err => console.log(err)
            )
        } else {
            message.error("标题和内容不能为空")
        }
    }

    return (
        <div className="article">
            <Row gutter={10}>
                <Col span={16}>
                    <input ref={titleEl} style={{ width: 900, height: 40 }} placeholder="博客标题"></input>
                </Col>
                <Col span={8}>
                    <Button size="large">保存草稿</Button>&nbsp;
                    <Button size="large" type="primary" onClick={publishArticle}>发布文章</Button>
                </Col>
            </Row>
            <Row gutter={5}>
                <Col span={12}>
                    <textarea ref={contentEl} onChange={(e) => setText(e.target.value)} className="markdown-content" rows={26} placeholder="文章内容" />
                </Col>
                <Col span={12}>
                    <div className="show-html">{text}</div>
                </Col>
            </Row>
        </div>
    )
}
export default AddArticle