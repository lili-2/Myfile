#include<stdio.h>
int w[105];
int v[105];
int dp[105];
int max(int a,int b)
{
	return a>b ? a : b;
}
int main()
{
	int n,i,a,b;
	int bag;
	scanf("%d %d",&n,&bag);	
	for(i = 0;i < n;i++)
	{
		scanf("%d %d",&a,&b);
		a = w[i];
		b = w[i];
	}
	for(i=1;i<n;i++)
	{
		if(bag >= w[i])
		{
			dp[i] = max(dp[i-1]+v[i],dp[i-1]);
		}
	}
	printf("%d",dp[n-1]);
	return 0;
} 
