 #include <stdio.h>
 int main()
 {
 	int a=0,i,j=0,n,flag=0;
 	scanf("%d",&n);
 	for(i=0;5*i<=n;i++)
 	{
 		for(j=0;(3*j+5*i)<=n;j++)
 		{
 			a=(n-5*i-3*j)*3;
 			if(i+j+a==100&&flag!=0)
			{
				printf("\n%d %d %d",i,j,a);
				flag++;
			}
 			if(i+j+a==100&&flag==0)
 			{
 				flag++;
 				printf("%d %d %d",i,j,a);
			}
		}
	}
	if(flag==0) printf("No Answer.");
	return 0;
 }

