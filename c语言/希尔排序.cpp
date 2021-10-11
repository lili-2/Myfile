#include<stdio.h>
void print_arr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void shell_sort(int arr[], int n)
{
	int i,j,inc,key;
	// 初始增量: n / 2 ,每一趟之后除以二 
	for(int inc = n/2; inc > 0; inc /= 2)
	{
		for(i = inc;i < n;i++)
		{
			key = arr[i];
			for( j = i;j >= inc && key < arr[j - inc];j -= inc)
				arr[j] = arr[j - inc];
			arr[j] = key;
		}
		print_arr(arr, n);
	}
}
int main()
{
	int arr[] = {15, 5, 2, 7, 12, 6, 1, 4, 3, 9, 8, 10};
	print_arr(arr, 12);
	
	shell_sort(arr, 12);
	
	return 0;
}
