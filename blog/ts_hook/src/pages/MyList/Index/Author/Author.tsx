import { Divider } from "antd"
import './Author.css'

const Author = () => {
    return (
        <div className="author-div comm-box">
            <div className="author-introduction">个人中心</div>
            <Divider>我的</Divider>
            <div className="author-information">
                <div>会员中心</div>
                <div>收藏</div>
                <div>动态</div>
                <div>消息</div>
            </div>
        </div>
    )
}
export default Author