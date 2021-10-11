#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//栈 
typedef struct Node
{
	int date;
	struct Node * pNext;
}NODE,* PNODE;
//两个指针 指向头部和尾部
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PTACK;


//创造出一个空栈 
void init(PTACK pS);
//压栈 
void push(PTACK pS, int val); 
//遍历输出
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
		printf("出战成功,出栈的元素是%d\n",val);
	}
	traverse(&S);
	return 0;		
} 
void init(PTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("动态内存分配失败\n");
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
