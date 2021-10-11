#include<stdio.h>
int a[10005];
void sort(int n,int m)
{
	for(int i = n;i >= 0;i--)
	{
		if(m > a[i])
		{
			a[i+1] = m;
			break;
		}
		else
			a[i+1] = a[i];
	}
	return ;
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < n-1;i++)
	{
		sort(i,a[i+1]);
	}
	for(int i = 0;i < n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 
