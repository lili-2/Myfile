// class Animal {}

// class Cat extends Animal{
//     meow(){
//         console.log('cat meow');
//     }
// }

// class Dog extends Animal{
//     wow(){
//         console.log('dog wow');
//     }
// }

// function test1(v:Cat):Cat{
//     return v
// }
// function test2(v:Animal):Animal{
//     return v;
// }
// let a = test1(Animal);  报错
// let b = test2(Cat);

class Animal { }

class Cat extends Animal {
    meow() {
        console.log('cat meow');
    }
}
class Dog extends Animal {
    wow() {
        console.log('dog wow');
    }
}
class SmallDog extends Dog{
    public name: string = 'name'
}

//参数dog 返回值Dog
type testType = (v:Dog) => Dog;
function exec(v:testType){
    v(new SmallDog)
}
