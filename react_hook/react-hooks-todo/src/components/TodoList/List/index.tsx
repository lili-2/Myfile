import React, { FC, ReactElement } from "react";
import { ITodo } from "../typings";
import Item from "./Item";

interface IProps {
    todoList: ITodo[];
    toggleTodo: (id: number) => void;
    removeTodo: (id: number) => void;
}


const TdList:FC<IProps> = ({
    todoList,
    toggleTodo,
    removeTodo
}):ReactElement => {
    return (
        <div className="todo-list">
            {
                todoList && todoList.map((todo: ITodo) => {
                    return (
                        <Item 
                        key={todo.id}
                        todo = {todo}
                        removeTodo = {removeTodo}
                        toggleTodo = {toggleTodo}
                        />
                    )
                })
            }
        </div>
    )
}

export default TdList