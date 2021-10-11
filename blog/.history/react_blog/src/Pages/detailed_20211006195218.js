import React, { useState } from "react"
import { Row, Col ,Affix} from "antd"

import ReactMarkdown from "react-markdown"
import MarkNav from "markdown-navbar"
import 'markdown-navbar/dist/navbar.css'

import 'antd/dist/antd.css'
import {CalendarFilled,HeartFilled,MessageFilled } from "@ant-design/icons"
import Header from "../components/Header/Header"
import Author from "../components/Index/Author/Author"
import Footer from "../components/Footer/Footer"
import '../static/css/detailed.css'

function Detailed() {
    // console.log(props.location.state)
    let markdown="# `let` 基础用法
    1. `let`命令，用来声明变量。它的用法类似于`var`，但是所声明的变量，只在let命令所在的代码块内有效。
    2. `let`命令改变了语法行为，它所声明的变量一定要在声明后使用，否则报错。
    3. 变量`x`使用`let`命令声明，所以在声明之前，都属于x的“死区”，只要用到该变量就会报错。因此，`typeof`运行时就会抛出一个`ReferenceError`。
    4. ES6 明确规定，如果区块中存在`let`和`const`命令，这个区块对这些命令声明的变量，从一开始就形成了封闭作用域。凡是在声明之前就使用这些变量，就会报错。不存在变量提升
    5. `let x = x`;
    `// ReferenceError: x is not defined`
    6. `let`不允许在相同作用域内，重复声明同一个变量。
    
    
    ### 块级作用域
    1. `let`实际上为` JavaScript` 新增了块级作用域。
    2. 
     ```javescript
    function f1() {
      let n = 5;
      if (true) {
        let n = 10;
      }
      console.log(n); // 5
    }
    ```
    
    3. `ES6 `允许块级作用域的任意嵌套。每一层都是一个单独的作用域。第四层作用域无法读取第五层作用域的内部变量。
    4. 考虑到环境导致的行为差异太大，应该避免在块级作用域内声明函数。如果确实需要，也应该写成函数表达式，而不是函数声明语句。
    5. `ES6` 的块级作用域必须有大括号，如果没有大括号，`JavaScript` 引擎就认为不存在块级作用域。
    6. ES5中有三种作用域， 全局 函数 `eval`：只在严格模式才会出现
    
    
    ### let 案例
    
    ```javascript
    let items = document.getElementsByClassName('item');
            for(let i = 0;i<items.length;i++){
                items[i].onclick = function(){
                    items[i].style.background = 'pink';
                }
            }
            
    ```
    结果有效，换成`var`无效，`let`产生每一个i在当前作用域有效，三个i互不影响
    换成`var` ，使用`this`，也可以产生效果
    产生效果
    
    ```javascript
    {
                let i = 0;
                items[i].onclick = function(){
                    items[i].style.background = 'pink';
                }
            }
            {
                let i = 1;
                items[i].onclick = function(){
                    items[i].style.background = 'pink';
                }
            }
    ```
    
    
    ### const
    1. `const`声明一个只读的常量。一旦声明，常量的值就不能改变，一定要赋初始值。
    2. 一般常量是用大写。
    3. `const`的作用域与`let`命令相同：只在声明所在的块级作用域内有效。
    4. `const`命令声明的常量也是不提升，同样存在暂时性死区
    5. `const`实际上保证的，并不是变量的值不得改动，而是变量指向的那个内存地址所保存的数据不得改动,对于简单类型的数据（数值、字符串、布尔值），值就保存在变量指向的那个内存地址，因此等同于常量。
    6. 对于数组和对象的元素的修改，不算做对常量的修改，不会报错。-------- 复合类型的数据（主要是对象和数组），变量指向的内存地址，保存的只是一个指向实际数据的指针，`const`只能保证这个指针是固定的（即总是指向另一个固定的地址），至于它指向的数据结构是不是可变的，就完全不能控制了。
    7. 如果真的想将对象冻结，应该使用`Object.freeze`方法。
    
    
    # 模板字符串
    1. ES6引入新的生命字符串的方式` `` `，之前是` ' 和' " " `
    2. 声明
    
    ```javascript
     let str = `我也是字符串`;
    ```
    3. 内容中可以直接出现换行符；
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/2021032619465345.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzUyMjczMjM0,size_16,color_FFFFFF,t_70)
    4. 变量拼接
    
    ```javascript
    let lovest = `你好`;
            let out = `${lovest}大家好`;
            console.log(out);
    ```
    
    # ES6 声明变量的六种方法 
    1. `var`命令和`function`命令。ES6 除了添加`let`和`cons`t命令，后面章节还会提到，另外两种声明变量的方法：`import`命令和`class`命令。所以，ES6 一共有 6 种声明变量的方法。
    
    # 顶层对象的属性 
    1. `var`命令和`function`命令声明的全局变量，依旧是顶层对象的属性
    2. 另一方面规定，`let`命令、`const`命令、`class`命令声明的全局变量，不属于顶层对象的属性。
    
    # globalThis 对象 
    1. `JavaScript `语言存在一个顶层对象，它提供全局环境（即全局作用域），所有代码都是在这个环境中运行。但是，顶层对象在各种实现里面是不统一的。 
    2. 浏览器里面，顶层对象是`window`，但 `Node` 和 `Web Worker `没有`window`。
    3. 浏览器和 `Web Worker` 里面，`self`也指向顶层对象，但是 `Node` 没有`self`。
    4. `Node` 里面，顶层对象是`global`，但其他环境都不支持。
    
    ES6：https://es6.ruanyifeng.com/#docs/intro
    ECMAScript 6 入门'


    return (
        <>
            <Header ></Header>
            <Row className="comm-main" type="flex" justify="center">
                <Col className="comm-left" xs={24} sm={24} md={16} lg={18} xl={14}>
                    <div>
                        <div className="detailed-title">
                            React实战
                        </div>
                        <div className="list-icon center">
                            <span><CalendarFilled />2020-10-1</span>
                            <span><HeartFilled />点赞</span>
                            <span><MessageFilled />评论</span>
                        </div>
                        <div className="detailed-content">
                            <ReactMarkdown children={markdown} escapeHtml = {false} />
                        </div>
                    </div>
                </Col>
                <Col className="comm-right" xs={0} sm={0} md={7} lg={5} xl={4}>
                    <Author/>
                    <Affix offsetTop= {5}>
                        <div className="detailed-nav comm-box">
                            <div className="nav-title">文章目录</div>
                            <MarkNav className="article-menu" source={markdown} ordered={false}></MarkNav>
                        </div>
                    </Affix>
                </Col>
            </Row>
            <Footer/>
        </>
    );
}

export default Detailed;
