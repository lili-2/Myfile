function Promise(executor){
    //添加属性
        this.PromiseStata = 'pending';
        this.PromiseResult = null;
        //声明属性 保存回调函数
        this.callbacks = [];
    
        const self = this;
        //保存this的值
        function resolve(data){
            //改变状态 promiseState
            if(self.PromiseStata !== 'pending') return;
            self.PromiseStata = 'fullfilled';
            //设置对象结果值 promiseResult
            self.PromiseResult = data;
            //调用成功的回调函数
            self.callbacks.forEach(item => {
                item.onResolved(data);
            })
        }
        function reject(data){
            if(self.PromiseStata !== 'pending') return;
            self.PromiseStata = 'rejected';
            //设置对象结果值 promiseResult
            self.PromiseResult = data;
            self.callbacks.forEach(item => {
                item.onRejected(data);
            })
        }
        try{
            executor(resolve, reject);
        }catch(e){
            reject(e);
        }
    }
    Promise.prototype.then = function(onResolved, onRejected){
        //调用回调函数
        if(this.PromiseStata === "fullfilled"){
            onResolved(this.PromiseResult);
        };
        if(this.PromiseStata === 'rejected'){
            onRejected(this.PromiseResult);
        }
        if(this.PromiseStata === 'pending'){
            //保存回调函数
            this.callbacks.push({
                onResolved: onResolved,
                onRejected: onRejected
            });
        }
    }