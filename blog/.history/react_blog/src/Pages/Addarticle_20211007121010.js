import React,{useState} from "react";
import {Row,Col,Button, Input} from "antd"
import "../static/css/Addarticle.css"
const {TextArea} = Input


function AddArticle(){

    const [articleContent , setArticleContent] = useState('') 
    const [markdownContent, setMarkdownContent] = useState('预览内容') 
    const [articleList, setArticleList] = useState('生成目录')
    
    const changeContent = (e) => {
        let html = e.target.value
        setMarkdownContent(html)
    }

    return (
        <div className="article">    
            <Row gutter={10}>
                <Col span={16}>
                    <input style={{width:900,height:40} } placeholder="博客标题" size="large"></input>
                </Col>
                <Col span={8}>
                    <Button size="large">保存草稿</Button>&nbsp;
                    <Button size="large" type="primary">发布文章</Button>
                </Col>
            </Row>
            <br/>
            <Row gutter={5}>
                <Col span={8}>
                    <TextArea className="markdown-content" rows={30} placeholder="文章内容"  onChange={changeContent}  />
                </Col>
                <Col span={8}>
                    <div className="show-html" children={markdownContent}></div> 
                </Col>
                <Col span={8}>
                    <div className="show-html" children={articleList} ></div> 
                </Col>
            </Row>
        </div>
    )
}
export default AddArticle