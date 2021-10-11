import React, { Component } from 'react'
import './index.css'

export default class Item extends Component {

    state = {mouse: false}//标识鼠标移入移出

    //鼠标移入移出的回调
    handleMouse = (flag) => {
        return ()=>{
            this.setState({mouse:flag})
        }
    }

    //勾选
    render() {
        const {name,done} = this.props
        const {mouse} = this.state
        return (
            <li style={{backgroundColor: mouse ? '#ddd' : 'white'}} onMouseEnter={this.handleMouse(true)} onMouseLeave={this.handleMouse(false)}>
                <label>
                    <input type="checkbox" defaultChecked={done} onChange={this.handleCheck}/>
                    <span>{name}</span>
                </label>
                <button className="btn btn-danger" style={{ display: mouse ? 'block': 'none' }}>删除</button>
            </li>
        )
    }
}
