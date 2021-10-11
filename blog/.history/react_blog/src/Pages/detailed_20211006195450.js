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

function Detailed(props) {
    // console.log(props.location.state)
    let markdown=`# css总结
    ###### 分类及位置：内部样式-head区域style标签里面
    1. 外部样式-link调用	
    2. 内联样式-标签元素里面
    ###### css样式表的语法
    - CSS规则由两个主要的部分构成：要添加样式的盒子名或者标签名、和要添加的样式。
    ###### css颜色
    1. 用十六进制的颜色值表示(红、绿、蓝)
     #FF0000或者#F00
    2. 用rgb(r,g,b)函数表示
    如：rgb(255,255,0)
    
    3. 用rgba(r,g,b,a)函数表示
    
    > 其中a表示的是改颜色的透明度，取值范围是0~1，其中0代表完全透明
    
    ###### 样式的优先级
    相同权值情况下，CSS样式的优先级总结来说，就是——就近原则（离被设置元素越近优先级别越高）：
    ` 内联样式表（标签内部）` > `嵌入样式表（当前文件中）`>` 外部样式表（外部文件中）`
    
    ###### 伪类选择器
    ` a:link {color:#FF0000;}` 未访问的链接 (只用于a标签）
    `a:visited {color:#00FF00;}` 已访问的链接 （只用于a标签）
    `a:hover {color:#FF00FF;}` 鼠标移动到链接上可和其他标签结合一起用）
    ` a:active {color:#0000FF;} ` 选定的链接
    注意
    伪类选择器的排序很重要
    
    > a:link a:visited a:hover a:active，记作lvha
    ###### block（块）元素的特点:
    1. 总是在新行上开始；
    2. 高度，行高以及外边距和内边距都可控制；
    3. 宽度缺省是它的容器的100%，除非设定一个宽度。
    4. 它可以容纳内联元素和其他块元素
    ###### inline元素的特点
    
    1. 和其他元素都在一行上；
    2. 高，行高及外边距和内边距不可改变；
    3. 宽度就是它的文字或图片的宽度，不可改变
    4. 内联元素只能容纳文本或者其他内联元素
    ###### margin合并
    
    ###### 定位
    ` static静态定位`（不对它的位置进行改变，在哪里就在那里）
    
    > 默认值。没有定位，元素出现在正常的流中（忽略 top,bottom, left, right 或者 z-index 声明）。
    
    ` fixed固定定位`（参照物–浏览器窗口）—做 弹窗广告用到
    
    > 生成固定定位的元素，相对于浏览器窗口进行定位。 元素的位置通过 "left", "top", "right"以及
    > "bottom"属性进行规定。
    
    ` relative（相对定位 ）`（参照物以他本身）
    
    > 生成相对定位的元素，相对于其正常位置进行定位。
    
    ` absolute`（绝对定位）(除了static都可以，找到参照物–>与它最近的已经有定位的父元素进行定位)
    
    > 生成绝对定位的元素，相对于 static 定位以外的第一个父元素进行定位。 元素的位置通过 “left", "top", "right"
    > 以及 "bottom" 属性进行规定
    
    `z-index`
    
    > z-index 属性设置元素的堆叠顺序。拥有更高堆叠顺序的元素总是会处于堆叠顺序较低的元素的前面。 定位的基本思想:
    > 它允许你定义元素框相对于其正常位置应该出现的位置，或者相对于父元素、另一个元素甚至浏览器窗口本身的位置。
    
    - 一切皆为框
    
    1. 块级元素: div、h1或p元素 即：显示为一块内容称之为 “块框“ ;
    2. 行内元素: span,strong,a等元素 即：内容显示在行中称 “行内框”;
    3. 使用display属性改变成框的类型 即：display:block; 让行内元素设置为块级元素，display:none; 没有框
    
    `相对定位`：
    1. 如果对一个元素进行相对定位，它将出现在它所在的位置上。
    2. 通过设置垂直或水平位置，让这个元素“相对于”它的起点进行移动
    .adv_relative { position: relative; left: 30px; top: 20px; }
    
    ` 绝对定位`：
    - 元素的位置相对于最近的已定位祖先元素，如果元素没有已定位 的祖先元素，它的位置相对于最初的包含块。 .adv_absolute { position: absolute; left: 30px; top: 20px; }
    
    ###### 浮动
    ` 解决问题：能够让多个块级元素在一行中显示。`
    
    > 浮动特点： 1、元素一旦浮动起来将不占页面空间，脱离文档流。
    > 2、元素浮动起来后，会停靠在父元素的左边或者右边，或停靠在其他已经浮动元素的边缘上。
    
    属性：float 取值
     1.   left：左浮动
    2. right：右浮动
    3. none：无浮动
    
    ###### 清除浮动
    
    > 清除浮动主要是为了解决，父元素因为子级元素浮动引起的内部高度为0的问题
    
    1. ` 额外标签法（在最后一个浮动标签后，新加一个标签，给其设置clear：both；）`
    
    > 
    
    2.` BFC`
     例：父级添加overflow属性（父元素添加overflow:hidden）
    
    > 通过触发BFC方式，实现清除浮动
    > 但内容增多的时候容易造成不会自动换行导致内容被隐藏掉，无法显示要溢出的元素
    
    3. `使用after伪元素清除浮动`
    
    ```css
        .clearfix:after{/*伪元素是行内元素 正常浏览器清除浮动方法*/
            content: "";
            display: block;
            height: 0;
            clear:both;
            visibility: hidden;
        }
    
    ```
    `+
    '# P01:课程介绍和环境搭建\n' +
    '[ **M** ] arkdown + E [ **ditor** ] = **Mditor**  \n' +
    '> Mditor 是一个简洁、易于集成、方便扩展、期望舒服的编写 markdown 的编辑器，仅此而已... \n\n' +
    '**这是加粗的文字**\n\n' +
    '*这是倾斜的文字*`\n\n' +
    '***这是斜体加粗的文字***\n\n' +
    '~~这是加删除线的文字~~ \n\n'+
    '\`console.log(111)\` \n\n'+
    '# p02:来个Hello World 初始Vue3.0\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n'+
    '***\n\n\n' +
    '# p03:Vue3.0基础知识讲解\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n\n'+
    '# p04:Vue3.0基础知识讲解\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n\n'+
    '#5 p05:Vue3.0基础知识讲解\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n\n'+
    '# p06:Vue3.0基础知识讲解\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n\n'+
    '# p07:Vue3.0基础知识讲解\n' +
    '> aaaaaaaaa\n' +
    '>> bbbbbbbbb\n' +
    '>>> cccccccccc\n\n'+
    '``` var a=11; ```'


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
