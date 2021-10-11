const guanzhu = document.getElementsByClassName('guanzhu')[0];
const cityAll = document.getElementsByClassName('cityAll')[0];
const pos = document.getElementById('pos')
const cityInput = document.getElementById('city')
const search1 = document.getElementById('search1')
const search = document.getElementById('search')
const his = document.getElementById('cityhistory')
const canvas = document.getElementById('myCanvas')
const ctx = canvas.getContext("2d");
ctx.fillStyle = 'rgba(255, 255, 255, 0)'
const del = document.getElementById('btn_clean')
const delList = document.getElementById('city_history')

//jsonp跨域请求
function cb(data) {
    update(data.data)
    // updataCon()
}
function addScriptTag(src) {
    let lastscript = document.querySelector('.newscript');
    if (lastscript) {
        document.body.removeChild(lastscript);
    }
    let script = document.createElement('script');
    script.src = src;
    script.className = 'newscript';
    document.body.appendChild(script);
}

//设置记录清除
del.addEventListener('mousedown', () => {
    delList.style.display = 'none'
    localStorage.removeItem("historys");
})

let saveCity;
let historys;
//一开始地址默认陕西 西安
getData(`陕西`, `西安`)

//关注保存 
//historys刚开始为空
if (typeof (localStorage) !== "undefined") {
    // saveCity = (JSON.parse(localStorage.getItem('saveCity')) || [])
    // saveCity.filter(item => {
    //     if (pos.innerHTML === item) {
    //         guanzhu.innerHTML = `[已关注]`
    //     }
    // })
    historys = (JSON.parse(localStorage.getItem('historys')) || [])
    if (historys === '[]') {
        delList.style.display = 'none'
    }
} else {
    console.log("Sorry, your browser does not support Web Storage...");
}

//点击关注进行保存
guanzhu.addEventListener('click', () => {
    const pos_data = document.querySelector('#pos>.pos_data')
    if (guanzhu.innerHTML === `[添加关注]`) {
        saveCity = (JSON.parse(localStorage.getItem('savecity')) || [])
        let data_county = pos_data.attributes['data-county'] ? pos_data.attributes['data-county'].value : ''
        saveCity.push({ data_province: pos_data.attributes['data-province'].value, data_city: pos_data.attributes['data-city'].value, data_county: data_county})
        localStorage.setItem(`savecity`, JSON.stringify(saveCity))
    }
    guanzhu.innerHTML = `[已关注]`
})

search.addEventListener('focus', function () {
    cityInput.style.display = 'block'
})

search.addEventListener('blur', function () {
    cityInput.style.display = 'none'
    cityAll.style.display = 'none'
    search.value = ''
})

//热门城市绑定点击事件 数据同步更新
const hotCity = document.querySelectorAll('#hot-city>li')
cityCilck(hotCity)


//通过地址发送请求 得到数据 调用更新数据
function getData(a, b, c = '') {
    historys = (JSON.parse(localStorage.getItem('historys')) || [])
    historys = [{ data_province: a, data_city: b, data_county: c }, ...historys.filter(({ data_city }) => data_city !== b)].slice(0, 4)
    localStorage.setItem(`historys`, JSON.stringify(historys))

    //在dom中更新history
    his.innerHTML = ""
    historys.forEach((item, i) => {
        his.innerHTML += `<li class="top_right" data-province=${historys[i].data_province} data-city=${historys[i].data_city} data-county=${historys[i].data_county}>${historys[i].data_city}</li>`
    })
    const historyEle = document.querySelectorAll('#cityhistory>.top_right')
    cityCilck(historyEle)


    saveCity = (JSON.parse(localStorage.getItem('savecity')) || [])
    console.log(saveCity)
    let city_result = saveCity.some(item => {
        item.data_city.trim() === b.trim() && item.data_province.trim() === a.trim()
        console.log(item.data_city.trim() === b.trim(),item.data_city.trim())
        console.log(item.data_province.trim() === a.trim(),item.data_province.trim())
    })
    console.log(city_result)
    if(city_result) guanzhu.innerHTML = `[已关注]` 
    else {guanzhu.innerHTML = `[添加关注]`}

    addScriptTag(`https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=${a}&city=${b}&county=${c}&callback=cb`);
}
//搜索绑定事件 回车搜索出所有城市
search.addEventListener('keydown', function (e, v) {
    cityInput.style.display = 'none'
    if (e.keyCode === 13) {
        addScriptTag(`https://wis.qq.com/city/like?source=pc&city=${search.value}&callback=citycb`);
    }
})
//获取具体城市 
//1. 根据获取到的城市数据进行更新
//2. 生成block 显示出来的城市
//3. 为显示出来的数据绑定点击事件 搜索天气并更新
function citycb(data) {
    choose_city(data.data)
    choose_click()
}

