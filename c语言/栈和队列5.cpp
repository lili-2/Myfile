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

//���еĻ���������������
SeQueue * InitQueue();  //��ʼ�����У�����ֵΪָ����е�ָ�롣
void DestroyQueue(SeQueue *Q); //�������������Ԫ��ֵ�����ͷſռ䡣

int IsEmptyQueue(SeQueue *Q); //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
int IsFullQueue(SeQueue *Q); //������������Ϊ�����򷵻�1������������0��
int EnQueue(SeQueue *Q, ElemType x);  //  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int DelQueue(SeQueue *Q, ElemType *x);  //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��


int main(void)
{
    char cmd[20];
    SeQueue *pQueue=InitQueue();
    ElemType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(pQueue,&x) == 0)
                  printf("EMPTY QUEUE!\n");
            else
                printf("%d\n",x);
        }
        else if (strcmp(cmd, "ISEMPTY") == 0)
        {
            if (IsEmptyQueue(pQueue) == 0)
                 printf("NOT EMPTY\n");
            else
                  printf("EMPTY\n");
        }
        else if (strcmp(cmd, "ISFULL") == 0)
        {
            if (IsFullQueue(pQueue) == 0)
                 printf("NOT FULL\n");
            else
                  printf("FULL\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}


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
/* ����������д�� */
int IsEmptyQueue(SeQueue *Q) //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
{
	if((Q->rear)%4 == (Q->quelen)%4)
	{
		return 1;
	}
	return 0;
}
int IsFullQueue(SeQueue *Q) //������������Ϊ�����򷵻�1������������0��
{
	if((Q->rear+1)%4 == (Q->quelen)%4)
	{
		return 1;
	}
	return 0;
} 
int EnQueue(SeQueue *Q, ElemType x)//  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
{
	
}
int DelQueue(SeQueue *Q, ElemType *x);  //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
