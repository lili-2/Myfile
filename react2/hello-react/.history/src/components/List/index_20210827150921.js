import React, { Component } from 'react'
import PropTypes from 'prop-types'
import Item from '../Item'
import './index.css'

export default class List extends Component {

    //对接受的的类型进行限制
    static propTypes = {
        todos: PropTypes.array.isRequired,
        updateTodo: PropTypes.func.isRequired
    }

    render() {
        const {todos,updateTodo,deleteTodo} = this.props
        return (
            <ul className="todo-main">
                {
                    todos.map((todo,index)=>{
                        return <Item key={todo.id} {...todo} updateTodo={updateTodo} deleteTodo={this.deleteTodo}/>
                    })
                }
            </ul>
        )
    }
}
