function Person(name) {
    this.name = name
    this.sayName= function () {
        console.log(`我是 ${this.name}!`)
    }
}


function myNew(that, ...args) {
    const obj = Object.create(null)
    obj.__proto__ = that.prototype
    const res = that.call(obj, ...args)
    return res instanceof Object ? res : obj
}
let person= myNew(Person, '小明')
person.sayWorld(); // 我是小明
