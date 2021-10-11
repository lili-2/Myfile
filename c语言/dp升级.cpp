#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
  if(a>b)return a;
  else return b;
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int a[100][100];
  int d[100][100];
  int N;
  scanf("%d",&N);
  int i,j;
  for(i=0;i<N;i++)
  {
    for(j=0;j<=i;j++)
      scanf("%d",&a[i][j]);
  }
  d[0][0]=a[0][0];
  for(i=1;i<N;i++)
  {
    for(j=0;j<=i;j++)
      d[i][j]=a[i][j]+max(d[i-1][j],d[i-1][j-1]);  
  }
  int ans=max(d[N-1][(N)/2],d[N-1][(N+1)/2]);
  printf("%d",ans);
  
  
  return 0;
}

