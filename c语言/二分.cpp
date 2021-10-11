#include<stdio.h>
int a[6] = {0,1,2,3,4,5};
void fn(int left,int right,int number);
int main()
{
	int number; 
	int n = 6,left = 0,right = 6;
	scanf("%d",&number);
	fn(0,6,number);
	return 0; 
}
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

//}
void fn(int left,int right,int number)
{
	int mid = (left + right)/2;
	while(left <= right)
	{
		if(number>a[mid])
		{
			left = mid;
		}
		if(number<a[mid])
		{
			right = mid + 1;
		}
		if(number = a[mid])
		{
			printf("%d",mid);
			return;
		}
	}
	printf("no");
	return; 
}
