import React, { Component } from 'react'
import PubSub from 'pubsub-js' 
import PropTypes from 'prop-types'
import Item from '../Item'
import './index.css'

export default class List extends Component {

    state = {
        todos:[
            {id: '001',name:'吃饭',done: true},
            {id: '002',name:'睡觉',done: true},
            {id: '003',name:'打代码',done: false},
            {id: '004',name:'逛街',done: false},
        ]
    }

    componentDidMount(){
        //dingyue

    }
    //对接受的的类型进行限制
    // static propTypes = {
    //     todos: PropTypes.array.isRequired,
    //     updateTodo: PropTypes.func.isRequired,
    //     deleteTodo: PropTypes.func.isRequired
    // }

    render() {
        const {todos,updateTodo,deleteTodo} = this.state
        return (
            <ul className="todo-main">
                {
                    todos.map((todo,index)=>{
                        return <Item key={todo.id} {...todo} updateTodo={updateTodo} deleteTodo={deleteTodo}/>
                    })
                }
            </ul>
        )
    }
}
