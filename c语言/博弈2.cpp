/*
#include<stdio.h>
#include<string.h>
_Bool prime[100000000];
int main()
{
	int n;
	int i,j,p=0;
	scanf("%d",&n);
	memset(prime,1,sizeof(prime));
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<=n;i++)
	{
		if(prime[i])
		{
			p++;
			for(j=i*2;j<=n;j+=i)
			{
				prime[j]=0;
			}
		}
	} 
	printf("%d",p);
	return 0;
}
*/
/*
#include<stdio.h>
int prime(long long a)
{
	int flag=1;
	long long i;
	if(a%2==0&&a%3==0)
	{
		flag = 0;
	}
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	long long int a,b,i,t,number=0;
	scanf("%lld %lld",&a,&b);
	for(i=a;i<=b;i++)
	{
		t=i;
		while(t>0)
		{
			number = number * 10 + t%10 ;
			t/=10;
		}
		if(number==i&&prime(number))
		{
			printf("%d\n",number);
		} 
		number=0;
	}
	return 0;
}*/
/* 
#include<stdio.h>
#include<string.h>
int prime[10000000];
int main()
{
	long long int a,b,i,t,j,number=0;
	scanf("%lld %lld",&a,&b);
	memset(prime,1,sizeof(prime));
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<=b;i++)
	{
		if(prime[i])
		{
			for(j=i*2;j<=b;j+=i)
			{
				prime[j]=0;
			}
		}
	} 
	for(i=a;i<=b;i++)
	{
		t=i;
		while(t>0)
		{
			number = number * 10 + t%10 ;
			t/=10;
		}
		if(number==i&&prime[number])
		{
			printf("%d\n",number);
		} 
		number=0;
	}
	return 0;
}
