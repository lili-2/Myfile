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
                    <Col span={20}>
                        <input placeholder="博客标题" size="large"></input>
                    </Col>
                    <Col span={4}>
                        &nbsp;
                        <Select
                    </Col>
                </Row>
            </Col>
            <Col span={6}></Col>
        </Row>
    )
}
export default AddArticle