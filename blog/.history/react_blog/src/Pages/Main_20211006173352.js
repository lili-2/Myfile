import React from "react";
import {BrowserRouter as Router,Route} from 'react-router-dom'
import Login from './Login'
import AddArticle from "../components/AddArticle/Addarticle";

function Main() {
    return (
        <Router>
            <Route path='/' exact component={Login} />
            <Route path='/index' component={AddArticle}/>
        </Router>
    )
}
export default Main