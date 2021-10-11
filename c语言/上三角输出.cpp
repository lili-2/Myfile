#include <stdio.h>
int map[1000][1000];
int main()
{
	int x,y,i,j,k,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0,k=1;i<n/2;i++)
		{
			for(x=i,y=i;y<n-2*i-1;y++)
				map[x][y]=k++;
			for(;y>i;y--,x++)
				map[x][y]=k++;
			for(;x>i;x--)
				map[x][y]=k++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			printf("%-3d ",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}