function update(data) {
    //当天数据更新
    let data_today = [...document.getElementsByClassName("data_today")]
    const winds_arr = ['微风', '东北风', '东风', '东南风', '南风', '西南风', '西风', '西北风', '北风']
    const today_weatherCode = document.getElementsByClassName("today_weatherCode")[0]

    const dayTime = `${data.observe.update_time}`
    const today_data = [`中央气象台${dayTime.slice(8, 10)}:${dayTime.slice(10, 12)}发布`, `${data.observe.degree}°`, `${data.observe.weather}`, `${winds_arr[data.observe.wind_direction]} ${data.observe.wind_power}级`, `湿度 ${data.observe.humidity}%`, `气压 ${data.observe.pressure}hPa`]
    data_today.forEach((item, i) => {
        item.innerHTML = today_data[i]
    })
    today_weatherCode.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/currentweather/night/${data.observe.weather_code}.png)`

    if (`${data.limit.tail_number}` !== '不限行') {
        data_today[6].innerHTML = `限行 ${data.limit.tail_number}`
    } else {
        const car_pic = document.getElementById('car_pic')
        data_today[6].style.display = 'none'
        car_pic.style.display = 'none'
    }

    //逐小时天气预报
    const hoursListEle = document.getElementsByClassName('hour_data_list')[0]
    hoursListEle.innerHTML = ""

    //判断日落日出时间为当天还是下一天
    let srTime, ssTime, myDate = new Date()
    let sunrise = data.rise[0].sunrise
    if ((parseInt(myDate.getHours()) - parseInt(sunrise.slice(0, 2))) <= 1) {
        srTime = data.rise[0].sunrise
    } else {
        srTime = data.rise[1].sunrise
    }
    let sunset = data.rise[0].sunset
    if ((parseInt(myDate.getHours()) - parseInt(sunset.slice(0, 2))) <= 1) {
        ssTime = data.rise[0].sunset
    } else {
        ssTime = data.rise[1].sunset
    }
    //生成24h天气 并将日出日落插入
    for (let i = 0; i <= 23; i++) {
        let hourDatatime = data.forecast_1h[i].update_time
        if (parseInt(hourDatatime.slice(8, 10)) - parseInt(srTime) === 1) {
            hours_innerhtml(hoursListEle, srTime, `rise`, `日出`)
        }
        if ((parseInt(hourDatatime.slice(8, 10) - parseInt(ssTime))) === 1) {
            hours_innerhtml(hoursListEle, ssTime, `set`, `日落`)
        }
        hours_innerhtml(hoursListEle, `${hourDatatime.slice(8, 10)}:${hourDatatime.slice(11, 13)}`, `night/${data.forecast_1h[i].weather_code}`, `${data.forecast_1h[i].degree}°`)
    }
    // hours_data.appendChild(hoursListEle)
    // 左右键绑定click事件
    const btn_l1 = document.getElementsByClassName('btn_l')
    const btn_r1 = document.getElementsByClassName('btn_r')
    btn_r1[0].addEventListener('click',() => btnFunr(hoursListEle))
    btn_l1[0].addEventListener('click',() => btnFunl(hoursListEle))

    //7天天气预报 上 forecast_24h
    const dats7_top = document.getElementsByClassName("dats7_top")[0]
    dats7_top.innerHTML = ""
    for (let i = 0; i <= 7; i++) {
        let time1 = time
        if (i === 0) {
            time1 = `昨天`
        } else if (i === 1) {
            time1 = `今天`
        } else { time1 = `${getMyDay(new Date(data.forecast_24h[i].time))}` }
        dats7_top.innerHTML +=
            `<div class="days_top">
                    <p class="days_top_time1">${time1}</p>
                    <p class="days_top_time2">${data.forecast_24h[i].time.slice(5, 7)}月${data.forecast_24h[i].time.slice(8, 10)}日</p>
                    <p class="days_top_tianqi">${data.forecast_24h[i].day_weather}</p>
                    <div class="days_top_pic" style="background-image: url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/${data.forecast_24h[i].day_weather_code}.png);"></div>
                </div> `
    }

    //7天天气预报 下 forecast_24h
    const dats7_bottom = document.getElementsByClassName("days7_footer")[0]
    dats7_bottom.innerHTML = ""
    for (let i = 0; i <= 7; i++) {
        dats7_bottom.innerHTML +=
            `<div class="days_footer">
                <div class="days_footer_pic" style="background-image: url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/${data.forecast_24h[i].night_weather_code}.png);"></div>
                <p class="days_footer_tianqi">${data.forecast_24h[i].night_weather}</p>
                <p class="days_footer_wind">${data.forecast_24h[i].night_wind_direction} ${data.forecast_24h[i].night_wind_power}级</p>
            </div>`
    }

    //生活指数
    const lifePic = [`-80px -37px`, `1px -150px`, `-150px -72px`, `-117px -74px`, `-70px -154px`, `-154px -111px`, `-150px -37px`, `-150px 2px`, `-37px -43px`, `0px -40px`, `-32px -113px`, `-74px -78px`]
    const lifeText = [`穿衣 舒适`, `雨伞 不打伞`, `钓鱼 较适宜`, `旅游 适宜`, `感冒 极易发`, `洗车较适宜`, `交通 良好`, `空气污染扩散条件`, `运动 适宜`, `防晒 中等`, `舒适度 舒适`, `晾晒`]
    const mRM = document.getElementsByClassName("m_r_m")[0]
    // const ul_list = document.createElement('ul')
    // ul_list.classList.add('m_r_m_list')
    const ul_list = document.getElementsByClassName('m_r_m_list')[0]
    ul_list.innerHTML = ""
    for (let i = 0; i <= 11; i++) {
        ul_list.innerHTML +=
            `<li class="m_r_m_one">
                <div class="m_r_m_1">
                    <div class="m_r_m_pic" style="background-position: ${lifePic[i]};"></div>
                    <p class="m_r_m_title">${lifeText[i]}</p>
                    <div class="m_r_m_text">
                        天气较好，赶快投身大自然参与户外运动，尽情感受运动的快乐吧。
                    </div>
                </div>
            </li>`
    }
    mRM.appendChild(ul_list)
    //左右点击事件
    ul_list.style.left = `0px`
    btn_r1[1].addEventListener('click',() => btnFunr(ul_list))
    btn_l1[1].addEventListener('click', () => btnFunl(ul_list))

    //7天天气预报中
    const maxDegree = Object.values(data.forecast_24h).map((item) => {return parseInt(item.max_degree)})
    const minDegree = Object.values(data.forecast_24h).map((item) => {return parseInt(item.min_degree)})
    console.log(maxDegree)
    console.log(minDegree)
    const minDegree = [Object.values(data.forecast_24h).map((item) => {return parseInt(item.min_degree)})]
    
    let max = Math.max.apply(Math,Object.values(data.forecast_24h).map((item) => {return parseInt(item.max_degree)}))
    let min = Math.min.apply(Math,Object.values(data.forecast_24h).map((item) => {return parseInt(item.min_degree)}))

    // let max = Math.max(...data.forecast_24h[i].max_degree.slice(0,7))
    // let max = -100, min = 100
    // for (let i = 0; i <= 7; i++) {
    //   
    //     maxDegree.push(data.forecast_24h[i].max_degree)
    //     minDegree.push(data.forecast_24h[i].min_degree)
    // }

    const unitY = ((200 - 60) / (max - min))
    const unitX = 30
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    draw(maxDegree,'rgb(252,192,112)',16,unitX,unitY,max)
    draw(minDegree,'rgb(148,204,249)',58,unitX,unitY,max)
}

//判断星期几
function getMyDay(date) {
    var week;
    if (date.getDay() == 0) week = "周日";
    if (date.getDay() == 1) week = "周一";
    if (date.getDay() == 2) week = "周二";
    if (date.getDay() == 3) week = "周三";
    if (date.getDay() == 4) week = "周四";
    if (date.getDay() == 5) week = "周五";
    if (date.getDay() == 6) week = "周六";
    return week;
}

function btnFunr(dom){
    if (parseInt(dom.style.left) + parseInt(dom.offsetWidth) > parseInt(dom.offsetWidth)/2) {
        dom.style.left = `${parseInt(dom.style.left) - parseInt(dom.offsetWidth)/2}px`//可以减
    } else {
        dom.style.left = `-${parseInt(dom.offsetWidth)/2}px`//最后点不了的时候
    }
}
function btnFunl(dom){
    if(parseInt(dom.style.left + parseInt(dom.offsetWidth) < parseInt((dom.offsetWidth)/2)))
        dom.style.left = `${parseInt(dom.style.left) + parseInt(dom.offsetWidth)/2}px`
    else dom.style.left = '0px'
}
//生成搜索出来的城市列表
function choose_city(result) {
    cityAll.innerHTML = ""
    result = Object.values(result)
    result.forEach((item,i) => {
        cityAll.innerHTML += `<p class="tit">${result[i]}</p>`
    })
    cityAll.style.display = 'block'
}

function choose_click() {
    let input = document.getElementById('search')
    let cityAll = document.querySelector('.cityAll')
    let p = document.querySelectorAll('.cityAll>p')
    p.forEach((item, index) => {
        item.addEventListener('mousedown', () => {
            cityAll.style.display = 'none'
            input.value = ""
            cityAll.innerHTML = ""
            let cityStr = item.innerHTML.split(',')
            if (cityStr.length === 2) {
                getData(cityStr[0], cityStr[1])
                if (cityStr[0].trim() === cityStr[1].trim()) pos.innerHTML = `<p data-province = ${cityStr[0]} data-city=${cityStr[1]}} class="pos_data">${cityStr[1]}</p>`
                else pos.innerHTML = `<p data-province = ${cityStr[0]} data-city=${cityStr[1]} class="pos_data">${cityStr[0]} ${cityStr[1]}</p>`
            } else if (cityStr.length === 3) {
                getData(cityStr[0], cityStr[1], cityStr[2])
                pos.innerHTML = `<p data-county = ${cityStr[2]} data-province = ${cityStr[0]} data-city=${cityStr[1]} class="pos_data">${cityStr[1]} ${cityStr[2]}</p>`
            }
        })
    })
}

//在dom中更新关注
// function saveCitys(data) {
    // citysaveCity.innerHTML += `<li class="itemcity" data-province="陕西省" data-city="西安市" data-district="">
                                //     <div class="ct-location">
                                //         <p class="location">西安市</p>
                                //         <a href="javascript:;" class="btnMR">设为默认</a>
                                //     </div>
                                //         <img class="icon" src="https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/01.png" alt="多云" title="多云">
                                //         <p class="weather">多云转小雨</p>
                                //         <p class="temperature">19°/25°</p>
                                //         <a href="javascript:;" class="btn btn-delete"></a>
                                // </li>`
