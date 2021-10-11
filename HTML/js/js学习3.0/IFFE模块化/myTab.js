; (function (doc, tpl, tools) {
    // console.log(tools)
    // console.log(tpl)
    function MyTab(el) {
        this.el = doc.querySelector(el);
        this.data = JSON.parse(this.el.getAttribute('data'));
        this._index = 0;

        this.init();
    }
    //init启动
    MyTab.prototype.init = function () {
        //需要渲染 render
        this._render();
        //绑定事件处理函数
        this._bindEvent();
    }
    MyTab.prototype._render = function () {
        var tabWrapper = doc.createElement('div');
        var pageWrapper = doc.createElement('div');
        //createdocumentfragment()方法创建了一虚拟的节点对象，节点对象包含所有属性和方法
        var oFrag = doc.createDocumentFragment();

        tabWrapper.className = 'tab-wrapper';
        pageWrapper.className = 'page-wrapper';

        this.data.forEach(function (item, index) {
            tabWrapper.innerHTML += tools.tplReplace(tpl.tab('tab'), {
                tab: item.tab,
                current: !index ? 'current' : '  '
            });
            pageWrapper.innerHTML += tools.tplReplace(tpl.tab('page'), {
                page: item.page,
                current: !index ? 'current' : '  '
            });
        });

        oFrag.appendChild(tabWrapper);
        oFrag.appendChild(pageWrapper);

        this.el.appendChild(oFrag)
        // console.log(tabWrapper,pageWrapper);
    }
    MyTab.prototype._bindEvent = function () {
        var doms = {
            oTabItems: doc.querySelectorAll('.tab-item'),
            oPageItems: doc.querySelectorAll('.page-item')
        }
        this.el.addEventListener('click', this._handleTabClick.bind(this, doms), false);
    }
    MyTab.prototype._handleTabClick = function () {
        console.log(arguments);
        var _doms = arguments[0],
            tar = arguments[1].target,
            className = tar.className.trim();

        if (className === 'tab-item') {
            _doms.oTabItems[this._index].className = 'tab-item';
            _doms.oPageItems[this._index].className = 'page-item';
            this._index = [].indexOf.call(_doms.oTabItems, tar)
            // console.log(this._index)
            tar.className += ' current';
            _doms.oPageItems[this._index].className += ' current'
        }

        // console.log(_doms,tar,className)
    }
    window.MyTab = MyTab;
})(document, tpl, tools);