import React from "react"
// import {Row,Col} from "antd"
import "antd/dist/antd.css"
// import Index from "./Pages/index"
import Detailed from './Pages/detailed'
// import Header from "./components/Header/Header"
import './static/css/app.css'

function App() {
  return (
    <div>
      {/* <Header></Header> */}
      {/* <Detailed></Detailed> */}
      {/* <Index/> */}
      <Detailed/>
      {/* <Row className="comm-main" type="flex" justify="center">
        <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
          左侧
        </Col>
        <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
          右侧
        </Col>
      </Row> */}
    </div>
  );
}

export default App;
