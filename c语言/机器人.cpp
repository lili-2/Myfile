#include<stdio.h>
#include<math.h>
int shu(int i,long long int j)
{
	int a,b;
	while(i != 0)
	{
		a = i%10;
		b = j%10;
		if(a!=b) return 0;
		i/=10;
		j/=10;
	}
	return 1;
}
int main()
{
	int i,count=0;
	long long int j;
	for(i = 1;i <= 1000;i++)
	{
		j = pow(i,3);
		if(shu(i,j)) 
		{
			count++;
			printf("%d\n",i);
		}
	}
	printf("%d",count);
	return 0;
}

unsigned long long y(int n,int prev) {
	return n > 0 ? y(n - 1,2 * prev - 1) : 2 * prev - 1;
}

