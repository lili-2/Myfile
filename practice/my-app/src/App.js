import React from 'react';
import { Route ,Switch} from 'react-router';
import './App.css';
import Header from './component/header';
import Choose from './component/choose';
import Mylist from './component/mylist';
import Detailed from './page/detailed';

function App() {
  return (
    <div>
      <Header />
      <Switch>
        <Route path="/detailed" component={Detailed}/>
        <Route path="/mylist"  component={Mylist}/>
        <Route path="/choose" component={Choose}/>
      </Switch>
    
    </div>
  )
}
export default App