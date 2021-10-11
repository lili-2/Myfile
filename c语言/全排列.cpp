#include<stdio.h>
void swap(int a[],int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void prin(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void perm(int a[],int p,int q)
{
	if(p==q)
	{
		prin(a,q+1);
	} 
	else
	{
		int i;
		for(i=p;i<=q;i++)
		{
			swap(a,p,i);
			perm(a,p+1,q);
			swap(a,p,i);
		}
	}
} 	
int main()
{
	int a[4] = {1,2,3,4};
	perm(a,0,3);
	return 0;
}
