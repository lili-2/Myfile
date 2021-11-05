const mysql = require("mysql")
const dbConfig = require('../db/DBConfig')
const userSQL = require('../db/usersql')

const pool = mysql.createPool(dbConfig.mysql)
//获取
exports.getAllArticle = (req, res, next) => {
    pool.getConnection((err, connection) => {
        if (err) console.log(err)
        connection.query(userSQL.findAllAriticle, [], function (err, data) {
            if (err) {
                console.log(err)
            }
            res.json({
                'code': 200,
                'data': data,
                'message': 'success'
            });
            connection.release();
        });
    });
}
exports.getOneArticle = (req, res, next) => {
    const id = req.query.id
    pool.getConnection((err, connection) => {
        if (err) console.log(err)
        connection.query(userSQL.findOneAriticle, [id], function (err, data) {
            if (err) {
                console.log(err)
            }
            res.json({
                'code': 200,
                'data': data,
                'message': 'success'
            });
            connection.release();
        });
    });
}
exports.insertArticle = (req, res, next) => {
    const { title, content } = req.body
    pool.getConnection((err, connection) => {
        if (err) console.log(err)
        connection.query(userSQL.insertArticle, [title, content], function (err, data) {
            if (err) {
                console.log(err)
            }
            res.json({
                'code': 200,
                'data': data,
                'message': 'success'
            });
            connection.release();
        });
    });
}
exports.deleteArticle = (req, res, next) => {
    const id = req.query.id
    pool.getConnection((err, connection) => {
        if (err) console.log(err)
        connection.query(userSQL.deleteArticle, [id], function (err, data) {
            if (err) {
                console.log(err)
            }
            res.json({
                'code': 200,
                'data': data,
                'message': 'success'
            });
            connection.release();
        });
    });
}
exports.searchArticle = (req, res, next) => {
    const searchReq = req.query.searchReq
    pool.getConnection((err, connection) => {
        if (err) console.log(err)
        connection.query(userSQL.searchArticle, [`%${searchReq}%`,`%${searchReq}%`], function (err, data) {
            if (err) {
                console.log(err)
            }
            res.json({
                'code': 200,
                'data': data,
                'message': 'success'
            });
            connection.release();
        });
    });
}