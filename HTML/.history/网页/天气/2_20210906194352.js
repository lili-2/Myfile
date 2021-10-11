window.onload = function(){
    function cb(data) {
        update(data.data)
        updataCon()
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
    addScriptTag(`https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=${a}&city=西安&callback=cb`);
    
}