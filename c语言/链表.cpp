#include<stdio.h>
#include<malloc.H>
typedef  struct Node 
{
	int date;
	struct Node * pNext;
}NODE, *PNODE;
void traverse_list(struct Node *);
PNODE creat_list(void);
int main()
{
	PNODE pHead = NULL;

	pHead = creat_list();
	traverse_list(pHead);
}
void traverse_list(struct Node * pHead)
{
	PNODE p = pHead->pNext;
	while(pHead->pNext != NULL)
	{
		printf("%d ",p->date);
		p = p->pNext;
	}
	return ;
}
PNODE creat_list(void)
{
	int len;
	int i;
	int value;
	printf("length=\n");
	scanf("%d",&len);
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); 
	
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	for(int i = 0;i < len; i++)
	{
		printf("value\n");
		scanf("%d",&value);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		
		pNew->date = value;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

