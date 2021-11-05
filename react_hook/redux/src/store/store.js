import math from '../reducers/math';
import thunk from 'redux-thunk';
import {createStore,applyMiddleware} from 'redux';

const store = createStore(math,applyMiddleware
    (thunk));

export default store