#include<stdio.h>
int shu(int a)
{
	int b = 0;
	while(a != 0)
	{
		b = a%10;
		a = a/10;
		if(b == 2||b == 4)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int i,j,a=2019,count = 0;
	for(i = 1; ;i++)
	{
		if(shu(i))
		{
			for(j = i+1; ;j++)
			{
				if(shu(j))
				{
					a = 2019 - i - j;
					if(a > i&& a> 673&&j<a)
					{
						if(shu(a))
						{
							count++;
						}
					}
					else break;
				}
			}	
		}
		if(a<=i) break;
	}
	printf("%d",count);
	return 0;
}
