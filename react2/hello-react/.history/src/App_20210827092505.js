//创建外壳组件APP
import React,{Component} from 'react'
import Hello from './components/Hello/Hello'
import Welcome from './components/H

//创建并暴露App组件
export default class App extends Component{
    render(){
        return (
            <div>
                <Hello/>
            </div>
        )
    }
}
