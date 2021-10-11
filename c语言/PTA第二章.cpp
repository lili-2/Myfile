#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //创建无头结点单链表,并返回头指针。
void PrintLinkList(LinkList H);//依次输出无头结点单链表H中各个元素结点，若为空表则输出NONE。
void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j);
main()
{
    LinkList la,lb;
    int i,j,len;
    la = CreatLinkList();
    lb = CreatLinkList();
    scanf("%d %d %d",&i,&j,&len);
    MoveLaToLb(&la,i,len,&lb,j);
    PrintLinkList(la);
    PrintLinkList(lb);
}

LinkList CreatLinkList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    scanf("%d",&n);//接收结点总数
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        if(rear==NULL)
            rear=head=nw;
        else
        {
            rear->next=nw;
            rear=nw;
        }
    }
    if(rear)
        rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!H)
    {    
        printf("NONE\n");
        return;
    }
    for(p=H;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}


/* 请在这里填写答案 */
void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j)
{
	int a = len;
	LinkList p,q,m; 
	p = *pa;
	q = *pb;
	while(i-- > 2)
	{
		p = p->next; 
	}
	while(j-- > 1)
	{
		q = q->next;
	} 
	while(a--)
	{
		if(p->next != NULL && q!=NULL) break;
	}
	while(len--)
	{
		m = p->next;
		p->next = p->next->next;
		
		m->next = q->next;
		q->next = m; 
		q = q->next;
	}
}
