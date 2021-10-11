 /*¿ìËÙÅÅĞò*/ 
 #include <stdio.h>
 int a[10001];
 void quicksort(int left,int right);
 int main()
 {
 	int n,i;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
 } 
 void quicksort(int left,int right)
 {
 	int i,j,t,temp;
 	i=left;
 	j=right;
 	temp=a[left];
 	if(left>right)
 	return;
 	while(i!=j&&i<j)
 	{
	 	while(a[j]>=temp&&i<j)
	 	j--;
	 	while(a[i]<=temp&&i<j)
	 	{
	 		i++;
		}
		printf(" i = %d j = %d\n",i,j);
		if(i<j )
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}	
	}
	printf("%d %d %d %d %d\n",a[i],a[j],i,j,temp);
	a[left]=a[i];
	a[i]=temp;
	for(int i = left;i<right;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	quicksort(left,i-1);
	quicksort(i+1,right); 
 }

