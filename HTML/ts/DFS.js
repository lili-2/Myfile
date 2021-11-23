var ArrList = [
    {
        index: 0,
        data: 'A',
        next: {
            index: 1,
            next: {
                index: 4
            }
        }
    },
    {
        index: 1,
        data: 'B',
        next: {
            index: 2
        }
    },
    {
        index: 2,
        data: 'C',
        next: {
            index: 3
        }
    },
    {
        index: 3,
        data: 'D',
        next: {
            index: 0,
            next: {
                index: 1
            }
        }
    },
    {
        index: 4,
        data: 'E',
        next: {
            index: 2
        }
    }
];
// const visited: number[] = new Array(5).fill(0);
var visited = [0, 0, 0, 0, 0];
var stack = [];
function DFS(ArrList) {
    stack.push(ArrList[0]);
    while (stack.length) {
        var v = stack.pop();
        if (!visited[v.index]) {
            console.log(ArrList[v.index].data);
            visited[v.index] = 1;
            while (v.next) {
                if (!visited[ArrList[v.next.index].index]) {
                    stack.push(ArrList[v.next.index]);
                }
                v.next = v.next.next;
            }
        }
    }
}
DFS(ArrList);
// const Queue:Item[] = []
// function * BFS (ArrList: List[]){
//     Queue.unshift(ArrList[0])
//     while(Queue.length){
//         let v = Queue.pop()!;
//         if(!visited[v.index]){
//             console.log(ArrList[v.index].data)
//             visited[v.index] = 1;
//             while(v.next){
//                 if(!visited[ArrList[v.next.index].index]){
//                     Queue.unshift(ArrList[v.next.index])
//                 }
//                 v.next = v.next.next!;
//             }
//         }
//     }
// }
// const fn = BFS(ArrList);
// fn.next()
