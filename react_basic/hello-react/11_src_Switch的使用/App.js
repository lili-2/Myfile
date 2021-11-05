import React, { Component } from 'react'
import { Route, Switch } from 'react-router-dom'
import About from './pages/About'
import Home from './pages/Home'//Home是路由组件 
import Header from './components/Header'//Header是一般组件
//路由组件和一般组件的区别 路由组件会收到路由器给传递的props history location match...
import MyNavLink from './components/MyNavLink'
import Test from './components/Test'

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

                            {/* Link不能加高亮效果 给className追加active要用升级版NavLink */}
                            {/* <Link className="list-group-item" to="/about" >About</Link>
                            <Link className="list-group-item" to="/home" >Home</Link> */}

                            {/* activeClassName='active'点谁给谁加类名 === bootstrap点谁给谁加active */}
                            {/* <NavLink activeClassName='demo' className="list-group-item" to="/about" >About</NavLink>
                            <NavLink activeClassName='demo' className="list-group-item" to="/home" >Home</NavLink> */}
                            <MyNavLink to="/about" title="About">About---</MyNavLink>
                            <MyNavLink to="/home" title="Home">Home---</MyNavLink>
                        </div>
                    </div>
                    {/* <div className="col-xs-6">
                        <div className="panel">
                            <div className="panel-body">
                                {注册路由 }
                                <Switch>
                                    <Route path='/about' component={About} />
                                    <Route path='/home' component={Home} />
                                    <Route path='/home' component={Test} />
                                </Switch>
                            </div>
                        </div>
                    </div> */}
                </div>
            </div>
        )
    }
}
