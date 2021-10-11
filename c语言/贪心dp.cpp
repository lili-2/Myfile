/*
#include<stdio.h>
int b[100000];
int a[1000000];
int main()
{
	int n,m,ret=0,mid,left=0,right=0,i,key,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	i=0;
	while(m--)
	{
		i++;
		ret=0;
		left=0;
		right=n-1;
		while(left<=right)
		{
			
			mid = (right+left)/2;
			if(b[i]==a[mid])
			{
				key=i;
				for(j=1;i-j>0;j++)
				{
					if(b[i-j]==a[mid])
					{
						key=i-j;
					}
					else
						break;
				}
				printf("%d ",key);
				ret=1;
				break;
			}
			else if(b[i]>a[mid])
				left = mid+1;
			else if(b[i]<a[mid]) 
				right = mid-1;
		}
		if(ret==0)
			printf("-1 ");	
	}
	return 0;
}
*/
/*
//ÌÇ¹û 
#include<stdio.h>
int main()
{
	long long number=0,n,x,i;;
	scanf("%lld %lld",&n,&x);
	long long a[100001];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}		
	for(i=0;i<n-1;i++)
	{
		while((a[i+1]+a[i])>x&&a[i+1]>0)
		{
			a[i+1]--;
			number++;
		}
		while((a[i+1]+a[i])>x&&a[i]>0)
		{
			a[i]--;
			number++;
		}
	}
	printf("%lld",number);
	return 0;
}
*/ 
 
//×Ö·û´® Õ¼Î»ÖÃ 
/*
#include<stdio.h>
#include<string.h> 
int main()
{
	int r,c,k,a=0,b=0,m,count=0,i,j;
	char s[1000][1000];
	scanf("%d %d %d",&r,&c,&k);
	getchar();
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;i++)
		{
			scanf("%c",&s[i][j]);
		}
		getchar();
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(s[i][j]=='.')
			{
				for(m=1;m+j<c;m++)
				{
					if(s[i][j+m]=='.')
					{
						a++;
					} 
					else
						break;
				}
				if(a>=1)
					count+=a/k;
				a=0;
				for(m=1;m+i<r;m++)
				{
					if(s[i][j-m]=='.')
					{
						b++;
					} 
					else
						break;
				}
				if(b>=1)
					count+=b/k;
				b=0;
			}
		}
	}
	printf("%d",count);
	return 0;
}
*/

#include<stdio.h>
#include<algorithm>
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int a[1000000];
	int b[1000000];
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	std::sort[a,m];
	std::sort[b,n];
	for(i=0;i<n;i++)
	{
		if()
	}
} 
