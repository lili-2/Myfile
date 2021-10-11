#include<stdio.h>
void print_subset(int n,int *a,int cur)
{
	for(int i = 0;i < cur;i++)
		printf("%d ",a[i]);
	printf("\n");
	int s = cur ? a[cur-1]+1 : 0;//确定当前元素的最小可能数
	for(int i = s; i < n; i++)
	{
		a[cur] = i;
		print_subset(n,a,cur+1);
	 } 
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int n =5, cur = 0;
	print_subset(n,a,cur);
	return 0;
 } 
