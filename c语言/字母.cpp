#include<stdio.h>
#include<math.h>
int main()
{
	int n,k = 0,count = 0;
	scanf("%d",&n);
	for(int i = n;i >= 0;i--)
	{
		for(int j = n;j >= 0;j--)
		{
			k = n - i - j;
			while(k > 0)
			{
				if(k < abs(i - j))
				{
					count++;
					printf("%d %d\n",k,count);
				}
				i = j;
				j = k;
				k--;
			}
		}
	}
	return 0;
}
 
