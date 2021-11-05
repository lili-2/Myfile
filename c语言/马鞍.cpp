#include<stdio.h>
 
int main()
 
{
	int m,n;
	int i,j;
	int max[20],min[20];
	scanf("%d %d",&m,&n);
	int a[20][20];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]<=a[i][0])
				min[i]=a[i][j];
		}
	}
 
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[j][i]>=a[0][i])
				max[i]=a[j][i];
		}
	}
 
	for(i=0;i<m||j<n;i++)
	{
		if(min[i]==max[i])
			printf("%d",min[i]);
	}
 
	return 0;
}
