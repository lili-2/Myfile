#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int i;
	int j;
	int k;
	struct node * next;
	struct node * left;
}Node; 
typedef struct{
	int x;
	int y;
}pos; 
int dir[2][9] = {{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}}; 
int board[8][8];
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
int popStack(Node * top)
{
	int count;
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
	count = p->k;
	free(p);
	return count;
}
int fes(int x,int y)//判断能不能走 
{
	if(x < 8 && x >= 0 && y >= 0 && y < 8 && board[x][y] == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int step = 0;
	int m,n;//m,n初始位置 
	scanf("%d %d",&m,&n);
	m--;
	n--;
	pos Cur,Next;
	Cur.x = m;//当前x,y 
	Cur.y = n;
	int before = 0;//当前点无路可走 上一个的方向 
	Node *head = create_stack();
	int i;
	while(step < 63)
	{
		i  = before + 1;
		while(i < 9)
		{
			Next.x = Cur.x + dir[0][i];
			Next.y = Cur.y + dir[1][i];
			if(fes(Next.x,Next.y))
			{
				step++;
				board[Cur.x][Cur.y] = step;
				pushStack(head,Cur.x,Cur.y,i);
				Cur.x = Next.x;
				Cur.y = Next.y;
				break;
			}
			i++;
		}
		if(i == 9)
		{
			if(head->next == NULL){
				printf("找不到合适的路径\n");
				break;
			}
			else
			{ 
				Cur.x = head->next->i;
				Cur.y = head->next->j;
				board[Cur.x][Cur.y] = 0;
				before = popStack(head);
				step--;
			}
		}
		else
		{
			before = 0;
		}
	}
	for(i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(board[i][j] == 0)
			{
				printf("%2d ",64);	 
			}
			else
			{
				printf("%2d ",board[i][j]);	 
			} 
		} 
		printf("\n");
	} 
}
