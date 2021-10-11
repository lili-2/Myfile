#include<stdio.h>
#include<malloc.h>
enum direction{ right = 1, down = 2, left = 3, top = 4 };

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
	Node * top = create_stack();
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
		if(arr[i][j] == 0 && j+1<n)
		{
			pushStack(top,i,j,right);	
			arr[i][j+1] = 2; 
			j++;
		}
		else if(arr[i+1][j] == 0 && i+1<m)
		{
			pushStack(top,i,j,2);
			arr[i+1][j] = 2;
			i++;
		}
		else if(arr[i][j-1] == 0 && j-1>=0)
		{
			pushStack(top,i,j,3);
			arr[i][j-1] = 2;
			j--; 
		}
		else if(arr[i-1][j] == 0 && i-1>=0)
		{

			pushStack(top,i,j,4);
			arr[i-1][j] = 2;
			i--; 
		}else{
			popStack(top);
		} 
	}
	pushStack(top,i,j,0);
	printf("%d %d\n",i,j);
	while(tail!=top)
	{
		printf("(%d,%d,%d)",tail->i+1,tail->j+1,tail->k);
		tail=tail->left;
	}
	return 0;
}
