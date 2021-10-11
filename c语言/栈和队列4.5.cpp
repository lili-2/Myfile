#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //���е��������
typedef int ElemType;
typedef struct
{      ElemType  elem[MAXSIZE];
       int rear;  //��βԪ�ص�λ��
       int quelen; //����Ԫ�صĸ���
}SeQueue;
SeQueue *InitQueue()  //��ʼ�����У�����ֵΪָ����е�ָ�롣
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
//���еĻ���������������
SeQueue * InitQueue();  //��ʼ�����У�����ֵΪָ����е�ָ�롣
void DestroyQueue(SeQueue *Q); //�������������Ԫ��ֵ�����ͷſռ䡣

int IsEmptyQueue(SeQueue *Q); //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
int IsFullQueue(SeQueue *Q); //������������Ϊ�����򷵻�1������������0��
int EnQueue(SeQueue *Q, ElemType x);  //  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int DelQueue(SeQueue *Q, ElemType *x);  //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int main(void)
{
	SeQueue * Q =  InitQueue();
    int i;
    int n;
    while(1){
    	scanf("%d",&i);
		    if(i == 1){
		    		printf("����");
		    		scanf("%d",&n);
					EnQueue(Q, n);
				}
		    else if(i == 2){
					DelQueue(Q, &n);
					printf("����Ԫ��%d",n); 
			}
	} 
    return 0;
}
int IsEmptyQueue(SeQueue *Q) //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
{
	if(Q->quelen == 0)
	{
		return 1;
	}
	return 0;
}
int IsFullQueue(SeQueue *Q) //������������Ϊ�����򷵻�1������������0��
{
	if(Q->quelen == MAXSIZE)
	{
		return 1;
	}
	return 0;
} 
int EnQueue(SeQueue *Q, ElemType x)//  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
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
int DelQueue(SeQueue *Q, ElemType *x) //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
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

