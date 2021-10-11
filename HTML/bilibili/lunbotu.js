function move(obj, speed, target) {
    clearInterval(obj.timer);
    let current = parseInt(getStyle(obj, "left"));
    if(current > target){
        speed = -speed;
    }
    obj.timer = setInterval(function () {

        let oldValue = parseInt(getStyle(obj, "left"));

        let newValue = oldValue + speed;


        if((speed < 0 && newValue < target) || (speed > 0 && newValue > target))
        {
            newValue = target;
        }

        obj.style.left = newValue + "px";
        if(newValue == target){
            clearInterval(obj.timer);
        }
    }, 30);
}

function getStyle(obj, name) {
    if (window.getComputedStyle) {
        return getComputedStyle(obj, null)[name];
    } else {
        return obj.currentStyle[name];
    }
}