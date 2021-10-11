window.onload = function () {
    const concern = []
    const guanzhu = document.getElementsByClassName('guanzhu')[0];
    const cityAll = document.getElementsByClassName('cityAll')[0]
    // guanzhu.addEventListener('click',)
    // localStorage.setItem("key", "value");

    function getData(a,b,c){
        console.log(arguments.length)
        $.ajax({
            if(arguments.length ==)
            ,
            // type: "GET",
            dataType: "JSONP",
            success: function (data) {
                update(data.data)
            },
            // error: function (error) {
            //     console.log("错误")
            //     console.log(error)
            // }
        });
    }
    getData(`陕西`,`西安`)
    search.addEventListener('keydown', function (e, v) {
        if (e.keyCode === 13) {
            // console.log(search.value)
            get_city(search.value)
        }
    })
    // async function  searchcity(city){
    //     const result = await get_city(city)
    //     await  console.log(result)
    //     await choose_city(result)
    // }
    
    async function get_city(city, source='pc'){
        let result = await $.ajax({
            url: 'https://wis.qq.com/city/like', 
            type: 'get',
            data: {source: source, city: city}, 
            dataType: 'jsonp',
            success: function(res){ return res },
            error: function (error){ console.log(error)}
        });
        await choose_city(result.data)
        await choose_click()  
    }
    function update(data) {
        //当天数据更新
        const data_today = document.getElementsByClassName("data_today")
        const winds_arr = ['微风', '东北风', '东风', '东南风', '南风', '西南风', '西风', '西北风', '北风']
        const dayTime = `${data.observe.update_time}`
        data_today[0].innerHTML = `中央气象台${dayTime.slice(8,10)}:${dayTime.slice(10,12)}发布`
        data_today[1].innerHTML = `${data.observe.degree}°`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[3].innerHTML = `${winds_arr[data.observe.wind_direction]} ${data.observe.wind_power}级`//wind_direction
        data_today[4].innerHTML = `湿度 ${data.observe.humidity}%`
        data_today[5].innerHTML = `气压 ${data.observe.pressure}hPa`
        data_today[6].innerHTML = `限行 ${data.limit.tail_number}`

        //逐小时天气预报
        const hour_data_time = document.getElementsByClassName("hour_data_time")
        const hours_data = document.getElementsByClassName('hours_data')[0]
        hours_data.innerHTML = ''
        //forecast_1h
        const hoursListEle = document.createElement('ul')
        hoursListEle.classList.add('hour_data_list')
       
        for (let i = 0; i <= 25; i++) {
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
            if(i === 24){
                hourDataTime.innerHTML = `${data.rise[0].sunrise}`
                hourDataDegree.innerHTML = `日出`
            }
            else if(i === 25){
                hourDataTime.innerHTML = `${data.rise[0].sunset}`
                hourDataDegree.innerHTML = `日落`
            }else{
                const hourDatatime = data.forecast_1h[i].update_time
                hourDataTime.innerHTML = `${hourDatatime.slice(8, 10)}:${hourDatatime.slice(11, 13)}`
                hourDataDegree.innerHTML = `${data.forecast_1h[i].degree}°`
            }
            if(i<=24){
                hoursListEle.appendChild(hourEle)
            }else{
                hoursListEle.appendChild(hourEle)
            }
        }
        hours_data.appendChild(hoursListEle)

        // 左右键绑定click事件
        const btn_l1 = document.getElementsByClassName('btn_l')
        const btn_r1 = document.getElementsByClassName('btn_r')
        btn_r1[0].addEventListener('click',() => btn_r1Fun(hoursListEle))
        btn_l1[0].addEventListener('click',() => btn_l1Fun(hoursListEle))

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
            if(i === 0){
                days_top_time1.innerHTML = `昨天`
            }else if(i === 1){
                days_top_time1.innerHTML = `今天`
            }else{
                days_top_time1.innerHTML = `${getMyDay(new Date(timeWeek))}`
            }
            days_top_time2.innerHTML = `${time.slice(5, 7)}月${time.slice(8, 10)}日`
            days_top_tianqi.innerHTML = `${data.forecast_24h[i].day_weather}`
            days_top_pic.innerHTML = `${data.forecast_24h[i].day_weather_code}`
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
        btn_r1[1].addEventListener('click',() => btn_r2Fun(ul_list))
        btn_l1[1].addEventListener('click',() =>btn_l2Fun(ul_list))
    }
    //获取星期几
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
    function btn_r1Fun(hoursListEle){
        if(parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth < 2090){
            hoursListEle.style.left =  `-${hoursListEle.offsetWidth - 1140}px`
        }else{
            hoursListEle.style.left =  `${hoursListEle.style.left - 1045}px`
        }
    }
    function btn_l1Fun(hoursListEle){
        if(parseInt(hoursListEle.style.left) + hoursListEle.offsetWidth >= 2090){
            hoursListEle.style.left = `0px`
        }else{
            hoursListEle.style.left =  `${parseInt(hoursListEle.style.left) + 1045}px`
        }
    }
    function btn_r2Fun(ul_list){
        if(parseInt(ul_list.style.left) > -380 ){
            ul_list.style.left =  `${parseInt(ul_list.style.left) - 380}px`
        }
    }
    function btn_l2Fun(ul_list){
        if(parseInt(ul_list.style.left) < 0){
            ul_list.style.left =  `${parseInt(ul_list.style.left) + 380}px`
        }
    }
    function choose_city(result){
        const city_middle = document.createDocumentFragment()
        for(let p in result){
            let cityp = document.createElement('p')
            cityp.classList.add('tit')
            cityp.innerHTML =  `${result[p]}`
            city_middle.appendChild(cityp)
        }
        cityAll.appendChild(city_middle)
        cityAll.style.display = 'block'
    }
    function choose_click(){
        let input = document.getElementById('search')
        let cityAll = document.querySelector('.cityAll')
        let p = document.querySelectorAll('.cityAll>p')
        p.forEach((e,index) => {
            e.addEventListener('click',() => {
                cityAll.style.display = 'none'
                input.value = ""
                cityAll.innerHTML = ""
                let cityStr = e.innerHTML.split(',')
                if(cityStr.length === 2){
                    getData(cityStr[0],cityStr[1])
                }else if(cityStr.length === 3){
                    getData(cityStr[0],cityStr[1],cityStr[2])
                }
            })
        })
    }
}
