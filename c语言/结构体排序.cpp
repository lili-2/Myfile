//A
#include<stdio.h>
#include<algorithm>
struct sub
{
	char s[1000];
	long long int b;
};
bool comp(sub x,sub y)
{
	return x.b<y.b;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	struct sub arr[1000];
	for(i=0;i<t;i++)
	{
		scanf("%s %lld",arr[i].s,&arr[i].b);	
	}
	std::sort(arr,arr+t,comp);
	for(i=0;i<t;i++) 
	{
		printf("%s ",arr[i].s);
	} 
	return 0;
}

