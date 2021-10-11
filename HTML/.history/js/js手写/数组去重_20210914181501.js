const arr = [1,1,'1',17,true,true,false,false,'true','a',{},{}];

// 1. set
const arr1 = Array.from(new Set(arr));

// 2.使用indexof
const unique = arr => {
    const arr2 = [];
    for(let i = 0;i < arr.length;i++){
        if(arr2.indexOf(arr[i] === -1)){
            arr2.push(arr[i]);
        }
    }
    return arr2;
}

// 3. 使用include
const arr3 = arr => {
    const res = [];
    for(let i = 0;i < arr.length;i++){
        if(!res.includes(arr[i])) res.push(arr[i]);
    }
}
// indexOf() 方法可返回某个指定的字符串值在字符串中首次出现的位置。
// 4.使用filter
const arr4 = arr => {
    return arr.filter((item,index) => {
        return arr.indexOf(item) === index;
    })
}