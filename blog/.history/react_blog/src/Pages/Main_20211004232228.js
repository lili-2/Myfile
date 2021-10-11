import React from "react";
import {BrowserRouter,Route} from 'react-router-dom'
import Login from './Login'

export default function Main() {
    return (
        <BrowserRouter>
            <Route path='/login' component={Login}>
            </Route>
        </BrowserRouter>
    )
}
