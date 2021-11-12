;(function(){
    var Waterfall = function(opt){
        this.el = document.getElementsByClassName(opt.el)[0];
        this.oItems = document.querySelectorAll(".wf-item");

        this.colmun = opt.colmun;
        this.gap = opt.gap;
       
        this.itemWidth = (this.el.offsetWidth - (this.colmun - 1) * this.gap) / this.colmun;
        
        this.heightArr = [];

        this.init();

    }

    Waterfall.prototype.init = function(){
        this.render();
    }

    Waterfall.prototype.render = function(){
        let minIndex = -1;
        for(let i = 0;i < this.oItems.length;i++){
            item = this.oItems[i];
            item.style.width = this.itemWidth + 'px';
            if(i < this.colmun){
                item.style.top = '0px';
                item.style.left = i * (this.itemWidth + this.gap) + 'px'; 
                this.heightArr.push(item.offsetHeight);
            }else{
                let minIndex = getMinIdx(this.heightArr);
                item.style.left = this.oItems[minIndex].offsetLeft + 'px';
                item.style.top = this.heightArr[minIndex] + this.gap + 'px';

                this.heightArr[minIndex] += this.heightArr[minIndex] + item.offsetHeight + this.gap
            }
        }
        
    }

    function getMinIdx(arr){
        return arr.indexOf(Math.min(...arr));
    }

    window.Waterfall = Waterfall
})();