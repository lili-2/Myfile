#include<stdio.h>
int a[100] = {1,6,5,3,2,4};
void quickSort(int left,int right)
{
	int temp = a[temp];
	int i = left,j = right;
	if(left > right)
		return ;
	while(i < j)
	{
		if(a[j] >= temp)
			j--;
		if(a[i] <= temp)
			i++;
		if(a[i] > a[j])
		{
			int c = a[i];
			a[i] = a[j];
			a[j] = c;
		}	
	} 
	a[left] = a[i];
	a[i] = temp;
	
	quickSort(left,i-1);
	quickSort(i+1,right);
}
int main()
{
	quickSort(0,5);
	for(int i = 0;i < 5;i++)
	{
		printf("%d ",a[i]);
	 } 
	return 0;
 } 
