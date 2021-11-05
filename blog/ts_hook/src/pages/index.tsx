import { FC, ReactElement } from "react"
import { Switch, Route } from "react-router-dom"
import Login from "./Login"
import MyList from "./MyList"

const Pages: FC = (): ReactElement => {
  return (
    <Switch>
      <Route path='/' exact component={Login} />
      <Route path='/mylist' component={MyList} />
    </Switch>
  )
}
export default Pages