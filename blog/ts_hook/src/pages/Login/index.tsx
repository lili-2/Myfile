import React,{FC, ReactElement, useState} from 'react'
import LoginFrom from './LoginFrom'
import RegisterFrom from './RegisterFrom'
import './index.css'

const Login:FC = ():ReactElement => {

  const [fromType,setFromType] = useState('login') 

  const switchFrom = (value:string) => {
    setFromType(value)
  }

  return (
    <div className="from-login">
      {fromType === 'login' 
      ? <LoginFrom switchFrom={switchFrom}/>
      : <RegisterFrom switchFrom={switchFrom}/>}
    </div>
  );
};
export default Login