#include <stdio.h> 
int main()
{
 	int n,a1=0,a2=0,a3=0,a4=0;
 	scanf("%d",&n);
 	if(n%2==0)
 	{
 		if(n<=12&&n>4)
 		{
 			a1=1,a2=1;
		}
		else
		{
			a2=1,a3=1;
		}
	}
	else
	{
		if(n<=12&&n>4)
		a3=1;
		else a4=1;
	}
	printf("%d %d %d %d",a1,a2,a3,a4);
	return 0;
}
