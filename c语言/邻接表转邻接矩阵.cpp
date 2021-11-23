#include<stdio.h> 
#include<malloc.h>
#define MAXVEX 20
typedef char Vextype;
typedef struct
{
    int arcs[MAXVEX+1][MAXVEX+1];
    Vextype vex[MAXVEX+1];
    int vexnum;
    int arcnum;
}AdjMatrix;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct 
{
    Vextype vexdata;
    ArcNode *head;
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
}AdjList;

void Creat_AdjList(AdjList *G);
int LocateVex_AdjList(AdjList *G,Vextype v);

void Print_AdjMatrix(AdjMatrix *G);

void AdjListToAdjMartix(AdjList *L,AdjMatrix *M);

main()
{
    AdjList gL;
    AdjMatrix gM;
    Creat_AdjList(&gL);
    AdjListToAdjMartix(&gL,&gM);
    Print_AdjMatrix(&gM);
}

void Creat_AdjList(AdjList *G)
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vertex[i].vexdata));
        G->vertex[i].head=NULL;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        ArcNode *p;
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjList(G,v1);
        j=LocateVex_AdjList(G,v2);
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->next=G->vertex[i].head;
        G->vertex[i].head=p;
    }
}

int LocateVex_AdjList(AdjList *G,Vextype v)
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vertex[i].vexdata==v) 
            return i;
    return 0;
}

void Print_AdjMatrix(AdjMatrix *G)
{
    int i,j;
    printf("  ");
    for(i=1;i<=G->vexnum;i++)
        printf("%c ",G->vex[i]);
    printf("\n");
    for(i=1;i<=G->vexnum;i++)
    { 
        printf("%c ",G->vex[i]);
        for(j=1;j<=G->vexnum;j++)
        {
            printf("%d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}

/* 请在这里填写答案 */
void AdjListToAdjMatrix(AdjMatrix *M,AdjList *L){
    M->vexnum = L->vexnum;
    int i,j,count=0;
    ArcNode * p;
    for(i = 1;i <= L->vexnum;i++){
        M->vex[i] = L->vertex[i].vexdata;
    }
    for(i = 1;i <= L->vexnum;i++){
        for(j = 1;j <= L->vexnum;j++){
            M->arcs[i][j] = 0;
        }
    }
    for(i = 1;i <= L->vexnum;i++){
        p = L->vertex[i].head;
        while(p != NULL){
            M->arcs[i][p->adjvex] = 1;
            p = p->next;
            count++;
        }
    }
    M->arcnum = count;
}


