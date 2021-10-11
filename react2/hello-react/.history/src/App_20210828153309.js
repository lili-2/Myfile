import React, { Component } from 'react'
import { Link, Route } from 'react-router-dom'
import About from './pages/About'
import Home from './pages/Home'
import Header from './components/Header'//Header是一啊不能组件

export default class App extends Component {
    render() {
        return (
            <div>
                <div className="row">
                    <div className="col-xs-offset-2 col-xs-8">
                        <div className="page-header"><Header /></div>
                    </div>
                </div>
                <div className="row">
                    <div className="col-xs-2 col-xs-offset-2">
                        <div className="list-group">
                            {/* 原生html中，靠<a>跳转到不同页面 */}
                            {/* <a className="list-group-item" href="./about.html">About</a>
                            <a className="list-group-item active" href="./home.html">Home</a> */}

                            {/* 在React中靠路由链接实现切换组件 to里面不识别大小写-- 编写路由链接,路由链接能引起路由的变化*/}

                            <Link className="list-group-item" to="/about" >About</Link>
                            <Link className="list-group-item" to="/home" >Home</Link>

                        </div>
                    </div>
                    <div className="col-xs-6">
                        <div className="panel">
                            <div className="panel-body">
                                {/* 注册路由 */}

                                <Route path='/about' component={About} />
                                <Route path='/home' component={Home} />

                            </div>
                        </div>
                    </div>
                </div>
            </div>
        )
    }
}
