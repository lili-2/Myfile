import { createContext, FC, ReactElement } from 'react';
import Pages from './pages'
import { users } from './interface'

const Context: FC = ({ children }): ReactElement => {
const MyContext = createContext<users | {}>({});

  const user:users = {name: ""}

  return (
    <MyContext.Provider value={user}>
      {children}
    </MyContext.Provider>
  )
}

const App = (): ReactElement => {
  return (
    <Context>
      <Pages />
    </Context>
  )
};
export default App
