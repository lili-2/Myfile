#include<stdio.h>
//���һ�������ķ��Ӻͷ�ĸ�����Լ����1�����������Ϊ��Լ���������磬3/4,5/2,1/8,7/1���Ǽ�Լ������
//���ʣ��ж��ٸ���Լ���������Ӻͷ�ĸ����1��2020֮�������������1��2020
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
