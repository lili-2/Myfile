#include<stdio.h>

#define MAXSIZE 3
typedef struct 
{
    int vexnum;
    Node vertex[10];
}AdjList;

typedef struct 
{
    int * head;
    int data;
}Node;


typedef struct 
{
    int adjvex;
    int * next;
}ArcNode;

typedef struct 
{
    
}Queue;

void InitQueue(){

}

void FindID(AdjList G,int indegree[MAXSIZE]){ //获取每个节点的入度值 
    int i;
    ArcNode * p;
    for(i = 0;i < G.vexnum;i++){
        indegree[i] = 0;
    }
    for(i= 0;i < G.vexnum;i++){
        p = G.vertex[i].head;
        while(p != NULL){
            indegree[p->adjvex]++;
            p = p->next;
        }
    }
}

int TopoSort(AdjList G){
    Queue Q;
    int indegree[MAXSIZE];
    int i,count,k;
    ArcNode * p;

    FindID(G,indegree);
    InitQueue(Q);
    
    for(i = 0;i < G.vexnum;i++){
        if(indegree[i] == 0){
            EnterQueue(&Q,i);
        }
    }

    count = 0;
    while(!IsEmpty(Q)){
        DeleteQueue(&Q,&i);
        printf("%c",G.vertex[i].data);
        count++;
        p = G.vertex[i].head;
        while (p != NULL)
        {
            k = p->adjvex;
            indegree[k]--;
            if(indegree[k] == 0) EnterQueue(&Q,k);
            p = p->next;
        }
    }
    
    if(count < G.vexnum) return 0;
    return 1;
}
