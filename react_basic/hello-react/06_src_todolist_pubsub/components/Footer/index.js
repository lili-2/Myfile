import React, { Component } from 'react'
import './index.css'

export default class Header extends Component {

    //全选的回调
    // handleCheckAll = (event) => {
    //     this.props.checkAllTodo(event.target.checked)
    // }

    // //清除所有已完成的
    // handleClearAllDone = () => {
    //     this.props.clearAlltodo()
    // }

    render() {
        // const {todos} = this.props
        //已完成的
        // const doneCount = todos.reduce((pre,todo)=>{return pre + (todo.done ? 1 : 0)},0)
        //总数
        // const total = todos.length
        
        return (
            <div className="todo-footer">
                <label>
                    <input type="checkbox"/>
                </label>
                <span>
                    <span>已完成</span> / 全部
                </span>
                <button className="btn btn-danger">清除已完成任务</button>
            </div>
        )
    }
}
