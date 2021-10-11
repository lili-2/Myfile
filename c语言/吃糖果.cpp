#include<stdio.h>
int main()
{
	long long number=0,n,x,i;;
	scanf("%lld %lld",&n,&x);
	int a[100001];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}		
	for(i=0;i<n-1;i++)
	{
		if((a[i+1]+a[i])>x&&x>a[i])
		{
			a[i+1]-=a[i+1]+a[i]-x;
			number+=a[i+1]+a[i]-x;
		}
		else if((a[i+1]+a[i])>x&&x<a[i])
		{
		    a[i+1]=0;
            number+=a[i+1]+a[i]-x;
		}
	}
	printf("%lld",number);
	return 0;
}
