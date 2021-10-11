import React,{useState} from "react";
import "../static/css/Addarticle.css"
import {Row,Col,Button, Input} from "antd"
const {TextArea} = Input


function AddArticle(){

    const [articleContent , setArticleContent] = useState('')  //markdown的编辑内容
    const [markdownContent, setMarkdownContent] = useState('预览内容') //html内容
    
    const changeContent = (e) => {
        setArticleContent(e.target.value)
        let html = e.target.value
        setMarkdownContent(html)
    }

    return (
        <Row className="article">
            <Col>
                <Row gutter={10}>
                    <Col span={16}>
                        <input style={{width:700,height:40} } placeholder="博客标题" size="large"></input>
                    </Col>
                    <Col span={8}>
                        <Button size="large">保存草稿</Button>&nbsp;
                        <Button size="large" type="primary">发布文章</Button>
                    </Col>
                </Row>
                <br/>
                <Row gutter={10}>
                    <Col span={12}>
                        <TextArea className="markdown-content" rows={25} placeholder="文章内容" onChange={changeContent}  />
                    </Col>
                    <Col span={12}>
                        <div className="show-html" children={markdownContent}></div> 
                    </Col>
                </Row>
            </Col>
        </Row>
    )
}
export default AddArticle