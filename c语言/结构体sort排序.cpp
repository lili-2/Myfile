#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)     //��main����ǰ��һ��cmp����bool���Ͷ���
{
	return a>b;         //���شӴ�С������
}
int main()
{
	int a[5]={9,3,2,4,7};

	sort(a,a+5,cmp);     //����cmp
    for(int i=0;i<5;i++)
    printf("%d",a[i]);
    
    return 0;
} 

