//#include<stdio.h>
//int add(int i)
//{
//	i++;
//	return i;
//}
//int main()
//{
//	int a[10] = {1,2,3,4,5,6,7,8,9,20};
//	for( int i=0;i<10;i++)
//	{
//		a[i] = add(a[i]);
//		printf("%d  ",a[i]);
//	}
//	return 0;
//}
#include<stdio.h>
int a[105][105];
int main()
{
  int n,i,j;
  scanf("%d",&n);
  for(i = 0;i < n;i++)
  {
    for(j = 0;j <= i;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  for(i = n-2;i >= 0;i--)
  {
    for(j = 0;j <= i;j++)
    {
      a[i][j] += (a[i+1][j]>a[i+1][j+1])? a[i+1][j] : a[i+1][j+1];
    }
}
  printf("%d",a[0][0]);
  return 0;
}

