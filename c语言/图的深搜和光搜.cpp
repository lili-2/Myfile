#include<stdio.h>
#include<malloc.h>
typedef struct{
    int arcnum;
    int nodnum;
    char c[20];
    int arr[20][20];
}tu;
int getItem(char c,tu * G){
    int i = 0;
    for(int i = 0;i < G->nodnum;i++){
        if(c == G->c[i]){
            return i;
        }
    }
}
int main()
{
    int i,j,k;
    char m,n;
    tu * G;
    G = (tu *)malloc(sizeof(tu));
    scanf("%d %d",&G->nodnum,&G->arcnum);
    for(i = 0;i < G->nodnum;i++){
        scanf("%c",&G->c[i]);
    }
    for(i = 0;i < G->nodnum;i++){
        for(j = 0;j < G->nodnum;j++){
            G->arr[i][j] = 0;
        }
    }
    for(k = 0;k < G->nodnum;k++){
    	printf("k = %d\n",k);
        scanf("%c%c",&m,&n);
        i = getItem(m,G);
        j = getItem(n,G);
        G->arr[i][j] = 1;
    }
    for(i = 0;i < G->nodnum;i++){
        for(j = 0;j < G->nodnum;i++){
            printf("%d ",G->arr[i][j]);
        }
        printf("\n");
    }
}

