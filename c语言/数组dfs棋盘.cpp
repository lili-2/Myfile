#include<stdio.h>
int m,n,book[9][9],Map[9][9],ans=1;
int next[8][2]={{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int a;
void dfs(int x,int y);
int main()
{
	scanf("%d %d",&m,&n);
	book[m][n]=1;
	Map[m][n]=ans;
	ans++;
	dfs(m,n);
	for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
			printf("%2d ",Map[i][j]);
			}
		printf("\n");
	}
	return 0;
}
void dfs(int x,int y)
{
	int tx,ty;
	for(int k=0;k<8;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		if (tx>=1&&tx<=8&&ty>=1&&ty<=8)
		{
		
			if (book[tx][ty]==0)
			{
				Map[tx][ty]=ans;
				ans++;
				book[tx][ty]=1;
					  
				if (ans>64)
				{
					a=1;
					return ;
				}
				if (a)
				{
					return ;
				}
				Map[tx][ty]=0;
				book[tx][ty]=0;
				ans--;
			}
		}
	}
}
