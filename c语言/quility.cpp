#include <stdio.h>
#include <stdlib.h>

int fun(long long int a[],int n)
{
  int i,j,t;
  for(i=1;i<n;i++)
  {
    t=a[i];
    j=i-1;
    while(j>-1&&a[j]>t)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=t;
  }
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  long long int n,i,min,t,count=0;
  scanf("%lld",&n);
  long long int a[n];
  
  for(i=0;i<n;i++)
  {
    scanf("%lld",&a[i]);
  }
  fun(a,n);
  min=a[n-1]-a[n-2];
  for(i=n-1;i>0;i--)
  {
    t=abs(a[i]-a[i-1]);
    if(t<min)
    {
      min=t;
    }
  }
  if(min==0)
  {
      printf("%d",n);
      return 0;
  }
  while(a[0]!=a[n-1])
  {
    a[0]+=min;
    count++;
  }
  printf("%d",count+1);
  return 0;
}
