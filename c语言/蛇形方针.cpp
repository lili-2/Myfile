#include <stdio.h>
int map[1000][1000];
int main()
{
	int n,m,i,j,k=1;
	int left=0,right,up=0,down;
	
	scanf("%d %d",&m,&n);//控制行和列 
	right=n-1,down=m-1;
	while(1)
	{
		for(i=left;i<=right;i++)
			map[up][i]=k++;
		if(++up>down) break;
		for(i=up;i<=down;i++)
			map[i][right]=k++;
		if(--right<left) break;
		for(i=right;i>=left;i--)
			map[down][i]=k++;
		if(--down<up) break;
		for(i=down;i>=up;i--)
			map[i][left]=k++;
		if(++left>right) break;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%-3d ",map[i][j]);
		printf("\n");
	}
	return 0;
}

