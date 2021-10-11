#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int date;//������ 
	struct Node * pNext;// ָ���� 
}NODE, *PNODE;

//��������
struct Node * create_list(void);//�������� 
void traverse_list(struct Node *);//��������
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);
 
int main(void)
{
	PNODE pHead = NULL;//pHead����������� ͷ���ĵ�ַ 
	int val;		 //�ȼ��� struct Node * pHead = NULL 
	 
	pHead = create_list();//create_list()���ܣ� ����һ����ѭ�������� ,�����������ͷ���ĵ�ַ����pHead 
	traverse_list(pHead);
	
	//insert_list(pHead,4,33);
	//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽ�㣬�ýڵ��ֵ��val ������pos��һ��ʼ 
//	if ( delete_list(pHead,4,&val) )
//	{
//		printf("ɾ���ɹ���ɾ����������:%d\n",val); 
//	}
//	else
//	{
//		printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز�����\n"); 
//	}
//	traverse_list(pHead);

	
	int len = length_list(pHead);
	printf("����ĳ�����%d\n",len);
	
	sort_list(pHead);
	traverse_list(pHead);
	
	
	/*
	if( is_empty(pHead))
		printf("����Ϊ��\n");
	else
		printf("������\n"); 
	*/
	return 0;
}

PNODE create_list(void)
{
	int len;//���������Ч�ڵ�ĸ��� 
	int i;
	int val;//������ʱ����û�����Ľ���ֵ 
	
	printf("����������Ҫ���ɵ�����ڵ�ĸ���: len=");
	scanf("%d",&len);
	
	//������һ���������Ч���ݵ�ͷ��� 

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if( NULL == pHead)
	{
		printf("����ʧ��");
		exit(-1); 
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	for(i=0; i<len ;++i)
	{
		printf("�������%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if( NULL == pNew)
		{
			printf("����ʧ��");
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

//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽ�㣬�ýڵ��ֵ��val ������pos��һ��ʼ 
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
		printf("��̬�����ڴ�ʧ��\n");
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
	
	//ɾ��p�ڵ����Ľ��
	p->pNext = p->pNext->pNext;
	free(q);
	q=NULL;
	
	return true; 
}
