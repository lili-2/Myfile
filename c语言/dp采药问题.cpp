#include<stdio.h>
int ti[10005];
int vi[10005];
int dp[1000][1000];
int max(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
	int t,m;
	scanf("%d %d",&t,&m);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d %d",&ti[i],&vi[i]);
	}

	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= t;j++)
		{
			if(j >= ti[i])
			{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-ti[i]] + vi[i]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d",dp[m][t]);
	return 0;
}

