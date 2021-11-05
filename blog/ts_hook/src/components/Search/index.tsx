import { FC, useRef } from "react"
import { useHistory } from "react-router"
import { Articles } from "../../interface"
import './index.css'

interface searchRes {
    content: Articles[] | ''
}

const MySearch: FC<searchRes> = ({ content }) => {

    const MyHistory = useHistory()
    const listRef = useRef<HTMLDivElement>(null)

    const chooseItem = (id: number) => {
        console.log(listRef.current)
        MyHistory.push(`mylist/detailed/${id}`)
    }

    if (content !== '' && content.length !== 0) {
        return (
            <div ref={listRef} className="searchContent">
                {
                    content.map((item) => (
                        <div key={item.id} className="serchitem">
                            {/* <Link to={`mylist/detailed/${item.id}`}> */}
                            <span onClick={() => chooseItem(item.id)}>{item.title}</span>
                            {/* </Link> */}
                            <span>{item.content}</span>
                        </div>
                    ))
                }
            </div>
        )
    } else if (content == "") {
        return <></>
    } else {
        return <div className="searchContent">
            <div className="serchitem">
                对不起,没有您要查找的信息
            </div>
        </div>
    }
}

export default MySearch