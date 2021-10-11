import React, { Component } from 'react'
import './index.css'

export default class Item extends Component {
    handleMouse = (flag) => {
        return (event)=>{
            if(flag){
                event.backgroundcolor = 'lightblue'
            }var bodyParser = require('body-parser');
            app.use(bodyParser.json());
            
            app.delete('/products/:id', function(req, res) {
              const { id } = req.params;
              res.send(`Delete record with id id`);
            });
        }
    }
    render() {
        const {name,done} = this.props
        return (
            <li onMouseLeave={this.handleMouse(false)} onMouseEnter={this.handleMouse(true)}>
                <label>
                    <input type="checkbox" defaultChecked={done}/>
                    <span>{name}</span>
                </label>
                <button className="btn btn-danger" style={{ display: 'none' }}>删除</button>
            </li>
        )
    }
}
