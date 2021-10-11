import React, { Component } from 'react'

export default class Search extends Component {
    render() {
        return (
            <section className="jumbotron">
                <h3 className="jumbotron-heading">搜索github用户</h3>
                <div>
                    <input type="text" placeholder="输入关键词点击suo" />&nbsp;<button>Search</button>
                </div>
            </section>
        )
    }
}
