import React, { Component } from 'react'

export default class Search extends Component {

    search = () => {
        
    }
    render() {
        return (
            <section className="jumbotron">
                <h3 className="jumbotron-heading">搜索github用户</h3>
                <div>
                    <input type="text" placeholder="输入关键词点击搜索" />&nbsp;
                    <button onClick={this.search}>搜索</button>

                </div>
            </section>
        )
    }
}
