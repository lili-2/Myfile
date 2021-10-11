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
    
}