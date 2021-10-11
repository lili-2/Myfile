//
/*
#include<stdio.h>
void swap(int a[],int p,int q)
{
	int temp = a[p];
	a[p] = a[q];
	a[q] = temp;
}
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
			printf("5%d ",a[i]);
}
void perm(int a[],int p,int q)
{
	if(p==q)
	{
		print(a,q+1);	
	}
	else 
	{
		int i;
		for(i=p;i<q;i++)
		{
			swap(a,p,i);
			perm(a,p+1,q);
			swap(a,p,i);
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++)
	{
		a[i] = i+1;
	}
	swap(a,0,n-1);
	return 0;
}*/
/*
#include<stdio.h>
int main()
{
	int n,m,i;
	int a[1001];
	scanf("%d %d",&n,&m);
	while(n!=0&&m!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=(n-1);i>=0;i--)
		{
			if(m>=a[i])
			{
				a[i+1]=m;
				break;
			}
			else
			{
				a[i+1]=a[i];
			}
		}
		for(i=0;i<=n;i++)
		{
			printf("%d",a[i]);
			if(i<n)
				printf(" ");
			else
				printf("\n");			 
		}
		scanf("%d %d",&n,&m);
	} 
	return 0;
}*/
#include<stdio.h>
int main()
{
	int n,i=1,j=0,sum=0,min=9999,ret=0;
	int a[10000];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(i%j==0)
			{
				sum+=j;
			}
		}
		if(sum==n)
		{
			a[i]=i;
			ret=1;
		}
		sum=0;
	}
	for(i=0;i<j;i++)
	{
		printf("%d ",a[i]);
	}
	if(ret==0)
	{
		printf("-1\n");
	}
	else
	{
		for(i=1;i<j;i++)
		{
			if(min>a[i]&&a[i]!=0)
				min=a[i];
		}
		printf("%d\n",min);
	}
	return 0;
}

