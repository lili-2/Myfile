window.onload = (function(doc){
    console.log("____________________________")
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
        console.log(data.observe)
        const data_today = doc.getElementsByClassName("data_today")
        console.log(data_today)
    
        const winds_arr = ['微风','东北风','东风','东南风','南风','西南风','西风','西北风','北风']
        //[div#time.data_today, div#temp.data_today, div#weather.data_today, time: div#time.data_today, temp: div#temp.data_today, weather: div#weather.data_today
        data_today[0],innerHTML = `中央气象台发布${update_time}`
        data_today[1].innerHTML = `${data.observe.degree}°`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[3].innerHTML = `${winds_arr[data.observe.wind_direction]} ${data.observewind_power}`//wind_direction
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[2].innerHTML = `${data.observe.weather}`
        data_today[2].innerHTML = `${data.observe.weather}`
        
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
    