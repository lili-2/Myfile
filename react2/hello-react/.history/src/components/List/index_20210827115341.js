import React, { Component } from 'react'
import Item from '../Item'
import './index.css'

export default class List extends Component {
    render() {
        connst {todos} = this.props
        return (
            <ul className="todo-main">
                <Item />
                <Item />
            </ul>
        )
    }
}
