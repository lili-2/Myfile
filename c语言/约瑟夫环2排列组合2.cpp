#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int num;
	struct node * next;
}Node;
//´´½¨Á´±í 
Node * creat_list(int n,int m)
{
	Node * head = (Node*)malloc(sizeof(Node));
	Node * p = head;
	for(int i = 0;i < n-1;i++)
	{
		p->num = i+1; 
		p->next = (Node*)malloc(sizeof(Node));
		p = p->next;
	}
	p->next = head;
	p->num = n;
	p = head;
	return head;
}
delete_list(Node * head,int n,int m)
{
	int count = 0; 
	Node * p = head;
	Node * q;
	while(p != p->next)
	{
		count ++;
		if(count == m - 1)
		{
			q = p->next;
			p->next = p->next->next;
			printf("%d ",q->num);
			free(q);
			count = 0;
		}
		p = p->next;
	}
	printf("%d ",p->num);
}
int main()
{
	int n,m;
	Node * head;
	scanf("%d %d",&n,&m);
	head = creat_list(n,m);
	delete_list(head,n,m);
	return 0;
} 
