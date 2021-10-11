#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int j = n;
	for(int i=0;i<=n;i++)
	{
		for(j;j>i;)
		{
			printf("%d+%d=%d\n",i,j,n);
			j--;
			break;
		}
	}
	return 0;
}