// }

// function updataCon() {
//     saveCity = (JSON.parse(localStorage.getItem('saveCity')) || [])
//     const citysaveCity = document.getElementById('citysaveCity')
//     citysaveCity.innerHTML = ""
//     if (saveCity.length === 0) { citysaveCity.innerHTML = `<li id="city_saveCity">点击“添加关注”添加城市哟~</li>` }
//     else {
//         saveCity.forEach(item => {
//             // addScriptTag(`https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=${item.data_province}&city=${item.data_city}&county=${item.data_county}&callback=saveCitys`);
//             // console.log(item.data_province,item.data_city)
//             addScriptTag(`https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=${item.data_province}&city=${item.data_city}&callback=saveCitys`);
//         })
//     }
// }

//画圆
function drawcir(left, top, color) {
    ctx.beginPath();
    ctx.strokeStyle = 'red'
    ctx.arc(left, top, 4, 0, 2 * Math.PI);
    ctx.fillStyle = color;
    ctx.fill();

}
//写字
function dirText(size, text, left, top, color) {
    ctx.beginPath();
    // ctx.fillStyle = 'rgb(56,76,120)'
    ctx.fillStyle = color
    ctx.font = `${size} Arial`;
    ctx.fillText(text, left, top);
    ctx.stroke();
}
//划线
function drawline(startx, stary, endx, endy, color) {
    ctx.beginPath();
    ctx.strokeStyle = color;
    ctx.lineWidth = 3
    ctx.moveTo(startx, stary);
    ctx.lineTo(endx, endy);
    ctx.stroke();
}
//24h小时天气
function hours_innerhtml(dom, time, pic, text) {
    dom.innerHTML +=
        `<li class="hour_data">
            <p class="hour_data_time">${time}</p>
            <div class="hour_data_pic" style="background-image: url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/${pic}.png)"></div>
            <p class="hour_data_degree">${text}</p>
        </li>`
}

