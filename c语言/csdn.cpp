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
	printf("������ڼ�����");
	scanf("%d",&n);
	printf("����Ϊ");
	printf("%d\n",digui(n));
	return 0; 
}
