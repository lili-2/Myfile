#include<stdio.h>
//如果一个分数的分子和分母的最大公约数是1，这个分数称为既约分数。例如，3/4,5/2,1/8,7/1都是既约分数。
//请问，有多少个既约分数，分子和分母都是1到2020之间的整数（包括1和2020
int zhishu(int a,int b)
{
	int t;
//	if(a<b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
	
		t = a%b;
		while(t>0)
		{
			a = b;
			b = t;
			t = a%b;
		}
		return b;
	
} 
int main()
{
	int i,j;
	long long count=0;
	for(i=1;i<=2020;i++)
	{
		for(j=1;j<=2020;j++)
		{
			if(zhishu(i,j)==1)
			{
				count++;
			}
		}
	}
	printf("%lld",count);
	return 0;
}
