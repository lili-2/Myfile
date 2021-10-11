const arr = [1,[2,[3,[4,5]]],6];

//1 使用flat()
const arr1 = arr.flat(Infinity);

//2.使用正则 缺点：数据类型都会变成字符串
const arr2 = JSON.stringify(arr).replace(/\[|\]/g,'').split(',');

//3.正则改良
const arr3 = '[' + JSON.stringify(arr).replace(/\[|\]/g,'') + ']';

// 4. 使用reduce
const flatten = arr => {
    return arr.reduce((pre,cur) => {
        return pre.concat(Array.isArray(cur) ? flatten(cur) : cur);
    },[])
}
const arr4 = flatten(arr);

// 5.函数递归
const arr5 = [];
const fn = arr => {
    for(let i = 0;i < arr.length;i++){
        if(Array.isArray(arr[i])){
            fn(arr[i]);
        }else{
            arr5.push(arr[i]);
        }
    }
}
fn(arr);

console.log(arr);
console.log(arr1);
console.log(arr2);
console.log(arr3);
console.log(arr4);
console.log(arr5);
 
