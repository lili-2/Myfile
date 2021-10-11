import React, { Component } from 'react'
import Item from '../Item'
import './index.css'

export default class List extends Component {
    render() {
        cosnt {todos}
        return (
            <ul className="todo-main">
                <Item />
                <Item />
            </ul>
        )
    }
}
