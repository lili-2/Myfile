import React, { FC, useEffect, ReactElement, useCallback, useReducer } from "react";

import IdInput from './Input'
import TdList from "./List";
import { ITodo, IState, ACTION_TYPE } from "./typings"
import { todoReducer } from './reducer'

//惰性初始化
// const initialState: IState = {
//     todoList: []
// }
//可以用函数去创建一个state出来 他不执行是没有state的
function init (initTodoList: ITodo[]): IState{
    return {
        todoList: initTodoList
    }
}
const TodoList: FC = (): ReactElement => {

    // const [todoList, setTodoList] = useState<ITodo[]>([])

    //reducer 可以传入第三个参数 当useReducer执行的时候 才会创建出一个state
    //惰性初始化
    const [state, dispatch] = useReducer(todoReducer, [],init)
    useEffect(() => {
        const todoList = JSON.parse(localStorage.getItem('todolist') || '[]');

        dispatch({
            type:ACTION_TYPE.INIT_TODOLIST,
            payload: todoList
        })
    }, [])

    useEffect(() => {
        localStorage.setItem('todolist',JSON.stringify(state.todoList))
    }, [state.todoList])

    const addTodo = useCallback((todo: ITodo): void => {
        // setTodoList(todoList => [...todoList, todo]);
        dispatch({
            type: ACTION_TYPE.ADD_TODO,
            payload: todo
        })
    }, [])

    const removeTodo = useCallback((id:number): void=> {
            dispatch({
                type: ACTION_TYPE.REMOVE_TODO,
                payload: id
            })
        },[],
    )

    const toggleTodo = useCallback((id:number): void=> {
            dispatch({
                type: ACTION_TYPE.TOGGLE_TODO,
                payload: id
            })
    },[],
)
    // 父组件更新 子组件并没有更新的时候 这个函数 会重新生成一次
    //  如果子组件的方法是父组件传过来的话 都用useCallback包一下
    return (
        <div className="todo-list">
            <IdInput
                addTodo={addTodo}
                todoList={state.todoList}
            />
            <TdList
                todoList={state.todoList}
                removeTodo = {removeTodo}
                toggleTodo = {toggleTodo}
            />
        </div>
    )
}
export default TodoList