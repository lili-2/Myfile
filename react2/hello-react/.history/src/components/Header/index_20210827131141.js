import React, { Component } from 'react'
import {nanoid}
import './index.css'

export default class Footer extends Component {

    handleKeyUp = (event)=>{
        const {keyCode,target} = event 
        if(keyCode !== 13) return;
        const todoObj = {id: 1,name: target.value,done: false}
        this.props.addTodo(todoObj)
    }

    render() {
        return (
            <div className="todo-header">
                <input onKeyUp={this.handleKeyUp} type="text" placeholder="请输入你的任务名称，按回车键确认" />
            </div>
        )
    }
}
