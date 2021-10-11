/*
#include<stdio.h>
int main()
{
	int n,m,i,j,k,l,key=0;
	scanf("%d",&n);
	for(l=0;l<n;l++)
	{
		scanf("%d",&m);
		for(j=m/5;j>=0;j--)
		{
			for(k=m/7;k>=0;k--)
			{
				for(i=m/3;i>=0;i--)
				{
					printf("%d %d %d\n",k,j,i);
					if(i*3+j*5+k*7==m)
					{
						printf("%d %d %d\n",i,j,k);
						key=1;
						break;
					}
				} 
				if(key==1)
				{
					break;
				}
			} 
			if(key==1) 
			{
				break;
			}
		}
		
		if(key==0)
			printf("-1\n");
		key=0;
	}
	return 0;
}
*/


/*
#include<stdio.h>
int main()
{
	int i,j,z;
	int l,n,k,temp,max=0,min=0;
	int a[1000];
	scanf("%d",&l);
	for(z=0;z<l;z++)
	{
		scanf("%d %d",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]<a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			} 
		}
		max=a[0];
		
		for(i=1;i<=k;i++)
		{
			max=max+a[i];
		}
		min=0;
	
		printf("%d\n",(max-min));
	}
	return 0;
}
*/
//ËØÊýÌâÄ¿ 
/* 
#include <stdio.h>
 int main()
 {
 	int i,j,k=0,flag=1,count=0,c=0;
 	int arr[10000]={0};
 	int n,h=0,t;
 	for(i=2;i<10000;i++)
 	{
 	    for(j=2;j<=i-1;j++)
		{
		 	if(i%j==0) flag=0;
		}
		if(flag==1)
		{
			arr[k]=i;
			k++;
			count++;
		}
		flag=1; 
	}
	scanf("%d",&n);
 	while(n!=0&&n%2==0)
 	{
 	  for(k=0;k<count-2;k++)
	   {
	   	    for(t=k+1;t<count-1;t++)
	   	    {
	   	    	if(arr[k]+arr[t]==n) 
	   	    	{
	   	    		h++;
				}
		    }
	   }
	   printf("%d\n",h);
	   h=0;
	   scanf("%d",&n);
	   c++;	
	}
	return 0;
 }*/
 #include<stdio.h>
#include<string.h>
int main()
{
	char n[1001];
	int ret=0,i=0,len,number;
	scanf("%s",n);
	while(n[i]!='0')
	{
		i=0;
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
	}
	return 0;
} 
