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
		if(k==0)
		{
			min=a[0];
		}
		else
		{
			min=0;
		}
	
		printf("%d\n",(max-min));
	}
	return 0;
}

