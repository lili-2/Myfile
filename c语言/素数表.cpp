/*
#include<stdio.h>
const int MAXN=le5+10;
void isprime(MAXN); 
int main()
{
	int n;
	scanf("%d",&n);
	
	for( i=2;i<=n/2;i++)
	{
		if(isprime[i]&&isprime[n-i])
		{
			if( i!= n-i )
			{
				sum++;
			}
		}
	}
	return 0;
}
void isprime()
{
	int i,x;
	for( i=0;i<MAXN;i++)
	{
		isprime[i] = 1;
	}
	for( x=2;x<MAXN;x++)
	{
		if( isprime[i] )
		{
			for( i=2;i<MAXN;i++)
			{
				isprime[i*x]=0;
			}
		}
	} 
}
*/
/*
#include<stdio.h>
int main()
{
	int a,i,n,m;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&n,&m);
		if(n%(m+1) == 0)
		{
			printf("second\n");
		}
		else
		{
			printf("first\n");
		}
	}
	return 0;
}
*/

#include<stdio.h>
int main()
{
	int c;
	scanf("%d",&c);
	int map[100][100] = { 0 };
	while (c--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=i;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		for (int i=n-2;i>=0;i--)
		{
			for (int j=0;j<=i;j++)
			{
				map[i][j] = map[i][j] + (map[i+1][j]>map[i+1][j+1] ? map[i+1][j] : map[i+1][j+1]);
			}
		}
		printf("%d",map[0][0]);
	}
	return 0;
}

