#include<stdio.h>
int digui(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else 
		return digui(n-1)+digui(n-2);
}
int main()
{
	int n;
	printf("请问求第几个数");
	scanf("%d",&n);
	printf("该数为");
	printf("%d\n",digui(n));
	return 0; 
}
