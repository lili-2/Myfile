import React, { Component } from 'react'
import { NavLink } from 'react-router-dom'

export default class MyNavLink extends Component {
    render() {
        return (
            // 标签体内容是一个特殊的children属性
            // <NavLink activeClassName='demo' className="list-group-item" to={to} >{title}</NavLink>
            <NavLink activeClassName='demo' className="list-group-item" {...this.props} />
        )
    }
}
