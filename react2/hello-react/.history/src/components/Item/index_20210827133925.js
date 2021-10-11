import React, { Component } from 'react'
import './index.css'

export default class Item extends Component {
    render() {
        const {name,done} = this.props
        return (
            <li onMouseLeave={this.handleMouse(true)} onMouseEnter={this.handleMouse(false)}>
                <label>
                    <input type="checkbox" defaultChecked={done}/>
                    <span>{name}</span>
                </label>
                <button className="btn btn-danger" style={{ display: 'none' }}>删除</button>
            </li>
        )
    }
}
