/*
#include<stdio.h>
int main()
{
	int n;
	long l;
	long c[1000000];
	int v[10000];
	scanf("%d %ld",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&c[i]);
		v[i]=2^(i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<l;j++)
		if(v[i]*j+)
	}
}
*/


/*
#include<stdio.h>
int main()
{
	int t,n,m,x,y,z;
	int a[1000][1000]={1000};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",n,m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			a[x][y]==z;
		}
		for(i=1;i<n;i++)
		{
			
		}
		
	}
}*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s1[10000];
	while(scanf("%s",s1)!=EOF)
	{
		int i,j=0,l1,l2,count1=0,count2=0,a=0;
		char s1[10000];
		char s2[10000];
		scanf("%s",s1);
		getchar;
		scanf("%s",s2);
		getchar;
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=0;i<l1;)
		{
			if(s1[i]==s2[j])
			{
				count1++;
				i++;
				a++;
			}
			else
			{
				j++;
			}
			if(j>l2)
			{
				i++;
				j=a+1;	
			}	
		}
		j=0;
		for(i=0;i<l2;)
		{
			if(s2[i]==s1[j])
			{
				count2++;
				i++;
				a++;
			}
			else
			{
				j++;
			}
			if(j>l1)
			{
				i++;
				j=a+1;	
			}	
		}
		if(count1>count2)
			printf("%d\n",count1);
		else 
			printf("%d\n",count2);
	}
	return 0;
}
