window.onload = function () {
    const guanzhu = document.getElementsByClassName('guanzhu')[0];
    const cityAll = document.getElementsByClassName('cityAll')[0];
    const pos = document.getElementById('pos')
    const cityInput = document.getElementById('city')
    const search1 = document.getElementById('search1')
    const search = document.getElementById('search')
    const his = document.getElementById('cityhistory')
    const canvas = document.getElementById('myCanvas')
    const ctx = canvas.getContext("2d");
    const del = document.getElementById('btn_clean')
    const delList = document.getElementById('city_history')

    //设置记录清除
    del.addEventListener('click',() => {
        delList.style.display = 'none'
        localStorage.removeItem("history");
    })

    var concern;
    var history;
    //一开始地址默认陕西 西安
    getData(`陕西`, `西安`)

    //关注保存 history刚开始为空
    if (typeof (localStorage) !== "undefined") {
        concern = (JSON.parse(localStorage.getItem('saveCity')) || [])
        concern.filter(item => {
            if (pos.innerHTML === item) {
                guanzhu.innerHTML = `[已关注]`
            }
        })
        history = (JSON.parse(localStorage.getItem('history')) || [])
        if(history === '[]'){
            delList.style.display = 'none'
        }
    } else {
        console.log("Sorry, your browser does not support Web Storage...");
    }

    //点击关注进行保存
    guanzhu.addEventListener('click', () => {
        if (guanzhu.innerHTML === `[添加关注]`){
            saveCity(pos.innerHTML)
        }
        guanzhu.innerHTML = `[已关注]`
    })

    //保存到saveCity中
    function saveCity(value) {
        concern.push(value)
        localStorage.setItem(`saveCity`, JSON.stringify(concern));
    }


    search.addEventListener('focus',function(){ 
        cityInput.style.display = 'block'
    })
    search.addEventListener('blur',function(){
        cityInput.style.display = 'none'
        cityAll.style.display = 'none'
        console.log(search.)
        search.innerHTML = ''
    })

    //热门城市绑定点击事件 数据同步更新
    const hotCity = document.querySelectorAll('#hot-city>li')
        hotCity.forEach(function (i) {
        i.addEventListener('mousedown', function () {
            if(this.attributes['data-province'].value === this.attributes['data-city'].value){
                pos.innerHTML = `${this.attributes['data-city'].value}`
            }else{
                pos.innerHTML = `${this.attributes['data-province'].value} ${this.attributes['data-city'].value}`
            }
            cityInput.style.display = 'none'
            getData(this.attributes['data-province'].value, this.attributes['data-city'].value)
        })
    })
    
    //通过地址发送请求 得到数据 调用更新数据
    function getData(a, b, c = '') {
        history = (JSON.parse(localStorage.getItem('history')) || [])
        if (history.length === 0) {saveHistory(history, a, b, c);}
        let flag = true;
        history.forEach((item) => {
            if (item.data_province === a && item.data_city === b && item.data_county === c) {
                flag = false;
            };
        })
        if (flag === true) {
            saveHistory(history, a, b, c)
        }
        concern = (JSON.parse(localStorage.getItem('saveCity')) || [])


        let updategz = concern.every(item => {
            return item !== pos.innerHTML
        })
        if(updategz === true){
            guanzhu.innerHTML = `[添加关注]`
        }else{
            guanzhu.innerHTML = `[已关注]`
        }

        $.ajax({
            url: `https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=${a}&city=${b}&county` + `=${c}`,
            type: "GET",
            dataType: "JSONP",
            success: function (data) {
                update(data.data)
                updataHis()
                updataCon(data.data)
            },
            error: function (error) { console.log(error) }
        });
    }

    //搜索绑定事件 回车搜索出所有城市
    search.addEventListener('keydown', function (e, v) {
        cityInput.style.display = 'none'
        if (e.keyCode === 13) {
            get_city(search.value)
        }
    })


    //获取具体城市 
    //1. 根据输入点击后获取城市数据
    //2. 生成block 显示出来的城市
    //3. 为显示出来的数据绑定点击事件 搜索天气并更新
    async function get_city(city, source = 'pc') {
        let result = await $.ajax({
            url: `https://wis.qq.com/city/like?source=${source}&city=${city}`,
            type: 'get',
            dataType: 'jsonp',
            success: function (res) { return res },
            error: function (error) { console.log(error) }
        });
        await choose_city(result.data)
        await choose_click()
    }


    function update(data) {
        //当天数据更新
        const data_today = document.getElementsByClassName("data_today")
        const winds_arr = ['微风', '东北风', '东风', '东南风', '南风', '西南风', '西风', '西北风', '北风']
        const today_weatherCode = document.getElementsByClassName("today_weatherCode")[0] 

        const dayTime = `${data.observe.update_time}`
        data_today[0].innerHTML = `中央气象台${dayTime.slice(8, 10)}:${dayTime.slice(10, 12)}发布`
        data_today[1].innerHTML = `${data.observe.degree}°`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[3].innerHTML = `${winds_arr[data.observe.wind_direction]} ${data.observe.wind_power}级`//wind_direction
        data_today[4].innerHTML = `湿度 ${data.observe.humidity}%`
        data_today[5].innerHTML = `气压 ${data.observe.pressure}hPa`
        today_weatherCode.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/currentweather/night/${data.observe.weather_code}.png)`

        if (`${data.limit.tail_number}` !== '不限行') {
            data_today[6].innerHTML = `限行 ${data.limit.tail_number}`
        } else {
            const car_pic = document.getElementById('car_pic')
            data_today[6].style.display = 'none'
            car_pic.style.display = 'none'
        }

        //逐小时天气预报
        const hour_data_time = document.getElementsByClassName("hour_data_time")
        const hours_data = document.getElementsByClassName('hours_data')[0]
        hours_data.innerHTML = ''
        //forecast_1h
        const hoursListEle = document.createElement('ul')
        hoursListEle.classList.add('hour_data_list')
        const timehour = []
        const minutes = []
        const element = []
        for (let i = -2; i <= 23; i++) {
            const hourEle = document.createElement('li')
            const hourDataTime = document.createElement('p')
            const hourDataPic = document.createElement('div')
            const hourDataDegree = document.createElement('p')

            hourEle.classList.add('hour_data')
            hourDataTime.classList.add('hour_data_time')
            hourDataPic.classList.add('hour_data_pic')
            hourDataDegree.classList.add('hour_data_degree')

            hourEle.appendChild(hourDataTime)
            hourEle.appendChild(hourDataPic)
            hourEle.appendChild(hourDataDegree)
            if (i === -2) {
                hourDataTime.innerHTML = `${data.rise[0].sunrise}`
                hourDataDegree.innerHTML = `日出`
                hourDataPic.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/rise.png)`
            }
            else if (i === -1) {
                hourDataTime.innerHTML = `${data.rise[0].sunset}`
                hourDataDegree.innerHTML = `日落`
                hourDataPic.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/set.png)`
            } else {
                const hourDatatime = data.forecast_1h[i].update_time
                timehour.push(hourDatatime.slice(8, 10))
                minutes.push(hourDatatime.slice(11, 13))
                hourDataTime.innerHTML = `${hourDatatime.slice(8, 10)}:${hourDatatime.slice(11, 13)}`
                hourDataDegree.innerHTML = `${data.forecast_1h[i].degree}°`
                hourDataPic.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/night/${data.forecast_1h[i].weather_code}.png)`
            }
            if(i < 0){
                // console.log(data.rise[0].sunrise.slice(0, 2))
                // console.log(data.rise[0].sunrise.slice(3, 4))
            }else{
                // console.log(timehour)
                hoursListEle.appendChild(hourEle)
            }
        }

        hours_data.appendChild(hoursListEle)

        // 左右键绑定click事件
        const btn_l1 = document.getElementsByClassName('btn_l')
        const btn_r1 = document.getElementsByClassName('btn_r')
        btn_r1[0].addEventListener('click', () => btn_r1Fun(hoursListEle))
        btn_l1[0].addEventListener('click', () => btn_l1Fun(hoursListEle))

        //7天天气预报 上 forecast_24h
        const dats7_top = document.getElementsByClassName("dats7_top")[0]
        const middle_daystop = document.createDocumentFragment()
        dats7_top.innerHTML = ""

        for (let i = 0; i <= 7; i++) {
            const days_top = document.createElement('div')
            days_top.classList.add('days_top')

            const days_top_time1 = document.createElement('p')
            const days_top_time2 = document.createElement('p')
            const days_top_tianqi = document.createElement('p')
            const days_top_pic = document.createElement('div')

            days_top_time1.classList.add('days_top_time1')
            days_top_time2.classList.add('days_top_time2')
            days_top_tianqi.classList.add('days_top_tianqi')
            days_top_pic.classList.add('days_top_pic')

            days_top.appendChild(days_top_time1)
            days_top.appendChild(days_top_time2)
            days_top.appendChild(days_top_tianqi)
            days_top.appendChild(days_top_pic)
            middle_daystop.appendChild(days_top)

            const time = `${data.forecast_24h[i].time}`
            const timeWeek = `${time}`
            if (i === 0) {
                days_top_time1.innerHTML = `昨天`
            } else if (i === 1) {
                days_top_time1.innerHTML = `今天`
            } else {
                days_top_time1.innerHTML = `${getMyDay(new Date(timeWeek))}`
            }
            days_top_time2.innerHTML = `${time.slice(5, 7)}月${time.slice(8, 10)}日`
            days_top_tianqi.innerHTML = `${data.forecast_24h[i].day_weather}`
            days_top_pic.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/${data.forecast_24h[i].day_weather_code}.png)`
        }
        dats7_top.appendChild(middle_daystop)

        //7天天气预报 下 forecast_24h
        const dats7_bottom = document.getElementsByClassName("days7_footer")[0]
        const middle_daysbottom = document.createDocumentFragment()
        dats7_bottom.innerHTML = ""
        for (let i = 0; i <= 7; i++) {
            const days_bottom = document.createElement('div')
            days_bottom.classList.add('days_footer')

            const days_bottom_pic = document.createElement('div')
            const days_bottom_tianqi = document.createElement('p')
            const days_bottom_wind = document.createElement('p')

            days_bottom_tianqi.classList.add('days_footer_tianqi')
            days_bottom_wind.classList.add('days_footer_wind')
            days_bottom_pic.classList.add('days_top_pic')

            days_bottom.appendChild(days_bottom_pic)
            days_bottom.appendChild(days_bottom_tianqi)
            days_bottom.appendChild(days_bottom_wind)
            middle_daysbottom.appendChild(days_bottom)

            days_bottom_pic.style.backgroundImage = `url(https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/night/${data.forecast_24h[i].night_weather_code}.png)`
            days_bottom_tianqi.innerHTML = `${data.forecast_24h[i].night_weather}`
            days_bottom_wind.innerHTML = `${data.forecast_24h[i].night_wind_direction} ${data.forecast_24h[i].night_wind_power}级`
        }
        dats7_bottom.appendChild(middle_daysbottom)

        //生活指数
        const lifePic = [`-80px -37px`, `1px -150px`, `-150px -72px`, `-117px -74px`, `-70px -154px`, `-154px -111px`, `-150px -37px`, `-150px 2px`, `-37px -43px`, `0px -40px`, `-32px -113px`, `-74px -78px`]
        const lifeText = [`穿衣 舒适`, `雨伞 不打伞`, `钓鱼 较适宜`, `旅游 适宜`, `感冒 极易发`, `洗车较适宜`, `交通 良好`, `空气污染扩散条件`, `运动 适宜`, `防晒 中等`, `舒适度 舒适`, `晾晒`]
        const mRM = document.getElementsByClassName("m_r_m")[0]
        const ul_list = document.createElement('ul')
        ul_list.classList.add('m_r_m_list')
        mRM.innerHTML = ""
        for (let i = 0; i <= 11; i++) {
            const ul_li = document.createElement('li')
            ul_li.classList.add('m_r_m_one')

            const ulLiDiv = document.createElement('div')
            ulLiDiv.classList.add('m_r_m_1')

            const ulLiDpic = document.createElement('div')
            ulLiDpic.classList.add('m_r_m_pic')
            const ulLiP = document.createElement('p')
            ulLiP.classList.add('m_r_m_title')
            const ulLiText = document.createElement('div')
            ulLiText.classList.add('m_r_m_text')

            ulLiDiv.appendChild(ulLiDpic)
            ulLiDiv.appendChild(ulLiP)
            ulLiDiv.appendChild(ulLiText)
            ul_li.appendChild(ulLiDiv)

            ulLiText.innerHTML = '天气较好，赶快投身大自然参与户外运动，尽情感受运动的快乐吧。'
            ulLiP.innerHTML = `${lifeText[i]}`
            ulLiDpic.style.backgroundPosition = `${lifePic[i]}`
            ul_list.appendChild(ul_li)
            //     days_bottom_pic.innerHTML = `${data.forecast_24h[i].night_weather_code}`
            //     days_bottom_tianqi.innerHTML = `${data.forecast_24h[i].night_weather}`
            //     days_bottom_wind.innerHTML = `${data.forecast_24h[i].night_wind_direction} ${data.forecast_24h[i].night_wind_power}级`
        }
        mRM.appendChild(ul_list)
        //左右点击事件
        ul_list.style.left = `0px`
        btn_r1[1].addEventListener('click', () => btn_r2Fun(ul_list))
        btn_l1[1].addEventListener('click', () => btn_l2Fun(ul_list))

        //7天天气预报中
        const maxDegree = []
        const minDegree = []
        let max = -100, min = 100
        for (let i = 0; i <= 7; i++) {
            if (parseInt(data.forecast_24h[i].max_degree) > max) {
                max = parseInt(data.forecast_24h[i].max_degree)
            }
            if (parseInt(data.forecast_24h[i].min_degree) < min) {
                min = parseInt(data.forecast_24h[i].min_degree)
            }
            maxDegree.push(data.forecast_24h[i].max_degree)
            minDegree.push(data.forecast_24h[i].min_degree)
        }

        const unitY = ((200 - 60) / (max - min))
        const unitX = 30

        ctx.clearRect(0, 0, canvas.width, canvas.height)

        for (let i = 0; i <= 7; i++) {
            drawcir(unitX + 90 * i, (maxDegree[i] - max) * unitY * (-1) + 30, 'red')
            dirText(`20px`, `${maxDegree[i]}°`, (unitX + 90 * i - 10), (maxDegree[i] - max) * unitY * (-1) + 15)
            if (i < 7) {
                drawline(unitX + 90 * i, (maxDegree[i] - max) * unitY * (-1) + 30, unitX + 90 * (i + 1), (maxDegree[i + 1] - max) * unitY * (-1) + 30, 'red')
            }
        }
        for (let i = 0; i <= 7; i++) {
            drawcir(unitX + 90 * i, (minDegree[i] - max) * unitY * (-1) + 30, 'blue')
            dirText(`20px`, `${minDegree[i]}°`, (unitX + 90 * i - 10), (minDegree[i] - max) * unitY * (-1) + 60)
            if (i < 7) {
                drawline(unitX + 90 * i, (minDegree[i] - max) * unitY * (-1) + 30, unitX + 90 * (i + 1), (minDegree[i + 1] - max) * unitY * (-1) + 30, 'blue')
            }
        }
    }
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
    function btn_r1Fun(hoursListEle) {
        if (parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth < 2090) {
            hoursListEle.style.left = `-${hoursListEle.offsetWidth - 1140}px`
        } else {
            hoursListEle.style.left = `${hoursListEle.style.left - 1045}px`
        }
    }
    function btn_l1Fun(hoursListEle) {
        if (parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth >= 2090) {
            hoursListEle.style.left = `0px`
        } else {
            hoursListEle.style.left = `${parseInt(hoursListEle.style.left) + 1045}px`
        }
    }
    function btn_r2Fun(ul_list) {
        if (parseInt(ul_list.style.left) > -380) {
            ul_list.style.left = `${parseInt(ul_list.style.left) - 380}px`
        }
    }
    function btn_l2Fun(ul_list) {
        if (parseInt(ul_list.style.left) < 0) {
            ul_list.style.left = `${parseInt(ul_list.style.left) + 380}px`
        }
    }
    function choose_city(result) {
        const city_middle = document.createDocumentFragment()
        for (let p in result) {
            let cityp = document.createElement('p')
            cityp.classList.add('tit')
            cityp.innerHTML = `${result[p]}`
            city_middle.appendChild(cityp)
        }
        cityAll.appendChild(city_middle)
        cityAll.style.display = 'block'
    }
    function choose_click() {
        let input = document.getElementById('search')
        let cityAll = document.querySelector('.cityAll')
        let p = document.querySelectorAll('.cityAll>p')
        p.forEach((e, index) => {
            e.addEventListener('mousedown', () => {
                cityAll.style.display = 'none'
                input.value = ""
                cityAll.innerHTML = ""
                let cityStr = e.innerHTML.split(',')
                if (cityStr.length === 2) {
                    getData(cityStr[0], cityStr[1])
                    pos.innerHTML = `${cityStr[0]} ${cityStr[1]}`
                } else if (cityStr.length === 3) {
                    getData(cityStr[0], cityStr[1], cityStr[2])
                    pos.innerHTML = `${cityStr[1]} ${cityStr[2]}`
                }
            })
        })
    }

    //在dom中更新history
    function updataHis() {
        his.innerHTML = ""
        history = (JSON.parse(localStorage.getItem('history')) || [])
        const hisEle = document.createDocumentFragment()
        // history.forEach((item)=>{
        if (history.length >= 1) {
            for (let i = history.length - 1; i >= 0; i--) {
                const hor_item = document.createElement('li')
                // <li class="top_right" data-province="上海" data-city="上海">上海</li>
                hor_item.classList.add('top_right')
                hor_item.setAttribute('data-province', history[i].data_province)
                hor_item.setAttribute('data-city', history[i].data_city)
                hor_item.setAttribute('data-county', history[i].data_county)
                hor_item.innerHTML = `${history[i].data_city}`
                hisEle.appendChild(hor_item)
            }
        }
        // })
        his.appendChild(hisEle)
        const historyEle = document.querySelectorAll('#cityhistory>.top_right')
        historyEle.forEach((item) => {
            item.addEventListener('mousedown',function(){
                if(this.attributes['data-province'].value === this.attributes['data-city'].value){
                    pos.innerHTML = `${this.attributes['data-city'].value}`
                }else{
                    pos.innerHTML = `${this.attributes['data-province'].value} ${this.attributes['data-city'].value}`
                }
                cityInput.style.display = `none`
                getData(this.attributes['data-province'].value, this.attributes['data-city'].value)
            })
        })
    }



    //在dom中更新关注
    function updataCon(data) {
        concern = (JSON.parse(localStorage.getItem('saveCity')) || [])
        const cityConcern = document.getElementById('cityConcern')
        cityConcern.innerHTML = ""
        if(concern.length === 0){cityConcern.innerHTML = `<li id="city_concern">点击“添加关注”添加城市哟~</li>`}
        concern.forEach(item => {
            cityConcern.innerHTML += `<li class="itemcity" data-province="陕西省" data-city="西安市" data-district="">
                                    <div class="ct-location">
                                        <p class="location">西安市</p>
                                        <a href="javascript:;" class="btnMR">设为默认</a>
                                    </div>
                                        <img class="icon" src="https://mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/01.png" alt="多云" title="多云">
                                        <p class="weather">多云转小雨</p>
                                        <p class="temperature">19°/25°</p>
                                        <a href="javascript:;" class="btn btn-delete"></a>
                                </li>`
            // <li class="itemcity" data-province="陕西省" data-city="西安市" data-district=""> <div class="ct-location"> <p class="location">西安市</p>  <a href="javascript:;" class="btn btn-set-default">设为默认</a>  </div> <img class="icon" src="//mat1.gtimg.com/pingjs/ext2020/weather/pc/icon/weather/day/01.png" alt="多云" title="多云"> <p class="weather">多云转小雨</p> <p class="temperature">19°/25°</p> <a href="javascript:;" class="btn btn-delete"></a></li>
        })








        his.innerHTML = ""
        history = (JSON.parse(localStorage.getItem('history')) || [])
        const hisEle = document.createDocumentFragment()
        // history.forEach((item)=>{
        if (history.length >= 1) {
            for (let i = history.length - 1; i >= 0; i--) {
                const hor_item = document.createElement('li')
                // <li class="top_right" data-province="上海" data-city="上海">上海</li>
                hor_item.classList.add('top_right')
                hor_item.setAttribute('data-province', history[i].data_province)
                hor_item.setAttribute('data-city', history[i].data_city)
                hor_item.setAttribute('data-county', history[i].data_county)
                hor_item.innerHTML = `${history[i].data_city}`
                hisEle.appendChild(hor_item)
            }
        }
        // })
        his.appendChild(hisEle)
        const historyEle = document.querySelectorAll('#cityhistory>.top_right')
        historyEle.forEach((item) => {
            item.addEventListener('mousedown',function(){
                if(this.attributes['data-province'].value === this.attributes['data-city'].value){
                    pos.innerHTML = `${this.attributes['data-city'].value}`
                }else{
                    pos.innerHTML = `${this.attributes['data-province'].value} ${this.attributes['data-city'].value}`
                }
                cityInput.style.display = `none`
                getData(this.attributes['data-province'].value, this.attributes['data-city'].value)
            })
        })
    }

    //history保存在本地
    function saveHistory(history, a, b, c) {
        history.push({
            data_province: a,
            data_city: b,
            data_county: c
        })
        localStorage.setItem(`history`, JSON.stringify(history));
    }

    //画圆
    function drawcir(left, top, color) {
        ctx.beginPath();
        ctx.strokeStyle = 'red'
        ctx.arc(left, top, 4, 0, 2 * Math.PI);
        ctx.fillStyle = color;
        ctx.fill();

    }
    //写字
    function dirText(size, text, left, top) {
        ctx.beginPath();
        ctx.fillStyle = 'black'
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
}
