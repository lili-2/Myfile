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
    }





    
    search.addEventListener('keydown', function (e, v) {
        if (e.keyCode === 13) {
            // console.log(search.value)
            searchcity(search.value)
        }
    })
    searchcity = function (value) {
        $.ajax({
            url: `https://wis.qq.com/city/like?source=pc&city=${value}`,
            type: "GET",
            dataType: "JSONP",
            success: function (data) {
                console.log(data);
            },
            error: function (error) {
                console.log("错误")
                console.log(error)
            }
        });
    }
    // $.ajax({
    //     url: `https://wis.qq.com/city/like?source=pc&city=${}`,
    //     type: "GET",
    //     dataType: "JSONP",
    //     success: function (data) {
    //         console.log(data);
    //     },
    //     error: function (error) {
    //         console.log("错误")
    //         console.log(error)
    //     }
    // });
})(document)
    