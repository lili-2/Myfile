#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)     //在main函数前加一个cmp，用bool类型定义
{
	return a>b;         //返回从大到小的排序
}
int main()
{
	int a[5]={9,3,2,4,7};

	sort(a,a+5,cmp);     //加上cmp
    for(int i=0;i<5;i++)
    printf("%d",a[i]);
    
    return 0;
} 