//判断pos显示两个还是一个 还有三个参数时的判断
function judgeCity(dom) {
    if (dom.attributes['data-province'].value === dom.attributes['data-city'].value) {
        pos.innerHTML = `<p data-province = ${dom.attributes['data-province'].value} data-city=${dom.attributes['data-city'].value}} class="pos_data">${dom.attributes['data-city'].value}</p>`
    } else if(dom.attributes['data-county']){
        pos.innerHTML = `<p data-province = ${dom.attributes['data-province'].value} data-city=${dom.attributes['data-city'].value} data-county = ${dom.attributes['data-county'].value} class="pos_data">  ${dom.attributes['data-city'].value} ${dom.attributes['data-county'].value}</p>`
    }else{
        pos.innerHTML = `<p data-province = ${dom.attributes['data-province'].value} data-city=${dom.attributes['data-city'].value}} class="pos_data">${dom.attributes['data-province'].value} ${dom.attributes['data-city'].value}</p>`
    }
}

//给搜索底下的城市加上点击事件
function cityCilck(dom){
    dom.forEach(function (item) {
        item.addEventListener('mousedown', () => {
            //判断province是否和city相同
            judgeCity(item)
            cityInput.style.display = 'none'
            let country = item.attributes['data-county'] ? item.attributes['data-county'].value : ''
            getData(item.attributes['data-province'].value, item.attributes['data-city'].value,)
        })
    })
}
function draw(arrDegree,color,height,unitX,unitY,max){
    for (let i = 0; i <= 7; i++) {
        drawcir(unitX + 90 * i, (arrDegree[i] - max) * unitY * (-1) + 30, color)
        if (i === 0) {
            dirText(`19px`, `${arrDegree[i]}°`, (unitX + 90 * i - 10), (arrDegree[i] - max) * unitY * (-1) + height, "rgb(194,194,194)")
        } else {
            dirText(`19px`, `${arrDegree[i]}°`, (unitX + 90 * i - 10), (arrDegree[i] - max) * unitY * (-1) + height, "rgb(56,76,120)")
        }
        if (i < 7) {
            drawline(unitX + 90 * i, (arrDegree[i] - max) * unitY * (-1) + 30, unitX + 90 * (i + 1), (arrDegree[i + 1] - max) * unitY * (-1) + 30, color)
        }
    }
}