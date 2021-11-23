#include<stdio.h> 
#include<stdlib.h> 
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

void Creat_AdjMatrix(AdjMatrix *G);  //�����ڽӾ���
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);  

void Print_AdjList(AdjList *G);  //����ڽӱ�

void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L);  //�ڽӾ���ת��Ϊ�ڽӱ�

main()
{
    AdjMatrix gM;
    AdjList gL;
    Creat_AdjMatrix(&gM);
    AdjMatrixToAdjList(&gM,&gL);
    Print_AdjList(&gL);
}

void Creat_AdjMatrix(AdjMatrix *G)//�����ڽӾ���
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vex[i]));
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j]=0;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjMatrix(G,v1);
        j=LocateVex_AdjMatrix(G,v2);
        G->arcs[i][j]=1; 
    }
}

int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)//����ڽӱ�
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vex[i]==v) 
            return i;
    return 0;
}


void Print_AdjList(AdjList *G)
{
    int i;
    ArcNode *p;
    for(i=1;i<=G->vexnum;i++)
    { 
        printf("%d:(%c)",i,G->vertex[i].vexdata);
        for(p=G->vertex[i].head;p;p=p->next)
        {
            printf("->%d",p->adjvex);
        }
        printf("\n");
    }
}

/* ����������д�� */
void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L){
    int i,j,count = 0;
    ArcNode * p;
    L->vexnum = M->vexnum;
    for(i = 1;i <= M->vexnum; i++){
        for(j = 1;j <= M->vexnum;j++){
	
            if(M->arcs[i][j] == 1){
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                
                p->next = L->vertex[i].head;
                L->vertex[i].head = p;
                count++;
            }
        }
    }
    L->arcnum = count;
}



void AdjListToAdjMatrix(AdjMatrix *M,AdjList *L){
    M->vexnum = L->vexnum;
    int i;
    for(i = 0;i < L->vexnum;i++){
        M->
    }

}

// typedef struct
// {
//     int arcs[MAXVEX+1][MAXVEX+1];
//     Vextype vex[MAXVEX+1];
//     int vexnum;
//     int arcnum;
// }AdjMatrix;

// typedef struct
// {
//     VertexNode vertex[MAXVEX];
//     int vexnum;
//     int arcnum;
// }AdjList;
