import React,{Component}  from 'react'
import hello from './Hello.module.css'

export default class Hello extends Component{
    render(){
        return <h2 className={hello.title}>hello react!!!</h2>
    }
}