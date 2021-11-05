import {ADD,SQUARE} from '../constans/ActionTypes'

// const addOne = {
//     type: ADD,
//     num: 1
// }

// const addTwo = {
//     type: ADD,
//     num: 2
// }

// const square = {
//     type: SQUARE
// }

const addAction = (num) => {
    return {
        type: ADD,
        num
    }
}
const squareAction = (num) => {
    return {
        type: SQUARE
    }
}
const getAction = () => {
    return (dispatch,getState) => {
        fetch('./data.json')
            .then(res => res.json())
            .then(res => {
                dispatch({
                    type: 'GET',
                    num: Number(res[0])
                })
            })
    }
}
export {
    addAction,
    squareAction,
    getAction
}