import { Link } from 'react-router-dom'
import '../static/css/get.css'
function Get(){
    return (
        <div className="get_note">
          <div className="get_note_item">
            <div><img src="https://t7.baidu.com/it/u=2295206085,4139296147&fm=193&f=GIF" /></div>
            <div>hello word</div>
            <button><Link to="/detailed?id=1">详情页</Link></button>
          </div>     
          <div className="get_note_item">
            <div><img src="https://t7.baidu.com/it/u=2295206085,4139296147&fm=193&f=GIF" /></div>
            <div>hello word</div>
            <button>
              <Link to="/detailed?id=1">详情页</Link>
            </button>
          </div> 
        </div>
    )
}
export default Get