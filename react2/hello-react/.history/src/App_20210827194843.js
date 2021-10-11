import React, { Component } from 'react'

export default class App extends Component {
    render() {
        return (
            <div ｃｌａｓｓＮａｍｅ＝"container">
                <section ｃｌａｓｓＮａｍｅ＝"jumbotron">
                    <h3 ｃｌａｓｓＮａｍｅ＝"jumbotron-heading">Search Github Users</h3>
                    <div>
                        <input type="text" placeholder="enter the name you search" />&nbsp;<button>Search</button>
                    </div>
                </section>
                <div ｃｌａｓｓＮａｍｅ＝"row">
                    <div ｃｌａｓｓＮａｍｅ＝"card">
                        <a href="https://github.com/reactjs" target="_blank">
                            <img src="https://avatars.githubusercontent.com/u/6412038?v=3" style='width: 100px' />
                        </a>
                        <p ｃｌａｓｓＮａｍｅ＝"card-text">reactjs</p>
                    </div>
                    <div ｃｌａｓｓＮａｍｅ＝"card">
                        <a href="https://github.com/reactjs" target="_blank">
                            <img src="https://avatars.githubusercontent.com/u/6412038?v=3" style='width: 100px' />
                        </a>
                        <p ｃｌａｓｓＮａｍｅ＝"card-text">reactjs</p>
                    </div>
                    <div ｃｌａｓｓＮａｍｅ＝"card">
                        <a href="https://github.com/reactjs" target="_blank">
                            <img src="https://avatars.githubusercontent.com/u/6412038?v=3" style='width: 100px' />
                        </a>
                        <p ｃｌａｓｓＮａｍｅ＝"card-text">reactjs</p>
                    </div>
                    <div ｃｌａｓｓＮａｍｅ＝"card">
                        <a href="https://github.com/reactjs" target="_blank">
                            <img src="https://avatars.githubusercontent.com/u/6412038?v=3" style='width: 100px' />
                        </a>
                        <p ｃｌａｓｓＮａｍｅ＝"card-text">reactjs</p>
                    </div>
                    <div ｃｌａｓｓＮａｍｅ＝"card">
                        <a href="https://github.com/reactjs" target="_blank">
                            <img src="https://avatars.githubusercontent.com/u/6412038?v=3" style='width: 100px' />
                        </a>
                        <p ｃｌａｓｓＮａｍｅ＝"card-text">reactjs</p>
                    </div>
                </div>
            </div>
        )
    }
}
