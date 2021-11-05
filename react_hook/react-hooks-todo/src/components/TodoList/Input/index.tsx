import React, { useRef, FC, ReactElement } from "react";
import { ITodo } from "../typings";

//函数组件本身是有类型的 FC function Component

interface IProps {
    addTodo: (todo: ITodo) => void;
    todoList: ITodo[];
}

const IdInput: FC<IProps> = ({
    addTodo,
    todoList
}): ReactElement => {

    //泛型
    //useRef useState 后面都需要后面写一个泛型 默认值为null
    const inputRef = useRef<HTMLInputElement>(null)

    const addItem = (): void => {
        const val: string = inputRef.current!.value.trim()
        //加一下断言 告诉js这里肯定有值

        if (val.length) {
            const isExist = todoList.find(todo => todo.content === val);

            if (isExist) {
                alert('已存在该项');
                return;
            }
            addTodo({
                id: new Date().getTime(),
                content: val,
                completed: false
            })

            inputRef.current!.value = '';
        }
    }

    return (
        <div className="todo-input">
            <input ref={inputRef} type="text" placeholder="请输入待办项" />
            <button onClick={addItem}>增加</button>
        </div>
    )
}

// {
// id：number  newDate().getTime()
// content string
// completed: boolean 
// }
export default IdInput