#include <stdio.h>
struct Ti
{
	int start;
	int end;
}ti;
void quicksort(int left,int right,ti a[])
{
	int i,j,temp;
	ti t,t1;
	if(left > right)
	{
		return;
	}
	temp=a[left].end;
	t1=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j].end>=temp&&i<j)
		{
			j--;
		}
		while(a[i].end<=temp&&i<j)
		{
			i++;
		}
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=t1;
	quicksort(left,i-1,a);
	quicksort(i+1,right,a);
}
int main()
{
	int number,i,j,cnt=1;
	ti time[50001],temp;
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		scanf("%d%d",&time[i].start,&time[i].end);
	}
	quicksort(0,number-1,time);
	for(i=1,j=0;i<number;i++)
	{
		if(time[i].start<time[j].end)
		{
			continue;
		}
		else
		{
			j=i;
			count++;
		}
	}
	printf("%d",count);
	return 0;
}

