#include<stdio.h>
int a[10005];
int b[10005];
int main()
{
	int n,m,j = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&m);
		a[m]++;		
	}
	for(int i = 0;i < 1000;i++)
	{
		while(a[i] != 0)
		{
			b[j] = i;
			j++;
			a[i]--;
		}
	}
	for(int i = 0;i < j;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
