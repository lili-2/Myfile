import React from "react";
import {BrowserRouter as Router,Route} from 'react-router-dom'
import Login from './Login'
import MyList from "./mylist"

function Main() {
    return (
        <Router>
            <Route path='/' exact component={Login} />
            <Route path='/index' component={MyList}/>
        </Router>
    )
}
export default Main