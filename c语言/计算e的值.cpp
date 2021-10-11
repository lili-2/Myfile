#include <stdio.h>
#include <math.h>
int main()
{
	int i=1,j=1;
	double sum=0;
	while(1.0/i>=0.0000001)
 	{
 		sum+=1.0/i;
 		i=i*j;
		j++;	
	}
	printf("e=%.8lf\n",sum);
	return 0;
 }

