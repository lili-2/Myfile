import React,{useState,useMemo,useCallback,memo} from 'react'

function SubCounter ({onClick,data}){
    console.log('SubCounter render');
    return (
        <button onClick={data.number}></button>
    )
}
SubCounter = memo(SubCounter)

let oldData,oldAddClick;

export default function Counter2(){
    console.log('Counter2 render');
    const [name,setName] = useState('计时器');
    const [number,setNumber] = useState(0)

    // const data = useMemo(() => {number},[]);
    const data = useMemo(() => number, [number]);
    console.log('data === oldData',data === oldData);

    oldData = data;

    const addClick = useCallback(
        () => {
            setNumber(number + 1);
        },[number],
    )
    oldAddClick = addClick
    console.log('addClick === oldAddClick',addClick === oldAddClick);
    

    return (
        <>
            <input type="text" value={name} onChange={(e) => setName(e.target.value)}/>
            <SubCounter data = {data} onClick={addClick}/>
        </>

    )
}