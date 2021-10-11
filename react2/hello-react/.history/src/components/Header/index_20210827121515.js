import React, { Component } from 'react'
import './index.css'

export default class Footer extends Component {

    handleKeyUp = (event)=>{
        const {keyCode,target} = 
        if(event.keyCode !== 13) return;
        console.log(event.target.value)
    }

    render() {
        return (
            <div className="todo-header">
                <input onKeyUp={this.handleKeyUp} type="text" placeholder="请输入你的任务名称，按回车键确认" />
            </div>
        )
    }
}
