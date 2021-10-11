#include<stdio.h>
int reversr( int number);

int main()
{
    
    int n;
    
    scanf("%d",&n);
    printf("%d\n",reversr(n));
    
    return 0;
}
int reversr( int number)
{
	int a;
	while(number!=0)
	{
		a = a*10 + (number%10);
		number/=10;
	}
	return a;
} 
