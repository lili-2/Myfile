import React from "react";

class App extends React.Component{
    constructor(){
        super();
        this.state = {
            testParam: "000"
        }
    }

    componentDidMount(){
        setTimeout(() => {
            this.setState({
                testParam: "1222"
            })
        }, 1000);
    }

    render(){
        return (
            <Child testParam={this.state.testParam}/>
        )
    }
}

class Child extends React.Component{
    // componentDidMount(){
    //     console.log(this.props.testParam)
    // }

    // constructor(pros){
    //     super(pros)
    //     console.log(pros.testParam)
    //     this.state = {arr: pros.testParam}
    // }
    //通过这种方式 arr拿不到最新的值

    constructor(props){
        super(props)
        console.log(props.testParam)
        this.state = {arr: props.testParam}
    }

    componentDidMount(){
        this.setState((props) => ({
            arr:this.props.testParam
        }))
    }

    render(){
        return (
            <div>{this.state.arr}hello
            </div>
        )
    }
}

// function Child(props){
//     useEffect(() => {
//         console.log(props)
//     }, [props])
//     return (
//         <>
//             {props.testParam}
//         </>
//     )
//   useEffect []依赖项 如果为空 也只执行第一次和最后一次 也拿不到最新值
// }

export default App