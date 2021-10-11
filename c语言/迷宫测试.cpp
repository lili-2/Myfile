#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int i;
	int j;
	int k;
	struct node * next;
	struct node * left;
}Node; 
int arr[20][20];
int count[20][20];
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
			scanf("%1d",&arr[i][j]);
		}
	}
	Node * top = create_stack();
	int	i = 0,j = 0;
	while(i != m-1 || j != n-1)
	{
		if(arr[i][j+1] == 0 && j+1<n && count[i][j+1] < 2)//����1
		{
			pushStack(top,i,j,1);
			arr[i][j+1] = 3; 
			count[i][j] ++;
			j++;
		}
		else if(arr[i+1][j] == 0 && i+1<m && count[i][j+1] < 2)//����2
		{
			pushStack(top,i,j,2);
			arr[i+1][j] = 3; 
			count[i][j] ++;
			i++;

		}
		else if(arr[i][j-1] == 0 && j-1>=0 && count[i][j+1] < 2)//����3
		{
			pushStack(top,i,j,3);
			arr[i][j-1] = 3;
			count[i][j]++;
			j--; 
		}
		else if(arr[i-1][j] == 0 && i-1>=0 && count[i][j+1] < 2)//����4
		{
			pushStack(top,i,j,4);
			arr[i-1][j] = 3;
			count[i][j]++;
			i--; 
		}else{
			arr[top->next->i][top->next->j] = 0;
			i = top->next->i;
			j = top->next->j;
			popStack(top);
		}
	}
	pushStack(top,i,j,0);
	while(tail!=top)
	{
		printf("(%d,%d,%d)",tail->i+1,tail->j +1,tail->k);
		tail=tail->left;
	}
	return 0;
}

