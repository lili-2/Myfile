const wrapper = document.getElementsByClassName('wrapper')[0];
const items = document.querySelectorAll(".wf-item");
const imgs = document.querySelectorAll('img');
const heightArr = [];

let n = 0;
let flag = 0;
let start = 0;

const obj = {
    col: 5,
    mar: 10
}


const findMin = (arr) => {
    let min = Math.min(...arr);
    return arr.indexOf(min);
}

function imgLazy(){
    const len = imgs.length;
    for(let i = n;i < len;i++){
        if(imgs[i].offsetTop < (window.screen.width + document.documentElement.scrollTop)){       
            imgs[i].src = imgs[i].getAttribute('data-src')
            imgs[i].removeAttribute('data-src');
            n++;
        }else{
            console.log("buzhix")
        }
    }
    setTimeout(() => {
        flow(obj,40)
    },500)
}

imgLazy()

window.addEventListener('scroll',function(){
    imgLazy()
})

function flow(obj,n) {
   
    const { col, mar } = obj;
    const iWidth = (wrapper.offsetWidth - (col - 1)*mar)/col;
   
    let minIndex = -1;

    
    for(let i = start;i < n;i++){
        items[i].style.width = iWidth + 'px';
        if(i < col){
            items[i].style.top = '0px'
            items[i].style.left = i * iWidth + (i - 1)*mar + 'px';  
            heightArr.push(items[i].offsetHeight);
        }else{
            minIndex = findMin(heightArr);
            items[i].style.top = heightArr[minIndex] + mar + 'px';
            items[i].style.left = items[minIndex].offsetLeft + 'px';
            heightArr[minIndex] +=  items[i].offsetHeight + mar;
        }
        start++;
    }
   
}