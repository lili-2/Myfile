import {Row,Col} from 'antd'
import '../static/css/choose.css'

function Choose(){
    return (
        <>
        <div className="choose_middle">
            <Row className="choose_middle_ad">
                广告位
            </Row>
            <Row className="choose_middle_two">
                <Col span={10}>
                    <div className="choose_middle_left">
                        <header>男生盒子</header>
                        <div className="choose_middle_pic">
                            <img src="http://bpic.588ku.com/element_pic/17/12/25/8b2d72ee81b9dc1341e61281fabd7254.jpg"/>
                        </div>
                        <div className="choose_note">
                            放入一张男生纸条
                        </div>
                        <div className="choose_note">
                            抽取一张男生纸条
                        </div>
                    </div>
                </Col>
                <Col span={10}>
                    <div className="choose_middle_right">
                        <header>女生盒子</header>
                        <div className="choose_middle_pic">
                            <img src="http://bpic.588ku.com/element_pic/17/12/25/8b2d72ee81b9dc1341e61281fabd7254.jpg"/>
                        </div>
                        <div className="choose_note">
                            放入一张女生纸条
                        </div>
                        <div className="choose_note">
                            抽取一张女生纸条
                        </div>
                    </div>
                </Col>
            </Row>
        </div>
        <div className="footer">
           <span>玩家须知</span>
        </div>
        </>
    )
}
export default Choose