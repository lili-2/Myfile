#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int date;//数据域 
	struct Node * pNext;// 指针域 
}NODE, *PNODE;

//函数声明
struct Node * create_list(void);//创建链表 
void traverse_list(struct Node *);//遍历链表
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);
 
int main(void)
{
	PNODE pHead = NULL;//pHead用来存放链表 头结点的地址 
	int val;		 //等价于 struct Node * pHead = NULL 
	 
	pHead = create_list();//create_list()功能： 创建一个非循环单链表 ,并将该链表的头结点的地址赋给pHead 
	traverse_list(pHead);
	
	//insert_list(pHead,4,33);
	//在pHead所指向链表的第pos个节点的前面插入一个新的结点，该节点的值是val ，并且pos从一开始 
//	if ( delete_list(pHead,4,&val) )
//	{
//		printf("删除成功，删除的数字是:%d\n",val); 
//	}
//	else
//	{
//		printf("删除失败，您删除的元素不存在\n"); 
//	}
//	traverse_list(pHead);

	
	int len = length_list(pHead);
	printf("链表的长度是%d\n",len);
	
	sort_list(pHead);
	traverse_list(pHead);
	
	
	/*
	if( is_empty(pHead))
		printf("链表为空\n");
	else
		printf("链表不空\n"); 
	*/
	return 0;
}

PNODE create_list(void)
{
	int len;//用来存放有效节点的个数 
	int i;
	int val;//用来临时存放用户输入的结点的值 
	
	printf("请输入您需要生成的链表节点的个数: len=");
	scanf("%d",&len);
	
	//分配了一个不存放有效数据的头结点 

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if( NULL == pHead)
	{
		printf("分配失败");
		exit(-1); 
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	for(i=0; i<len ;++i)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if( NULL == pNew)
		{
			printf("分配失败");
			exit(-1); 
		}
		pNew->date = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;	
	}  
	return pHead;
 } 

void traverse_list(PNODE pHead) 
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d\n",p->date);
		p = p->pNext;
	}
	return;
}
bool is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len =0;
	
	while(NULL!=p)
	{
		++len;
		p = p->pNext;
	}	
	return len;
}

void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);
	PNODE p,q;
	
	for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
	{
		for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
		{
			if(p->date > q->date)//a[i]>a[j]
			{
				t = p->date;
				p->date = q->date;
				q->date = t;
			}
		}
	}
}

//在pHead所指向链表的第pos个节点的前面插入一个新的结点，该节点的值是val ，并且pos从一开始 
bool insert_list(PNODE pHead,int pos,int val)
{
	int i = 0;
	PNODE p = pHead;
	
	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	
	if(i>pos-1||NULL==p)
		return false;
		
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("动态分配内存失败\n");
		exit(-1);
	}
	pNew->date = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;
}

bool delete_list(PNODE pHead,int pos,int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	
	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	
	if(i>pos-1||NULL==p->pNext)
		return false;
		
	PNODE q = p->pNext;
	*pVal = q->date;
	
	//删除p节点后面的结点
	p->pNext = p->pNext->pNext;
	free(q);
	q=NULL;
	
	return true; 
}
