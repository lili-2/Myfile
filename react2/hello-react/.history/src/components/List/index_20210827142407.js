import React, { Component } from 'react'
import 
import Item from '../Item'
import './index.css'

export default class List extends Component {

    //对接受的的类型进行限制
    static PropTypes = {
        addTodo: PropTypes.func.isRequired
    }

    render() {
        const {todos,updateTodo} = this.props
        return (
            <ul className="todo-main">
                {
                    todos.map((todo,index)=>{
                        return <Item key={todo.id} {...todo} updateTodo={updateTodo}/>
                    })
                }
            </ul>
        )
    }
}
