import React, { lazy, Suspense } from "react"
import {Switch,Route} from 'react-router-dom'
import Header from "./common/Header"

const Index = lazy(() => import('./Index/index'))
const MyArticle = lazy(() => import('./MyArticle'))
const AddArticle = lazy(() => import('./Addarticle'))
const Detailed = lazy(()=>import('./Detailed'))

function MyList() {
    return (
        <>
            <Header></Header>
            <Suspense fallback={<h1>Loading...</h1>}>
                <Switch>
                    <Route path="/mylist/write" component={AddArticle}/>
                    <Route path='/mylist/detailed/:id' component={Detailed}/>
                    <Route path="/mylist/article" component={MyArticle}/>
                    <Route path='/mylist' component={Index}/>
                </Switch>
            </Suspense>
        </>
    );
}

export default MyList;