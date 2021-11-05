import React,{ Component,createContext ,useContext} from "react";

const AppContext = createContext()

class Foo extends Component {
    render(){
        return (
            <AppContext.Consumer>
                {value =>  <div>{value}</div>}
            </AppContext.Consumer>
        )
    }
}
class Baz extends Component {
    static contextType = AppContext;
    render(){
        const value = this.context;
        return (
            <div>{value}</div>
        )
    }
}
const Bar = (props) => {
    const value = useContext(AppContext)
    return (
        <div>{value}</div>
    )
}

const Middle = (props) => {
    return (
        <div>
            <Foo/>
            <Bar/>
            <Baz/>
        </div>
    )
    
}
function App(params){
    return (
        <AppContext.Provider value="xiaoxiang">
            <Middle/>
        </AppContext.Provider>
    )
}
export default App