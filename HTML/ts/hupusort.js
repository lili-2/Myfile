var myArrList = [
    {
        index: 0,
        data: 'A',
        next: {
            index: 1,
            next: {
                index: 2,
                next: {
                    index: 3
                }
            }
        }
    },
    {
        index: 1,
        data: 'B'
    },
    {
        index: 2,
        data: 'C',
        next: {
            index: 1,
            next: {
                index: 4
            }
        }
    },
    {
        index: 3,
        data: 'D',
        next: {
            index: 4
        }
    },
    {
        index: 4,
        data: 'E'
    },
    {
        index: 5,
        data: 'F',
        next: {
            index: 3,
            next: {
                index: 4
            }
        }
    }
];
var myQueue = [];
var indegree = [0, 0, 0, 0, 0, 0];
function TopoSort(G) {
    for (var i = 0; i < G.length; i++) {
        var p = G[i].next;
        while (p) {
            indegree[p.index]++;
            p = p.next;
        }
    }
    for (var i = 0; i < G.length; i++) {
        if (indegree[i] === 0) {
            myQueue.unshift(i);
        }
    }
    var count = 0;
    while (myQueue.length > 0) {
        var node = myQueue.pop();
        count++;
        console.log(G[node].data);
        var p = G[node].next;
        while (p != null) {
            indegree[p.index]--;
            if (indegree[p.index] == 0) {
                myQueue.unshift(p.index);
            }
            p = p.next;
        }
    }
    if (count < G.length)
        return 0;
    return 1;
}
console.log(TopoSort(myArrList));
