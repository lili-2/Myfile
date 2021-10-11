import React, { Component } from 'react'
import Search from './components/Search'
imp
import './App.css'

export default class App extends Component {
    render() {
        return (
            <div className="container">
                <Search />
                <List />
            </div>
        )
    }
}
