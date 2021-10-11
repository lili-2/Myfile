#include<stdio.h>
int main()
{
	int d[] = {10,9,8,7,6,5,4,3,2,1,0},*p = d;
	printf("%5d %5d",*(p+5),*p+5);
	return 0; 
 } 
