let obj = Object.create(null) 与 let obj = {} 有什么区别？

    之前腾讯面试的时候，问了这个问题：对象字面量创建对象与 Object.create(null)创建对象有什么区别？
    一开始是有点懵的，不都是创建对象么，能有啥不同，后面我去试了一下，结果发现还蛮有意思：

let obj = {};
let obj2 = Object.create(null);
console.log(obj);
console.log(obj2)

    1
    2
    3
    4

    控制台打印
    在这里插入图片描述
    乍一看，好像没啥区别，都是一个花括号
    然而，展开后，确实大有不同
    在这里插入图片描述
    Object.create(null)创建的对象是非常纯净的，没有任何其它元素
    而另一个let创建的对象是带有_proto_的，下面有一些方法与属性，这便是js的原型链继承，它继承了Object的方法和属性。这便是区别。

    所以这种区别导致了使用场景不同

    如果需要对象的继承属性和方法，那就使用 let obj = {};
    如果只需要一个纯净的对象，那就使用 Object.create(null)
    比如说，我只需要用对象来保存一些数据，然后进行循环取用，提高循环效率。
    这个时候如果对象有原型链，那便会在循环的时候去循环它的各个属性和方法
    然而这不是必要的，我们只是要他里面的元素而已，前者会影响循环效率