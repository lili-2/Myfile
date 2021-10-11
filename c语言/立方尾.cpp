#include<stdio.h>
#include<math.h>
int shu(int i,int j)
{
  int key = 0;
    int a,b;
    while(i != 0)
    {
        a = i%10;
        b = j%10;
        if(a!=b)
    {
      key = 1;
      break;
    }
        i/=10;
        j/=10;
    }
  if(key==1)
  {
    return 0;
  }
    else return 1;
}
int main()
{
    int i,count=0;
    long long j;
    for(i = 1;i < 10000;i++)
    {
        j = pow(i,3);
        if(shu(i,j)==1) count++;
        
    }
    printf("%d",count);
    return 0;
}
