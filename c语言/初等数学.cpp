/*
#include<stdio.h>
int gcd(int a,int b)
{
	if(a,b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int t;
	while(1)
	{
		t = a/b;
		if(t=0)
			return b;
		a = b;
		b = t;
	}
}
int main()
{
	int x,y,a,b,count=0;
	scanf("%d %d",&x,&y);
	for(a=1;a<=y;a++)
	{
		for(b=y;b>0;b--)
		{
			if(a*b == x*y && gcd(a,b) == x)
			{
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int  n,count=0,p=0,i,j;
	scanf("%d",&n);
	int is_prime[10000] = {true};
	int prime[1000];
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<n;i++)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(j=i*2;j<=n;j+=i)
				is_prime[j] = false;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(prime[i])
			count++;
	}
	printf("%d\n",count);
	return 0;
}*/
#include<stdio.h>
int main()
{
	int i;
	int a[10] = {1};
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
	for(i=l-1;i>=0;i--)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			number1+=(s1[i]-'0')*pow(b,l-1-i);
		}
		else
		{
			number1+=(s1[i]-'A'+10)*pow(b,l-1-i);
		}
	}
	printf("%d  ",number1);
	l=strlen(s2);
	for(i=l-1;i>=0;i--)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			number1+=(s2[i]-'0')*pow(b,l-1-i);
		}
		else
		{
			number1+=(s2[i]-'A'+10)*pow(b,l-1-i);
		}
	}
	printf("%d  ",number2);




















