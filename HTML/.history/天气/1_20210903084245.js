window.onload = function () {
    const concern = []
    const guanzhu = document.getElementsByClassName('guanzhu')[0];
    // guanzhu.addEventListener('click',)
    // localStorage.setItem("key", "value");

    $.ajax({
        url: `https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=%E9%99%95%E8%A5%BF%E7%9C%81&city=%E8%A5%BF%E5%AE%89%E5%B8%82&county`,
        type: "GET",
        dataType: "JSONP",
        success: function (data) {
            update(data.data)
        },
        error: function (error) {
            console.log("错误")
            console.log(error)
        }
    });
    // search.addEventListener('keydown', function (e, v) {
    //     if (e.keyCode === 13) {
    //         // console.log(search.value)
    //         searchcity(search.value)
    //     }
    // })

    function update(data) {
        todayUp(data)

        oneHour(data)

        //左右键绑定click事件
        // const btn_l1 = document.getElementsByClassName('btn_l')[0]
        // const btn_r1 = document.getElementsByClassName('btn_r')[0]
        // btn_r1.addEventListener('click',() => {
        //     if(parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth < 0){
        //         hoursListEle.style.left =  `-${hoursListEle.offsetWidth}px`
        //     }else{
        //         hoursListEle.style.left =  `${hoursListEle.style.left - 1140}px`
        //     }
        //     console.log(hoursListEle.style.left,hoursListEle.offsetWidth)
        //     console.log(parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth)
        // })

        Seven_top(data)

        //7天天气预报 下 forecast_24h
        const dats7_bottom = document.getElementsByClassName("days7_footer")[0]
        const middle_daysbottom = document.createDocumentFragment()

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

            // night_wind_power
            days_bottom_pic.innerHTML = `${data.forecast_24h[i].night_weather_code}`
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
    }
    function todayUp(data) {
        //当天数据更新
        const data_today = document.getElementsByClassName("data_today")
        const winds_arr = ['微风', '东北风', '东风', '东南风', '南风', '西南风', '西风', '西北风', '北风']
        data_today[0], innerHTML = `中央气象台发布${data.observe.update_time}`
        data_today[1].innerHTML = `${data.observe.degree}°`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[3].innerHTML = `${winds_arr[data.observe.wind_direction]} ${data.observe.wind_power}级`//wind_direction
        data_today[4].innerHTML = `湿度 ${data.observe.humidity}%`
        data_today[5].innerHTML = `气压 ${data.observe.pressure}hPa`
        //逐小时天气预报
        const hour_data_time = document.getElementsByClassName("hour_data_time")
        const hours_data = document.getElementsByClassName('hours_data')[0]
    }
    function Seven_top(data) {
        //7天天气预报 上 forecast_24h
        const dats7_top = document.getElementsByClassName("dats7_top")[0]
        const middle_daystop = document.createDocumentFragment()

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

            days_top_time1.innerHTML = ""
            days_top_time2.innerHTML = `${data.forecast_24h[i].time.slice(5, 7)}月${data.forecast_24h[i].time.slice(8, 10)}日`
            days_top_tianqi.innerHTML = `${data.forecast_24h[i].day_weather}`
            days_top_pic.innerHTML = `${data.forecast_24h[i].day_weather_code}`
        }
        dats7_top.appendChild(middle_daystop)
    }
    function(data) {
        //forecast_1h
        const hoursListEle = document.createElement('ul')
        hoursListEle.classList.add('hour_data_list')
        for (let i = 0; i <= 24; i++) {
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
            hoursListEle.appendChild(hourEle)

            const hourDatatime = data.forecast_1h[i].update_time
            hourDataTime.innerHTML = `${hourDatatime.slice(8, 10)}:${hourDatatime.slice(11, 13)}`
            hourDataDegree.innerHTML = `${data.forecast_1h[i].degree}°`
        }
        hours_data.appendChild(hoursListEle)
    }
}
