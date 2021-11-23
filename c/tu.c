#include<stdio.h>
#include<malloc.h>

#define MAXVEX 20
typedef struct 
{
    int arcs[MAXVEX + 1][MAXVEX + 1];
    char vex[MAXVEX + 1];
    int vexnum;
    int arcnum;
    int chudu[MAXVEX + 1];
    int rudu[MAXVEX + 1];
}AdjMatrix;

int find_index(AdjMatrix* G,char c){
    int i;
    for(i = 1;i <= G->vexnum;i++){
        if(G->vex[i] == c){
            return i;
        }
    }
    return 0;
}

void Creat_AdjMatrix(AdjMatrix * G){
    int i,j,k;
    char v1,v2;
    scanf("%d %d\n",&(G->vexnum),&(G->arcnum));
    for(i = 1;i <= G->vexnum;i++){
        scanf("%c",&(G->vex[i]));
        for(j = 1;j <= G->vexnum;j++){
            G->arcs[i][j] = 0;
        }
        G->rudu[i] = 0;
        G->chudu[i] = 0;
    }

    for(k = 1;k <= G->arcnum;k++){
        scanf(" %c %c",&v1,&v2);
        i = find_index(G,v1);
        j = find_index(G,v2);
        G->arcs[i][j] = 1;
        G->rudu[j]++;
        G->chudu[i]++;
    }
}

void DFS(AdjMatrix * G){

}

void BFS(AdjMatrix * G){
    
}

typedef struct Node
{
    int index;
    struct Node * next;  
}Node;

void stackpush(Node * head,int i){
    Node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    Node * q = (Node *)malloc(sizeof(Node));
    q->index = i;
    q->next = NULL;
    p->next = q;
}

int stackpop(Node * head){
    Node * p = head;
    Node * q;
    if(p->next != NULL){
        q = p->next;
        int index = q->index;
        p->next = p->next->next;
        free(q);
        return index;
    }
    return 0;
}

int main()
{
    AdjMatrix G;
    Creat_AdjMatrix(&G);
    Node * head;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    
}