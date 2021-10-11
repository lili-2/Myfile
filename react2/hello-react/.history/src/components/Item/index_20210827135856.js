import React, { Component } from 'react'
import './index.css'

export default class Item extends Component {

    state = {mouse: false}

    handleMouse = (flag) => {
        return ()=>{
            this.setState({mouse:flag})
        }
    }
    render() {
        const {name,done} = this.props
        return (
            <li style={{backgroundColor: this.state.mouse ? '#ddd' : 'white'}} onMouseEnter={this.handleMouse(true)} onMouseLeave={this.handleMouse(false)}>
                <label>
                    <input type="checkbox" defaultChecked={done}/>
                    <span>{name}</span>
                </label>
                <button className="btn btn-danger" style={{ display: mouse ? : }}>删除</button>
            </li>
        )
    }
}
