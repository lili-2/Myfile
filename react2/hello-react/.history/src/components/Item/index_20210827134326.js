import React, { Component } from 'react'
import './index.css'

export default class Item extends Component {
    handleMouse = (flag) => {
        return (event)=>{
            console.log(event,flag)
            if(flag){
                event.backgroundcolor = 'lightblue'
            }else{
                event.backgroundcolor = ''
            }
        }
    }
    render() {
        const {name,done} = this.props
        return (
            <li onMouseEnter={this.handleMouse(true)} onMouseEnter={this.handleMouse(true)}>
                <label>
                    <input type="checkbox" defaultChecked={done}/>
                    <span>{name}</span>
                </label>
                <button className="btn btn-danger" style={{ display: 'none' }}>删除</button>
            </li>
        )
    }
}
