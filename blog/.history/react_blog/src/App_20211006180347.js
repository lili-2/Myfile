// import React from "react"
// // import {Row,Col} from "antd"
// import "antd/dist/antd.css"
// import Index from "./Pages/index"
// import Main from "./Pages/Main"
// // import Detailed from './Pages/detailed'
// // import Header from "./components/Header/Header"

// function App() {
//   return (
//     <Main/>
//   );
// }

// export default App;
import React from "react";
import {BrowserRouter as Router,Route} from 'react-router-dom'
import Login from './Login'
import MyList from "./mylist"
import './static/css/app.css'

function Main() {
    return (
        <Router>
            <Route path='/' exact component={Login} />
            <Route path='/index' component={MyList}/>
        </Router>
    )
}
export default App