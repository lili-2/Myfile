import React, { Component } from 'react'
import axios from 'axios'
import { response } from 'express'

export default class Search extends Component {

    search = () => {
        //获取用户的输入 (连续解构赋值 + 重命名)
        const { keyWordElement:{value: keyWord} } = this
        
        
        //#region //发送网络请求
        // axios.get(`https://api.github.com/search/users?q=${keyWord}`).then(
        //     response => {console.log('成功',response.data)},
        //     error => {console.log('错误',error)}
        // )
        //#endregion

        //发送网络请求 fetch
        fetch(`https://api.github.com/search/users?q=${keyWord}`).then(
            response => {
                console.log('联系服务器成功')
                return response.json())//谁有返回zhi
            },
            error => {console.log('联系服务器错误',error)} 
        )

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
