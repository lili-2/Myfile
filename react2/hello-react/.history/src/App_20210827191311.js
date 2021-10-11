import React, { Component } from 'react'
import axios from 'axios'

export default class App extends Component {

    getStudentData = () => {
        axios.get('http://localhost:3000/index2.html').then(
            response => {console.log('成功了',response.data);},
            error => {console.log('失败了',error);}
        )
    }

    render() {
        return (
            <div>
                <button onClick={this.getStudentData}>点击获取学生数据</button>
                <button onClick={this.getCarData}>点击获取数据</button>
            </div>
        )
    }
}
