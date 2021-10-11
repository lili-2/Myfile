#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
typedef struct node
{      DataType  data;
       struct node *next; 
}LNode,*CirLinkQueue;

//���еĻ���������������
CirLinkQueue InitQueue();  //��ʼ�����У�����ֵΪ���е�βָ�롣
int IsEmptyQueue(CirLinkQueue Q); //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
int EnQueue(CirLinkQueue *Q, DataType x);  //  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int DelQueue(CirLinkQueue *Q, DataType *x);  //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
void DestroyQueue(CirLinkQueue Q);

int main(void)
{
    char cmd[20];
    CirLinkQueue pQueue = InitQueue();
    DataType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(&pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(&pQueue,&x) == 0)
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
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(CirLinkQueue Q)
{
    LNode *p,*t;
    p=Q;Q=Q->next;
    p->next=NULL;
    p=Q->next;
    while(p)
    {
        printf("%d ",p->data);
        t=p->next;
        free(p);
        p=t;
    }
    free(Q);
}

/* ����������д�� */
CirLinkQueue InitQueue()  //��ʼ�����У�����ֵΪ���е�βָ�롣
{
	LNode *s;
	s = (LNode *)malloc(sizeof(LNode));
	s->next = s;
	return s;
}
int IsEmptyQueue(CirLinkQueue Q)//�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
{
	if(Q->next == Q)
	{
		return 1;
	}
	return 0;
}
int EnQueue(CirLinkQueue *Q, DataType x)  //  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
{
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));
	p->data = x;
	p->next = (*Q)->next;
	(*Q)->next = p;
	*Q = p;
	return 1;
}
int DelQueue(CirLinkQueue *Q, DataType *x)
{
	*x = (*Q)->data;
	if(IsEmptyQueue) return 0;
	return 1;
}
