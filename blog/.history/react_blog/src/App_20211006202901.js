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
import Detailed from "./Pages/detailed"
import Login from './Pages/Login'
import MyList from "./Pages/mylist"
import AddArticle from "./components/AddArticle\"
import './static/css/app.css'

function App() {
    return (
        <Router>
            <Route path='/' exact component={Login} />
            <Route path='/mylist' component={MyList}/>
            <Route path='/detailed' component={Detailed}/>
            <Route path="/mylist/write" component={AddArticle}/>
        </Router>
    )
}
export default App