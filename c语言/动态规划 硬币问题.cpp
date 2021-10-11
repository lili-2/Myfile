#include<stdio.h>
int min(int a,int b)
{
	return a>b ? b : a;
} 
int main()
{
	int dp[100],i;
	dp[0] = 0; 
	int cost;
	for(i=1;i<=15;i++)
	{
		cost = 999999;
		if(i>=1) cost = min(cost,dp[i-1]+1);
		if(i>=5) cost = min(cost,dp[i-5]+1);
		if(i>=11) cost = min(cost,dp[i-11]+1);
		dp[i] = cost;
		printf("dp[%d]=%d\n",i,dp[i]);
	}
}
