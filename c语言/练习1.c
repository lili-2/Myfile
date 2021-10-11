#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //创建带头结点单链表,并返回头指针。
void PrintLinkList(LinkList H);//依次输出单链表H中各个元素结点，若为空表则输出NONE。
LinkList CombineList(LinkList La,LinkList Lb)
{
	LinkList CombineList(LinkList La,LinkList Lb)
{
    LNode *p,*q,*r,*a,*b;
    LinkList Lc;
    int m=0,n=0;
    p = La->next;
    q = Lb->next;
  
  
    
    while(p){
        ++m;
        p = p->next;
    }
    while(q){
        ++n;
        q = q->next;
    }
    p = La->next;
    q = Lb->next;
    if(m <= n){
    	Lc = La;
        r = Lc;
         
        while(p && q){
            r->next = p;
            r = p;
            p = p->next;
            r->next = q;
            r = q;
            
            q = q->next;
        }
       
            while(q){
                r->next = q;
                r = q;
                q = q->next;
            }
    }
    else
    {
    	Lc = Lb;
        r = Lc;
        while(p && q){
            r->next = q;
            r = q;
            q = q->next;
            r->next = p;
            r = p;
            p = p->next;
           
        }
        
        while(p){
            r->next = p;
            r = p;
            p = p->next;
        }
    }

    free(Lb);
    return (Lc);
}    
}
main()
{
    LinkList la,lb;
    la = CreatLinkList();
    lb = CreatLinkList();
    la=CombineList(la,lb);
    PrintLinkList(la);
}

LinkList CreatLinkList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    head=(LNode*)malloc(sizeof(LNode));
    rear=head;
    scanf("%d",&n);//接收结点总数
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        rear->next=nw;
        rear=nw;
    }
    rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!(H->next))
    {    
        printf("NONE\n");
        return;
    }
    for(p=H->next;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}





















