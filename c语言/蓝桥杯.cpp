#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int x=2,y=10;
  int i;
  for(i=1;i<=6;i++)
  {
     if(i%2==1)
       y=y-x;
     if(i%6==0)
     x=x*2;
     if(i%4==0)
     y=y*2;
  }
  printf("%d",y);
  return 0;
}
//#include<stdio.h>
//int main()
//{
//	inx1 = 10,x2 = 0,y = 89,n = 120;
//	while(n--)	
//	{
//		if(n%6 == 0)
//		{
//			x2 = x;
//		}
//		if(n%6 - 1 == 0)
//		{
//			y = y - x2;
//		}
//		if(n%2 == 0)
//		{
//			y = y - x1;
//		}
//	}
//} 
