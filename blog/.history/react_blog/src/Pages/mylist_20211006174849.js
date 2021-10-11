import React, { useState } from "react"
import { Row, Col, List ,Breadcrumb} from "antd"
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import 'antd/dist/antd.css'
import Header from "../components/Header/Header"
import Author from "../components/Anthor/Author"
import Footer from '../components/Footer/Footer'
import Index from "../components/"
import '../static/css/index.css'

function MyList() {

    return (
        <>
            <Header ></Header>
            <Index></Index>
            <Footer></Footer>
        </>
    );
}

export default MyList;
