#include<stdio.h>
struct number
{
	int a;
	int b;
}; 
int main()
{
	int n,i,max,key=0,j;
	scanf("%d",&n);
	struct number arr[50005];
	struct number temp;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].a,&arr[i].b);
	}	
	max = arr[0].b;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j].a>arr[j+1].a)
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(arr[i].b>max)
			max = arr[i].b;
	}
	if(arr[n-1].b>max)
		max = arr[i].b;
	for(i=0;i<n-1;i++)
	{
		if(arr[i].b<=arr[i+1].b)
			key++;
		else
			break;
	}
	if(key==n-1)
		printf("%d %d\n",arr[0].a,max);
	else
		printf("no\n");
	return 0;
} 
