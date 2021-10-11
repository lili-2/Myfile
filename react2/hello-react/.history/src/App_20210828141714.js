import React, { Component } from 'react'
import Search from './components/Search'
import List from './components/List'

export default class App extends Component {
    render() {
        return (
            <div>
                <div class="row">
                    <div class="col-xs-offset-2 col-xs-8">
                        <div class="page-header"><h2>React Router Demo</h2></div>
                    </div>
                </div>
                <div class="row">
                    <div class="col-xs-2 col-xs-offset-2">
                        <div class="list-group">
                            <a class="list-group-item" href="./about.html">About</a>
                            <a class="list-group-item active" href="./home.html">Home</a>
                        </div>
                    </div>
                    <div class="col-xs-6">
                        <div class="panel">
                            <div class="panel-body">
                                <h3>我是Home的内容</h3>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        )
    }
}
