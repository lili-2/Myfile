import React from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter } from 'react-router-dom'
import App from './App';
// import Main from './Pages/Main'

ReactDOM.render( 
<BrowserRouter>
    <App/>
</BrowserRouter>,document.getElementById('root'));
// ReactDOM.render(<Main />,document.getElementById('root'));