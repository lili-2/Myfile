import React from "react"
import {Route} from 'react-router-dom'
import 'antd/dist/antd.css'
import Header from "../components/Header/Header"
import Footer from '../components/Footer/Footer'
import Index from "../components/Index/Index"
import Write from "./home"
import '../static/css/index.css'

function MyList() {

    return (
        <>
            <Header ></Header>
            {/* <Index></Index> */}
            <Route path="/mylist" exact component={Index}/>
            <Route path="/mylist/write" component={Write}/>
            <Footer></Footer>
        </>
    );
}

export default MyList;
