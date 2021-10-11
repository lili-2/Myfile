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
//接口 
//描述一个对象的类型 
// type myType = {
//     name: string,
//     age: number
// };
// const obj : myType = {
//     name: "hello",
//     age: 111
// }
//接口用来定义一个类结构 类就是用来创建对象的 用来定义一个类中应该包含哪些属性和方法
//同时接口也可以当作类型声明去使用
//不能重复去声明一个类型 但是接口可以重复声明 效果:合并 
// interface myInterface{
//     name : string,
//     age: number;
// }
// const obj : myInterface = {
//     name: "hello",
//     age: 111
// }
//接口可以在定义类的时候去限制类的结构 有点像抽象类,接口只定义对象结构，不考虑实际值，接口中的所有的属性都不能有实际的值
// interface myInter{
//     name : string,
//     sayhello():void;
// }
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
//对属性的封装
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
// //现在属性是在对象中设置的  属性可以被任意修改 会导致对象中的数据变得非常不安全
// var Person = /** @class */ (function () {
//     function Person(name, age) {
//         this._name = name;
//         this._age = age;
//     }
//     //定义方法 用来获取name属性
//     Person.prototype.getName = function () {
//         return this._name;
//     };
//     //定义方法 用来设置name的值
//     Person.prototype.setName = function (value) {
//         this._name = value;
//     };
//     return Person;
// }());
// var per = new Person("孙悟空", 18);
// per.setName("sun");
// console.log(per.getName());
