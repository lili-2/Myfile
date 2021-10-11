import React, { Component } from 'react'
import Header from './components/Header'
import List from './components/List'
import Footer from './components/Footer'
import './App.css'

export default class App extends Component {
    //状态在哪里,操作方法的状态就在哪里

    // //初始化状态
    // state = {
    //     todos:[
    //         {id: '001',name:'吃饭',done: true},
    //         {id: '002',name:'睡觉',done: true},
    //         {id: '003',name:'打代码',done: false},
    //         {id: '004',name:'逛街',done: false},
    //     ]
    // }

    //addTodo用于添加一个todo,接收的参数是todo对象
   ?
    //用于更新一个todo对象
    updateTodo = (id,done) => {
        
        const {todos} = this.state
        
        const newTodos = todos.map((todoObj) => {
            if(todoObj.id === id) return {...todoObj,done}
            else return todoObj
        })
        this.setState({todos: newTodos})
    }
    
    //用于删除一个todo对象
    deleteTodo = (id) => {
        const {todos} = this.state
        const newTodos = todos.filter(todoObj => {
            return todoObj.id !== id
        })
        this.setState({todos: newTodos})
    }

    //全部选中
    checkAllTodo = (done) => {
        const {todos} = this.state
        const newTodos = todos.map((todoObj) => {
            return {...todoObj,done}
        })
        this.setState({todos: newTodos})
    }

    //清除已完成
    clearAlltodo = () => {
        console.log("清除")
        const {todos} = this.state
        const newTodos = todos.filter((todoObj) => {
            return !todoObj.done 
        })
        this.setState({todos: newTodos})
    }
    render() {
        const {todos} = this.state
        return (
            <div className="todo-container">
                <div className="todo-wrap">
                    <Header addTodo = {this.addTodo}/>
                    <List todos={todos} deleteTodo={this.deleteTodo} updateTodo = {this.updateTodo}/>
                    <Footer todos={todos} checkAllTodo={this.checkAllTodo} clearAlltodo={this.clearAlltodo} />
                </div>
            </div>
        )
    }
}
