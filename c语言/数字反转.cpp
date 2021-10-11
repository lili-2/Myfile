#include<stdio.h>
int fanzhuan(int a)
{
	int number=0,b=0;
	while(a!=0)
	{
		b = a%10;
		number = number*10 + b;
		a=a/10;
//		printf("%d\n",a);
	}
//	printf("%d\n",a);
	return number;
}

unsigned long long f(int n){
	return 2 << n - 1;
}
unsigned long long y(int n,int prev) {
	return n > 0 ? y(n )
}

unsigned long long y(int n,int prev) {
	return n > 0 ? y(n - 1,2 * prev - 1) : 2 * prev - 1;
}

//int main()
//{
//	int a;
//	scanf("%d",&a);
//	int b = fanzhuan(a);
//	printf("%d\n",b);
//	return 0;}

int main()
{
	int count=0;
    int number = 0;
	for(int i = 11;i<200;i++)
	{
		number = i;
		count=0;
		while(number!=fanzhuan(number))
		{
			count++;
			number = number + fanzhuan(number);
		}
		printf("%d %d %d\n",i,number,count);
	}
	return 0;
}

