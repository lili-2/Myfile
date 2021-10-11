#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //队列的最大容量
typedef int ElemType;
typedef struct
{      ElemType  elem[MAXSIZE];
       int rear;  //队尾元素的位置
       int quelen; //队中元素的个数
}SeQueue;
SeQueue *InitQueue()  //初始化队列，返回值为指向队列的指针。
{
    SeQueue *q;
    q=(SeQueue*)malloc(sizeof(SeQueue));
    q->quelen=0;
    q->rear=-1;
    return q;
}

void DestroyQueue(SeQueue *Q)
{
    ElemType x;
    while(!IsEmptyQueue(Q))
    {
        DelQueue(Q,&x);
        printf("%d ",x);
    }
    printf("\n");
    free(Q);
}
//队列的基本操作函数定义
SeQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeQueue *Q); //依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
int main(void)
{
	SeQueue * Q =  InitQueue();
    int i;
    int n;
    while(1){
    	scanf("%d",&i);
		    if(i == 1){
		    		printf("输入");
		    		scanf("%d",&n);
					EnQueue(Q, n);
				}
		    else if(i == 2){
					DelQueue(Q, &n);
					printf("出队元素%d",n); 
			}
	} 
    return 0;
}
int IsEmptyQueue(SeQueue *Q) //队列判空，若为空，则返回1；非空，返回0。
{
	if(Q->quelen == 0)
	{
		return 1;
	}
	return 0;
}
int IsFullQueue(SeQueue *Q) //队列判满，若为满，则返回1；非满，返回0。
{
	if(Q->quelen == MAXSIZE)
	{
		return 1;
	}
	return 0;
} 
int EnQueue(SeQueue *Q, ElemType x)//  元素x入队，若操作成功，则返回1；操作失败，则返回0。
{
	
	if(!IsFullQueue(Q))
	{
		Q->rear = (Q->rear+1)%MAXSIZE;
		Q->elem[Q->rear] = x;
		Q->quelen++;
		return 1; 
	}else
	{
		return 0;
	}
}
int DelQueue(SeQueue *Q, ElemType *x) //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
{
	SeQueue * q = Q;
	int j;
	j = Q->rear;
	printf("%d %d\n",Q->quelen,Q->rear); 
	if(IsEmptyQueue(Q))
	{
		return 0;	
	}else
	{
		for(int i = 0;i < Q->quelen;i++)
		{
			 j++;
		}
		*x = Q->elem[j%MAXSIZE];
		Q->quelen--;
	}
    return 1;
} 

