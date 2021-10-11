/*
#include<stdio.h>
int main()
{
	int n,i,j;	
	while(scanf("%d",&n)!=EOF);
	{
		int a[100][100]; 
		for(i=0;i<n;i++)
		{
			a[i][0]=1;
			a[i][i]=1;
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	} 
	return 0;
} 
*/	//	else if(i==j) printf(" %d",a[i][j]);
/*
#include<stdio.h>
int main()
{
	int n;
	int a[100][100],i,j;
	while(scanf("%d",&n)!=EOF)
	{ 
		for(i=0;i<n;i++)
		{
			a[i][0]=1;
			a[i][i]=1;
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(i==0||j==0&&i!=j)
				{
					printf("%d",a[i][j]);
				}
				else
				{
					printf(" %d",a[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
*/
//Q - ÁúÂè 

#include<stdio.h>
int main()
{
	int  n,i;
	long long max,min,count=0;
	long long v[10000];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	max=v[0];
	min=v[0];
	for(i=1;i<n;i++)
	{
		if(v[i]>max)
			max=v[i];
		if(v[i]<min)
			min=v[i];	
	}  
	for(i=0;i<n;i++)
	{
		if(v[i]!=max&&v[i]!=min)
			count ++;
	}
	printf("%lld",count);
	return 0;
} 

/*
#include<stdio.h>
int main()
{
	int n,k;
	char str[100];
	scanf("%d %d",&n,&k);
	
}
*/
/*
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	if(a%2==0)
		b=a/2;
	else
	{
	
		b=a/2+1;
	}
	printf("%d",b);
	return 0;
}
*/ 
//Êý×ÖÓÎÏ· 
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char n[1000000];
	int ret=0,i=0,len,number;
	scanf("%s",n);
	while(n[i]!='0')
	{
	    len=strlen(n);
		ret=0;
		number=0;
		for(i=0;i<len;i++)
		{
			ret+=n[i]-'0';
		}
		while(ret>0)
		{
			number+=ret%10;
			if(ret<10&&number<10)
				break;
			if(ret<10)
			{
				ret=number;
			}
			ret=ret/10;
		}
		printf("%d\n",number);
		scanf("%s",n);
		i=0;
	}
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[1000][100];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			max=a[i][0];
			if(a[i][j]>max)
			{
				max=a[i][j];
			}
			b[i]==1;
		}
	}
} 
*/ 

