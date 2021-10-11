#include<stdio.h>
struct gold
{
	int m;
	int v;
	double p;
};
int main()
{
	int n,t,i,j;
	double value=0;
	struct gold temp;
	scanf("%d %d",&n,&t);
	struct gold arr[1000];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].m,&arr[i].v);
		arr[i].p = arr[i].v/arr[i].m*1.0;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j].p<arr[j+1].p)
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d %lf\n",arr[i].m,arr[i].v,arr[i].p);
	}
	for(i=0;i<n;)
	{
		if(t>=arr[i].m)
		{
			value += arr[i].p*arr[i].m;	
			t = t-arr[i].m;
			i++;
		}
		else
		{
			value += arr[i].p*t;
			break;
		}
	}
	printf("%.2lf",value);
	return 0;
} 
