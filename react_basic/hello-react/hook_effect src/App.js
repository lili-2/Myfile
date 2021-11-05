// import React,{useState,useReducer} from 'react'

// //若一个参数是对象的话 可以不用useState 考虑useReducer
// const App = (params) => {

//     const countReducer = (state, action) => {
//         switch (action.type) {
//             case 'add':
//                 return state + 1;
//             case 'minus':
//                 return state - 1;
//             default:
//                 return state;
//         }
//     }
//     //依然定义了一个 state 是 count，初始值为0 更新dispatch   
//     const [count, countDispatch] = useReducer(countReducer, 0);

//     const onClick = (params) => {
//         //放入最新的 action
        // countDispatch({type:'add'})
//     }

//     return (
//         <>
//             <div>{count}</div>
//             <button onClick={() => onClick()}>button</button>
//         </>
//     )
// }

// export default App;



// import React,{useEffect} from "react";
// function App(){
//     const [count,setCount] = useState(0);

//     console.log('render');
    
//     useEffect(() => {
//         let timer = setInterval(() => {
//             setCount(count + 1)
//         },1000)
//         console.log('useEffect')
//         return () => {
//             console.log('clean effect')
//             clearInterval(timer)
//         }
//     })

//     return (
//         <>
//             <div>{count}</div>
//             <button onClick={() => setCount(count + 1)}>ADD</button>
//         </>
//     )
// }


import React,{useEffect,useState} from "react";

function Foo(){
    const [count,setCount] = useState(0);

    console.log('render');
    
    useEffect(() => {
        console.log('开启定时器')
        let timer = setInterval(() => {
            console.log("进入定时器")
            setCount(count + 1)
        },1000)
        console.log('useEffect')
        return () => {
            console.log('clean effect')
            clearInterval(timer)
        }
    },[count])

    return (
        <>
            <div>{count}</div>
            <button onClick={() => setCount(count + 1)}>ADD</button>
        </>
    )
}
function App(){

    const [visible,setVisible] = useState(true);

    return (
        <div>
            {visible && <Foo/>}
            <button onClick={() => setVisible(visible ? false : true)}>显示/隐藏</button>
        </div>
    )
}
export default App