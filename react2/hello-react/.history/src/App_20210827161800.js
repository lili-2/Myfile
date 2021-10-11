import React, { Component } from 'react'
import axios from 'axios'
import { response } from 'express'

export default class App extends Component {

    getStudentData = () => {
        axios.get().then(
            response =>
        )
    }

    render() {
        return (
            <div>
                <button onClick={this.getStudentData}>点击获取学生数据</button>
            </div>
        )
    }
}
