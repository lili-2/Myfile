 #include <stdio.h>
 int main()
 {
 	int n,m,day,i,count=0;
 	int a[100000]={0};
 	scanf("%d %d",&n,&m);
 	while(n--)
 	{
 		scanf("%d",&day);
 		for(i=day;i<m+day;i++)
 		{
 			a[i]=1;
		}
	}
	for(i--;i>=0;i--)
	{
		if(a[i]==1)
			count++;
	}
	printf("%d",count);
	return 0;
 }

