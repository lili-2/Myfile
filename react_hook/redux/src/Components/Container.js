import React from 'react'
import {connect} from 'react-redux'
import {
    addAction,
    squareAction,
    getAction
  }from '../actions/actions'

function Contailer(props) {

    const { num , add , square ,get} = props;

    return (
        <>
            <p>{num}</p>
            <button onClick={() => add(1)}>+1</button>
            <button onClick={() => add(2)}>+2</button>
            <button onClick={() => square()}>**</button>
            <button onClick={() => get()}>10</button>
        </>
    )
}

const mapStateToProps = (state) => {
    return {
        num: state
    }
}
const mapDispatchProps = (dispatch) => {
    return {
        add: (value) => dispatch(addAction(value)),
        square: () => dispatch(squareAction()),
        get: () => dispatch(getAction())
    }
}

// containerName 展示组件 
export default connect(mapStateToProps,mapDispatchProps)(Contailer)
