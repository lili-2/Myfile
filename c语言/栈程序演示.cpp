#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//ջ 
typedef struct Node
{
	int date;
	struct Node * pNext;
}NODE,* PNODE;
//����ָ�� ָ��ͷ����β��
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PTACK;


//�����һ����ջ 
void init(PTACK pS);
//ѹջ 
void push(PTACK pS, int val); 
//�������
void traverse(PTACK  pS);
bool pop(PTACK pS,int *pVal);

int main()
{
	int val;
	STACK S;
	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);
	if(pop(&S,&val))
	{
		printf("��ս�ɹ�,��ջ��Ԫ����%d\n",val);
	}
	traverse(&S);
	return 0;		
} 
void init(PTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
 } 
void push(PTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->date = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	
	return ;
}
void traverse(PTACK  pS)
{
	PNODE p = pS->pTop;
	while(p != pS->pBottom)
	{
		printf("%d ",p->date);
		p = p->pNext; 
	}
	printf("\n");
}
bool pop(PTACK pS,int *pVal)
{
	if(pS->pTop == pS->pBottom)
	{
		return false;
	}
	else
	{
		PNODE q;
		q = pS->pTop;
		*pVal = q->date;
		pS->pTop = q->pNext;
		free(q);
		q = NULL;
		return true; 
	}
}
