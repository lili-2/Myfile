#include<stdio.h>
int main()
{
	int t,i,count=0,j;
	scanf("%d",&t);
	int a[t];
	
	for(i=0;i<t;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<t;i++)
	{
		while(a[i]!=0)
		{
			if(a[i]%2==1)
			{
				count++;
		    }
		    a[i]=a[i]/2;
		}
	}
	printf("%d\n",count);
	
	return 0;
}
