#include <stdio.h>
 #include <algorithm>
 using namespace std;
 int a[1000000]; 
 int main()
 {
 	int n,i=0,j=0,t,count=0;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	}
 	sort(a,a+n); 
 	i=0;
	while(j<=n/2)
	{
		if(a[n/2+i]/a[j]>=2)
		{
			count++;
			i++;
			j++;
		}
		else 
		{
			i++;
		}
		if(i==n) break;
	}
	printf("%d",n-count);
	return 0;
 }

