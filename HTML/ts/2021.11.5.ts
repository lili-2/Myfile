// const visited = new Array(10).fill(0);//被访问的节点

// interface Node{
//     index: number,
//     data: String,
//     next: number[]
// }

// const stack: Node[] = []

// interface List{
//     vexnum: number
//     arr: Node[]  
// }

// function * DFS (MyList:List){

//     stack.push(MyList.arr[0]);

//     while(stack.length){
//         let v = stack.pop()!;
//         if(!visited[v.index]){
//             yield console.log(v.data);
//             visited[v.index] = 1;
//             let i = visited.indexOf(0);
//             let next = v.next[i];
//             while(next != 0){
//                 if(!visited[next]) stack.push();//入栈
//                 i = visited.indexOf(0);
//                 next = v.next[i];
//             }
//         }
//    }
// }