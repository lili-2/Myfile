#include<stdio.h> 
#include<malloc.h> 
typedef struct node{
	int i;
	int j;
	int k;
	struct node * next;
	struct node * left;
}Node;

Node * tail;
Node * create_stack()
{
	Node * top;
	top = (Node *)malloc(sizeof(Node));
	top->next = NULL;
	top->left = NULL;
	return top;
}
void pushStack(Node * top,int i,int j,int k)
{
	Node * q;
	q = (Node *)malloc(sizeof(Node));
	q->i = i;
	q->j = j;
	q->k = k;
	if(top->next == NULL)
	{
		q->next = top->next;
		top->next = q;
		q->left = top;
		tail = q;
	}
	else
	{
		q->next = top ->next;
		q->left = top;
		top ->next = q;
		q->next->left = q;
	}
} 
void popStack(Node * top)
{
	Node * p;
	p = top->next;
	top->next =p->next;
    if(p->next == NULL)
    {
        top->next = NULL;
    }
	else
    {
        p->next->left = top;
    }
	printf("%d 出栈",p->i);
	free(p);
}
int main()
{
	int i,j,k;
	Node * top = create_stack();
	int a;
	while(1)
	{
		printf("选择入栈出栈"); 
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d %d %d",&i,&j,&k);
			pushStack(top,i,j,k);
		}else{
			popStack(top);
		}
	}
	return 0;
}

