/*
#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,count=0,j,l;
	char s[1000];
	scanf("%d",&l);
	getchar();
	gets(s);
	l=l-1;
	while(i<l)
	{
		if(s[i]==s[l])
		{
			i++;
			l--;
		}
		else if(s[i+1]==s[l])
		{
			count++;
			i++;
		}
		else if(s[i]==s[l-1])
		{
			count++;
			l--;
		}
		else 
		{
			count++;
			i++;
		}
	}
	printf("%d",count);
	return 0;
}
*/

