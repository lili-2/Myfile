// (function(){
//     class Person{
//         name: string;
//         age: number;
//         constructor(name:string,age:number){
//             this.name = name;
//             this.age = age;
//         }
//     }
//     const per = new Person("孙悟空",18);
//     per.name = 's'
// })(); 



// ************************************抽象类***************************************

//以abstract开头的类是抽象类  抽象类和其他类区别不大，但是不能用来创建对象 抽象类就是专门用于被继承的类 extends继承
//抽象类中可以添加抽象方法 
// abstract class Animals {
//     name: string;
//     constructor(name:string) {
//         this.name = name;
//     }
//     //抽象发方法 使用abstract开头，没有方法体，抽象方法只能定义在抽象类中，子类必须对抽象类进行重写，强制子类实现一个方法
//     abstract sayHello():void;
// }




// ************************************接口***************************************

//描述一个对象的类型 
// type myType = {
//     name: string,
//     age: number
// };
// const obj : myType = {
//     name: "hello",
//     age: 111
// }

// 接口用来定义一个类结构 类就是用来创建对象的 用来定义一个类中应该包含哪些属性和方法

// 同时接口也可以当作类型声明去使用

// 不能重复去声明一个类型 但是接口可以重复声明 效果:合并 

// interface myInterface{
//     name : string,
//     age: number;
// }
// const obj : myInterface = {
//     name: "hello",
//     age: 111
// }

// 接口可以在定义类的时候去限制类的结构 有点像抽象类,接口只定义对象结构，不考虑实际值，接口中的所有的属性都不能有实际的值
//  interface myInter{
//      name : string,
//      sayhello():void;
//  }

// //定义类时，可以使类去继承一个接口
// //实现接口就是使类满足接口的要求 implements实现
// class MyClass implements myInter{
//     name: string;
//     constructor(name: string){
//         this.name = name;
//     }
//     sayhello() {
//         console.log('hello');
//     }
// }
// 接口实际上就是定义类一个规范 只要实现接口 ，就满足条件，可以在规定地点使用




// *****************************************对属性的封装*******************************************

// class Person {
//     name: string;
//     age: number;
//     constructor(name: string, age: number) {
//         this.name = name;
//         this.age = age;
//     }
// }
// const per = new Person("孙悟空", 18);
// per.name = 'sun';
// per.age = 38;
// console.log(per);
//现在属性是在对象中设置的  属性可以被任意修改 会导致对象中的数据变得非常不安全
// class Person {
//     //ts可以在属性前面加修饰符 

//     // public修饰的属性 可以在任意位置访问修改 包括子类
//     // privacy 私有属性 只能在类内部进行修改  可以通过在类中添加方法使得私有属性可以被外部访问
//     //
//     private _name: string;
//     private _age: number;
//     constructor(name: string, age: number) {
//         this._name = name;
//         this._age = age;
//     }
//     //定义方法 用来获取name属性 getter setter 属性的存取器
//     // getName(){
//     //     return this._name;
//     // }
//     // //定义方法 用来设置name的值
//     // setName(value: string){
//     //     this._name = value;
//     // }
//     // setAge(value: number){
//     //     if(value >= 0){
//     //         this._age = value; 
//     //     }
//     // }

//     // ts中设置getter方法
//     get name(){
//         return this._name;
//     }
//     set name(value: string){
//         this._name = value
//     }
// }
// const per = new Person("孙悟空", 18);
// // per.setName("sun"); 原来的写法
// // console.log(per.getName());

// console.log(per.name) //ts中 .name时调用了get方法 用起来和属性一样  可以加入判断 js中defineOwnproperty那个方法也可以实现

// class A {
//     //num 默认值为public 子类均可访问
//     // num: number;
//     // constructor(num: number){
//     //     this.num = num;
//     // } 

//     //private b中无法访问 只能在当前类中访问
//     // private num: number;
//     // constructor(num: number){
//     //     this.num = num;
//     // }

//     //protected 折中 受保护的属性 只能在当前类和他的子类中访问（修改）
//     protected num: number;
//     constructor(num: number) {
//         this.num = num;
//     }

// }
// class B extends A {
//     test() {
//         console.log(this.num)
//     }
// }
// const b = new B(12);
// //protected 时 b.num无法访问

// class  C {
//     //可以直接将属性定义在构造函数中 属性声明 和 this.name = name都不用写了
//     constructor(public name: string,public age : number) {

//     }
// }
// const c = new C("niha",18);


// ***************************************泛型***********************************************

// 泛型 适用于多个类型 
// 泛型是指在预先定义函数、接口或者类的时候，不预先指定数据的类型，而是在使用的时候指定。

// function fun(a:number):number{
//     return a;
// }

//定义函数或者是类的时候，如果遇到类型不确定的 就可以使用泛型 类型一般为大写 T是一种类型，只有调用的时候才能知道
//<T> 这里是定义 所以a后可以使用
// function fun<T>(a: T): T{
//     return a;
// };
// //可以直接调用具有泛型的函数 用ts的自动推断，
// let result = fun(10); // 自动推断 并不是所有情况都能推断出来
// let result1 = fun<string>('hello');//指定泛型

// 泛型指定多个
// function fn2<T,K>(a: T,b: K):T{
//     return a;
// };
// fn2<number,string>(12,'hello');

//为泛型指定范围
// interface Inter{
//     length: number;
// }
// // T extends Inter 表示泛型必须实现Inter实现类（子类） 不一定非要传接口 类也可以
// function fn3<T extends Inter>(a: T): number{
//     return a.length;
// }
// //传入数据必须有一个length属性 比如 字符串
// fn3("123")

// //在类中使用泛型
// class MyClass<T> {
//     name: T;
//     constructor(name: T) {
//         this.name = name;
//     }
// }
// const mc = new MyClass<string>('sun');



// extends和implements区别
 

// 1、在类的声明中，通过关键字extends来创建一个类的子类。

// 一个类通过关键字implements声明自己使用一个或者多个接口。 

// extends 是继承某个类, 继承之后可以使用父类的方法, 也可以重写父类的方法; 

// implements 是实现多个接口, 接口的方法一般为空的, 必须重写才能使用 

// 2、extends是继承父类，子类除了不能继承父类的私有成员(方法和属性)和构造函数，其他的都可以继承。

// TypeScript 一次只能继承一个类，不支持继承多个类，但 TypeScript 支持多重继承（A 继承 B，B 继承 C）。

// 但implements可以实现多个接口，用逗号分开就行了 比如 ：

// class A extends B implements C,D,E

// 接口实现的注意点：  

// a.实现一个接口就是要实现该接口的所有的方法(抽象类除外)。 

// b.接口中的方法都是抽象的。  

// c.多个无关的类可以实现同一个接口，一个类可以实现多个无关的接口。