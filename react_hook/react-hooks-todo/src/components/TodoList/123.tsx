import React, { FC, useEffect, ReactElement, useCallback, useState } from "react";

import IdInput from './Input'
import TdList from "./List";
import { ITodo } from "./typings";

const TodoList: FC = (): ReactElement => {

    const [todoList, setTodoList] = useState<ITodo[]>([])

    // useReducer 存在的意义 是 usestate更高级的解决方案
    // 它本身会返回一个 状态 和 dispatch（dispatch会调用reducer相关的程序 直接调用）
    // 当状态的修改是有多种方案的时候 add remove 多种方法操作一个状态的变化 方法内部有相对比较复杂的逻辑的时候 

    useEffect(() => {
        console.log(todoList)
    }, [todoList])

    const addTodo = useCallback((todo: ITodo) => {
        setTodoList(todoList => [...todoList, todo]);
    }, [])
    // 父组件更新 子组件并没有更新的时候 这个函数 会重新生成一次
    //  如果子组件的方法是父组件传过来的话 都用useCallback包一下
    return (
        <div className="todo-list">
            <IdInput
                addTodo={addTodo}
                todoList={todoList}
            />
            <TdList todoList={[]} toggleTodo={function (id: number): void {
                throw new Error("Function not implemented.");
            } } removeTodo={function (id: number): void {
                throw new Error("Function not implemented.");
            } } />
        </div>
    )
}
export default TodoList