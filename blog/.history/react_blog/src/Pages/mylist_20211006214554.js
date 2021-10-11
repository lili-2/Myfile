import React from "react"
import 'antd/dist/antd.css'
import Header from "../components/Header/Header"
import Footer from '../components/Footer/Footer'
import Index from "../components/Index/Index"
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
