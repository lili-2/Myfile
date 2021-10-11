window.onload = function(){
    function addScriptTag(src){
        let lastscript=document.querySelector('.newscript');
        if(lastscript){
            document.body.removeChild(lastscript);
        }
        let script=document.createElement('script');
        script.src=src;
        script.className='newscript';
        document.body.appendChild(script);
    }
    addScriptTag('https://wis.qq.com/weather/common?source=pc&weather_type=observe|forecast_1h|forecast_24h|index|alarm|limit|tips|rise&province=陕西省&city=西安市&county=&callback=update');
    function update(data){

    }
}