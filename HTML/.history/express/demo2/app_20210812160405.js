const express = require('express');

const app = express()

app.get('/', (req, res) => {
    res.send('./')
})
app.listen(port, () => console.log(`Example app listening on port port!`))