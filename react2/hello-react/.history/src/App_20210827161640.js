import React, { Component } from 'react'

export default class App extends Component {
    render() {
        return (
            <div>
                <button onClick={this.getStudent}>点击获取学生数据</button>
            </div>
        )
    }
}