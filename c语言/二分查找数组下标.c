#include<stdio.h>
int main()
{
	int number,n = 9;
	int mid = n/2;
	int left = 0;
	int right = n-1;
	
	int arr[9]= {1,2,3,4,5,6,7,8,9};
	
	printf("请输入要查找的数\n"); 
	scanf("%d",&number);	
	
	while(left<right)
	{
		if(number==arr[mid])
		{
		    printf("结果是%d",mid);
		    break;
		}
		else if(number>arr[mid])
		{
		    left = mid - 1;
		    printf("%d  ",mid);
		} 
		else
		{
		    right = mid ;
		    printf("%d  \n",mid);
		}
		mid = (left+right)/2;
    }
    
    return 0;
		
} 
