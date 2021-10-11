import React from "react";
import {BrowserRouter as,Route} from 'react-router-dom'
import Login from './Login'

export default function Main() {
    return (
        <BrowserRouter>
            <Route path='/login' component={Login}>
            </Route>
        </BrowserRouter>
    )
}
