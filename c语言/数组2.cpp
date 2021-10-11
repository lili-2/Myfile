#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int i;
	int j;
	int k;
	struct node * next;
}Node; 

int arr[50][50];

Node * create_stack()
{
	Node * top;
	top = (Node *)malloc(sizeof(Node));
	top->next = NULL;
	return top;
}
void pushStack(Node * top,int i,int j,int k)
{
	Node * q;
	q = (Node *)malloc(sizeof(Node));
	q->i = i;
	q->j = j;
	q->k = k;
	q->next = top->next;
	top->next = q;
} 
void popStack(Node * top)
{
	Node * p;
	p = top->next;
	top->next = top->next->next;
	free(p);
}

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j <n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	Node * top = create_stack();
    
    
    int i = 0,j = 0;
	while(i == m && j == n)
	{
		if(arr[i][j+1] == 0 && j+1<m)
		{
			pushStack(top,i,j+1,0);
			arr[i][j+1] = 3; 
		}
		else if(arr[i+1][j] == 0 && i+1<n)
		{
			pushStack(top,i+1,j,1);
			arr[i][j+1] = 3;
		}
		else if(arr[i][j-1] == 0 && j-1>0)
		{
			pushStack(top,i,j,2);
			arr[i][j+1] = 3;
		}
		else if(arr[i-1][j] == 0 && i-1>0)
		{
			pushStack(top,i-1,j,3);
			arr[i][j+1] = 3;
		}else{
			popStack(top);
		}
	}
	while(top->next!=NULL)
	{
		printf("(%d),(%d),(%d)",top->i,top->j,top->k);
	}
	return 0;
}

