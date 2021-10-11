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
    let markdown='
    ## HTML链接
    #### HTML 链接`<a>`
    HTML 链接是通过标签 <a> 来定义的.
    ```css
    <a href="https://www.baidu.com">这是一个链接</a>
    ```
    #### HTML 链接 - target 属性
    使用 target 属性，你可以定义被链接的文档在何处显示。
    下面的这行会在新窗口打开文档：
    
    ```css
    <a href="https://www.baidu.com/" target="_blank" rel="noopener noreferrer">访问
    ```
    ## HTML 图像
    #### 图像标签（ img）和源属性src
    在 HTML 中，图像由 标签定义。
    img 是空标签，意思是说，它只包含属性，并且没有闭合标签。
    要在页面上显示图像，你需要使用源属性（src）。src 指 “source”。源属性的值是图像的 URL 地址。
    
    ```css
    <img src="url" alt="some_text">
    ```
    #### HTML 图像- Alt属性
    alt 属性用来为图像定义一串预备的可替换的文本。
    替换文本属性的值是用户定义的,在浏览器无法载入图像时，替换文本属性告诉读者她们失去的信息
    ```css
    <img src="" alt="Pulpit rock" width="304" height="228">
    ```
    
    1
    假如某个 HTML 文件包含十个图像，那么为了正确显示这个页面，需要加载 11 个文件。加载图片是需要时间的，所以我们的建议是：慎用图片。
    注意: 加载页面时，要注意插入页面图像的路径，如果不能正确设置图像的位置，浏览器无法加载图片，图像标签就会显示一个破碎的图片。
    ## HTML 列表
    #### 有序列表
    
    ```css
    <ol >
        <li> 烤冷面</li>
        <li> 煎饼果子</li>
        <li> 麻辣烫</li>
    </ol>
    
    ```
    #### 无序列表
    
    ```css
    <ul >
        <li> 烤冷面</li>
        <li> 煎饼果子</li>
        <li> 麻辣烫</li>
    </ul>
    ```
    #### 去掉列表前的符号圆圈和数字
    
    ```css
    /* 去掉a底下的横线 */
    a {
        text-decoration-line: none;
    }
    ol,
    ul {
        list-style: none;
    }
    ```
    
    ## HTML表格
    表格由标签来定义。每个表格均有若干行（由 标签定义），每行被分割为若干单元格（由
    标签定义）。字母 td 指表格数据（table data），即数据单元格的内容。数据单元格可以包含文本、图片、列表、段落、表单、水平线、表格等等。
    
    ```css
        <table align="center" border="1" cellpadding="8" cellspacing="0">
            <tr>
                <th>Header 1</th>
                <th>Header 2</th>
            </tr>
            <tr>
                <td colspan="2" align="center">row 1, cell 1</td>
            </tr>
            <tr>
                <td>row 2, cell 1</td>
                <td>row 2, cell 2</td>
            </tr>
        </table>
    ```
    
    > table border="1"  ` 边框`
    > cellpadding="8" ` 代表单元格边框到内容之间的距离（留白）`
    > cellspacing="0" ` 用来指定表格各单元格之间的空隙。此属性的参数值是数字，表示单元格间隙所占的像素点数。`
    > align="center" ` 表单居中 `
    > rowspan="2" `竖直方向占两个格子`
    > colspan="2" ` 水平方向占两个格子 `
    
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/2021012314311488.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzUyMjczMjM0,size_16,color_FFFFFF,t_70 )
    
    ## HTML 表单和输入
    HTML 表单
    表单是一个包含表单元素的区域。
    
    表单元素是允许用户在表单中输入内容,比如：文本域(textarea)、下拉列表、单选框(radio-buttons)、复选框(checkboxes)等等。
    
    表单使用表单标签 来设置:
    
    ```css
    <form>
    .
    input 元素
    .
    </form>
    
    ```
    #### HTML 表单 - 输入元素
    多数情况下被用到的表单标签是输入标签（）。
    
    文本域（Text Fields）
    输入类型是由类型属性（type）定义的。
    
    ```css
    <form align="center">
        <input type="text" placeholder="仅允许输入数字"></td>
        <br>
        <input type="text">
        <br>
        <input type="password">
    </form>
    ```
    
    > placeholder属性 ` 对用户做一个对输入内容的提醒或者指引`
    > password ` 密码框`
    
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210123144307549.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzUyMjczMjM0,size_16,color_FFFFFF,t_70)
    #### 单选按钮（Radio Buttons）
    标签定义了表单单选框选项
    
    ```css
    <form>
        <input type="radio" value="前端" name="sex">前端<br>
        <input type="radio" value="后台" name="sex" checked>后台<br>
        <input type="radio" value="全栈" name="sex">全栈
    </form>
    ```
    ![style="weight=50px"](https://img-blog.csdnimg.cn/20210123145547709.png)
    #### 复选框（Checkboxes）
    定义了复选框. 用户需要从若干给定的选择中选取一个或若干选项。
    
    ```css
    <form>
    <input type="checkbox" name="vehicle" value="Bike">I have a bike<br>
    <input type="checkbox" name="vehicle" value="Car">I have a car 
    </form>
    
    ```
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210123150028556.png)
    提交按钮(Submit Button)
    定义了提交按钮.
    
    当用户单击确认按钮时，表单的内容会被传送到另一个文件。表单的动作属性定义了目的文件的文件名。由动作属性定义的这个文件通常会对接收到的输入数据进行相关的处理
    
    ```css
        <form name="input" action="html_form_action.php" method="get">
            Username: <input type="text" name="user">
            <input type="submit" value="Submit">
            <button type="submit">提交</button>
            <button>重置</button>
        </form>
    ```
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210123150437276.png)
    #### 选择
    
    ```css
    <select name="" style="height: 50px; width: 200px;">
    <option value="--请选择政治面貌--">--请选择政治面貌</option>
        <option value="群众">群众</option>
        <option value="共青党员">共青党员</option>
        <option value="党员">党员</option>
    </select>
    ```
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210123151023152.png)
    ####  定义一个多行的文本输入控件
    可自己调节大小
    
    ```css
     <textarea cols="60" rows="1"></textarea>
    ```
    
    > cols 	` 文本区域内可见的列数（值：number）`
    > rows ` 本区域内可见的行数（值：number） `'


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
