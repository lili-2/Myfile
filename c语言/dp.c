/* 
//在arr中选出的数字加起来最大 选中的数字不能相邻 
#include<stdio.h>
int max(a,b)
{
	if(a>b) return a;
	else return b;
}
int rec(int *arr,int i)
{
	int a,b;
	if(i==0)
	    return arr[0];
	else if(i==1)
		return max(arr[0],arr[1]);
	else 
	{
		a = arr[i-2]+arr[i];//选第i个数 
		b = arr[i-1];       //不选第i个数 
	
		return max(a,b);
	}
}
int main()
{
    int arr[7]={1,2,4,1,7,8,3};
    
    printf("%d ",rec(arr,6));
    
} 
*/
#include<stdio.h>
int max(a,b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int arr[7]={1,2,4,1,7,8,3};
	int opt[7]={0,0,0,0,0,0,0};
	int i,a,b;
	
	opt[0] = arr[0];
	opt[1] = max(arr[0],arr[1]);
	for(i=2;i<=sizeof(arr)/4;i++)
	{
		a = opt[i-2]+arr[i];//选第i个数 
		b = opt[i-1];       //不选第i个数 
		opt[i] = max(a,b);  //最优解 
	} 
	printf("最大数为 ");
	printf("是%d",opt[i-1]);
	return 0;
}
