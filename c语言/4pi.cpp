#include<stdio.h>
  int main()
  {
  	int i;
  	double e,sum=0.0,flag=1.0;
  	scanf("%lf",&e);
  	for(i=1;;i+=2)
  	{
  		sum+=flag/i;
  		flag=-flag;
  		if(1.0/i<e)	
  			break;
	}
	  printf("pi=%.6lf",sum*4);
	  return 0;
  }

