import React, { Component } from 'react'
import './index.css'

export default class Header extends Component {
    render() {
        const {todos} = this.state
        //已完成的
        const doneCount = 
        //总数
        
        return (
            <div className="todo-footer">
                <label>
                    <input type="checkbox" />
                </label>
                <span>
                    <span>已完成0</span> / 全部2
                </span>
                <button className="btn btn-danger">清除已完成任务</button>
            </div>
        )
    }
}
