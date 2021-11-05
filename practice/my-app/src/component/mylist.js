import { Route } from "react-router"
import { NavLink } from "react-router-dom"
import '../static/css/mylist.css'
import Get from "./get"
import Put from "./put"

function Mylist(){
    return (
        <>
            <div className="mylist-header">
                <div>
                    <NavLink activeClassName='active' to="/mylist/put">我放入的纸条</NavLink>
                </div>
                <div>
                    <NavLink activeClassName='active' to="/mylist/get">我抽到的纸条</NavLink>
                </div>
            </div>
            <Route path="/mylist/put" component={Put}/>
            <Route path="/mylist/get" component={Get}/>

        </>
    )
}
export default Mylist