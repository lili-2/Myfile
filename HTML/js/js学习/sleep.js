// function sleep(ms){
//     return new Promise(resolve => {
//         setTimeout(resolve, ms);
//     });
// }
// (async () => {
//     console.log('111');

//     await sleep(2000);

//     console.log('222');
// })();

// async function randomDelay(id){
//     const delay = Math.random() * 1000;
//     return new Promise((resolve) => setTimeout(() => {
//         console.log(`${id} finished`);
//         resolve();
//     },dalay));
// }
// async function foo(){
//     const t0 = Date.now();
//     const promises = Array(5).fill(null).map((_,i) => randomDelay(i));
//     for(const p of promises){
//         await p;
//     }
// }

(() => {
    console.log(1);
})()