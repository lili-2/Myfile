#include<stdio.h>
int a[100] = {4,1,2,1,1,2};
int b[100] = {3,6,3,3};
int main()
{
	int sum1 = 11;
	int sum2 = 15;
	for(int i = 0;i < 6;i++)
	{
		for(int j = 0;j < 4;j++)
		{
			if(sum1 - a[i] + b[j] == sum2 + a[i] - b[j])
			{
				printf("[%d, %d]",a[i],b[j]);
				return 0;
			}
		}
	}
	printf("[]");
	return 0;
} 
