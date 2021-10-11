#include<stdio.h>
int a[100000],b[100000];
int main()
{
	int n,flag=1,t=2,j,k,i,p=0;
 	scanf("%d",&n);
 	a[0]=1,a[1]=1;
 	for(i=2;i<n;i++)
 	{
 		if(a[i]==0)
 		{
 			b[p++]=i;
 			for(j=2*i;j<n;j+=i)
 			{
 				if(a[j]==0)
 				{
 					a[j]=1;
				}
			}
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=i;j<p;j++)
		{
			for(k=j;k<p;k++)
			{
				if(b[i]+b[j]+b[k]==n)
				{
					printf("%d %d %d",b[i],b[j],b[k]);
					flag = 0;
					break;
				}
			}
				if(flag==0)
				break;
		}
		if(flag==0)
			break;
	}
	return 0;
}
