import React, { Component } from 'react'
import { Link, BrowserRouter } from 'react-router-dom'
import Home from './components/About'
import About from './components/Home'

export default class App extends Component {
    render() {
        return (
            <div>
                <div className="row">
                    <div className="col-xs-offset-2 col-xs-8">
                        <div className="page-header"><h2>React Router Demo</h2></div>
                    </div>
                </div>
                <div className="row">
                    <div className="col-xs-2 col-xs-offset-2">
                        <div className="list-group">
                            {/* 原生html中，靠<a>跳转到不同页面 */}
                            {/* <a className="list-group-item" href="./about.html">About</a>
                            <a className="list-group-item active" href="./home.html">Home</a> */}

                            {/* 在React中靠路由链接实现切换组件 to里面不识别大小写*/}
                            <BrowserRouter>
                                <Link className="list-group-item" to="/about" >About</Link>
                                <Link className="list-group-item" to="/home" >Home</Link>
                            </BrowserRouter>
                        </div>
                    </div>
                    <div className="col-xs-6">
                        <div className="panel">
                            <div className="panel-body">
                                <h3>我是Home的内容</h3>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        )
    }
}
