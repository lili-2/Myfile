import React, { Component } from 'react'
import { NavLink } from 'react-router-dom'

export default class MyNavLink extends Component {
    render() {
        const 
        return (
            <NavLink activeClassName='demo' className="list-group-item" to="/about" >About</NavLink>
        )
    }
}
