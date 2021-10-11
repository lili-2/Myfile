
window.onload = function () {
    //导航栏
    const header = document.querySelector('header');
    const block = document.querySelector('header>.right').querySelectorAll('div');
    const body = document.querySelector('body');
    window.onscroll = function () {
        if (document.documentElement.scrollTop > 100) {
            header.classList.add("header");
            block[1].style.backgroundColor = "white";
            block[1].style.borderColor = "rgb(87, 19, 87)";
            block[2].style.backgroundColor = "rgb(87, 19, 87)";
            block[2].style.color = "white";
            body.style.paddingTop = '70px';
        } else {
            header.classList.remove("header");
            block[1].style.backgroundColor = "";
            block[1].style.borderColor = "";
            block[2].style.backgroundColor = "";
            block[2].style.color = "";
            body.style.paddingTop = '';
        }
    }

    const ad = document.querySelector('.ad');
    const adc = ad.querySelector('.click');
    adc.addEventListener('click',function(){
        ad.style.display = "none";
    })
    //取消视频控制
    // const video = document.querySelector("video");
    // video.controls = false;


    //设置左边动态
    const midleft = document.getElementsByClassName('middle_left')[0];
    window.addEventListener('scroll',function(){
        if(document.documentElement.scrollTop > 1000 &&document.documentElement.scrollTop < 2000){
            midleft.classList.add('middle_left2');
            body.style.backgroundColor = "rgb(248, 235, 215)"
            midleft.style.display = "block";
        }else{
            midleft.classList.remove('middle_left2');
            body.style.backgroundColor = "";
            midleft.style.display = "";
        }
    })
}