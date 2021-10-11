import React,{useState} from "react";
import marked from "marked"
import "./Addarticle.css"
import {Row,Col,Select,Button,Datepicker, Input} from "antd"
const {Option} = Select
const {TextArea} = Input


function AddArticle(){
    return (
        <Row gutter={5}>
            <Col span={18}>
                <Row gutter={10}>
                    <Col span={16}>
                        <input style={{width:800,height:60} } placeholder="博客标题" size="large"></input>
                    </Col>
                    <Col span={8}>
                        <Button size="large">保存草稿</Button>
                        <Button size="large" type="primary">发布文章</Button>
                        {/* &nbsp;
                        <Select defaultValue="1" size="large">
                            <Option value="1">视频教程</Option>
                        </Select> */}
                    </Col>
                </Row>
                <br/>
                <Row gutter={10}>
                    <Col span={12}>
                        <TextArea className="markdown-content" rows={25} placeholder="文章内容" />
                    </Col>
                    <Col span={12}>
                        <div className="show-html"></div>
                    </Col>
                </Row>
            </Col>
            <Col span={6}></Col>
        </Row>
    )
}
export default AddArticle