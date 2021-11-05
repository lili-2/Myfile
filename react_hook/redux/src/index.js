import React from 'react';
import ReactDOM from 'react-dom';
import Container from './Components/Container'

import store from './store/store'

import {Provider} from 'react-redux'



function App(){

  return (
    <Provider store={store}>
      <Container/>
    </Provider>
  )
}

function render(){
  ReactDOM.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
    document.getElementById('root')
  );
}

render();

store.subscribe(render)

// 1. store 存取数据的仓库 const store = createStore(reducer)
// 2. state 在数据仓库中存储的数据 获取快照 store.getState() 查看数据状态
// 3. action 对象 描述现在如何操作数据

// const action = {
//   type: 'ADD_ONE',
//   num: 1
// }
// const action = {
//   type: 'ADD_TWO',
//   num: 2
// }
// 4. dispatch 唯一能更改state的方法 store.dispatch(action)
// 5. reducer 函数 返回一个更新的state

// const reducer = (state = 10,action) => {
//   switch(action.type){
//     case 'ADD_ONE':
//       return state + action.num;
//     case 'ADD_two':
//       return state + action.num;
//   }
// }

// function App(){
//   return (
//     <div>123</div>
//   )
// }

//展示组件 UI显示  和 容器组件 