window.onload = (function(doc){
    const concern = []
    const guanzhu = doc.getElementsByClassName('guanzhu')[0];
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

    function update(data){
        //当天数据更新
        const data_today = doc.getElementsByClassName("data_today")
        const winds_arr = ['微风','东北风','东风','东南风','南风','西南风','西风','西北风','北风']
        data_today[0],innerHTML = `中央气象台发布${data.observe.update_time}`
        data_today[1].innerHTML = `${data.observe.degree}°`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[3].innerHTML = `${winds_arr[data.observe.wind_direction]} ${data.observe.wind_power}级`//wind_direction
        data_today[4].innerHTML = `湿度 ${data.observe.humidity}%`
        data_today[5].innerHTML = `气压 ${data.observe.pressure}hPa`
        //逐小时天气预报
        const hour_data_time = document.getElementsByClassName("hour_data_time")
        //forecast_1h
        const hoursListEle = document.createElement('ul')
        hoursListEle.classList.add('hour_data_list')
        for(let i = 1;i <= 24;i++){
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

            // console.log(i)
            console.log(data.forecast_1h[i].update_time)
            // hourDataTime.innerHTML = `${data.forecast_1h.i.update_time}`
        }


    }

    
    // search.addEventListener('keydown', function (e, v) {
    //     if (e.keyCode === 13) {
    //         // console.log(search.value)
    //         searchcity(search.value)
    //     }
    // })
    // searchcity = function (value) {
    //     $.ajax({
    //         url: `https://wis.qq.com/city/like?source=pc&city=${value}`,
    //         type: "GET",
    //         dataType: "JSONP",
    //         success: function (data) {
    //             console.log(data);
    //         },
    //         error: function (error) {
    //             console.log("错误")
    //             console.log(error)
    //         }
    //     });
    // }
})(document)
    