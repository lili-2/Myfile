import React, { Component } from 'react'

export default class Search extends Component {

    search = () => {
        //获取用户的输入
        const { keyWordElement:{value: } } = this
        //发送网络请求
        console.log(value)
    }
    render() {
        return (
            <section className="jumbotron">
                <h3 className="jumbotron-heading">搜索github用户</h3>
                <div>
                    <input ref={(c) => {this.keyWordElement = c}} type="text" placeholder="输入关键词点击搜索" />&nbsp;
                    <button onClick={this.search}>搜索</button>
                </div>
            </section>
        )
    }
}