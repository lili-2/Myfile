#include<stdio.h>
int ? main(){
  double?a0,a1,sumTi=0,sumTi2=0,sumRi=0,TiRi=0;
  double?T[100],R[100];
  int?n,m,i,j;
  printf("输入数据的个数n:");
  scanf("%d",&n);
  printf("输入各组数据T[i]与R[i]:\n");?
  m=n;
  i=0;j=0;
  while(n--){
  scanf("%lf%lf",&T[i],&R[i++]);
  }
printf("%d\n",i);
for(j=0;j<i;j++){
sumTi+=T[j];
sumRi+=R[j];
sumTi2+=T[j]*T[j];
TiRi+=T[j]*R[j];
}
a0=-(sumTi*TiRi-sumTi2*sumRi)/(m*sumTi2-sumTi*sumTi);
a1=(m*TiRi-sumTi*sumRi)/(m*sumTi2-sumTi*sumTi);
printf("a0=%.3lf  a1=%.3lf\n",a0,a1);
printf("最小二乘拟合曲线为:R=%.3lf+%.3lfT\n",a0,a1);
return 0;
}

