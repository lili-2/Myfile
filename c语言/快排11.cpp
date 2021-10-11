#include<stdio.h>
int a[100] = {1,6,5,3,2,4};
void quickSort(int left,int right); 
int main()
{
	quickSort(0,5);
	for(int i = 0;i < 5;i++)
	{
		printf("%d ",a[i]);
	 } 
	return 0;
} 
void quickSort(int left,int right)
{
	int i = left,j = right,temp = a[left];
	if(left>right)
		return ;
	while(i<j)
	{
		while(a[j]>=temp && i<j)
			j--;
		while(a[i]<=temp && i<j)
			i++;
		if(i<j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;

	quickSort(left,i-1);
	quickSort(i+1,right);
}
