/* 
#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,b,min,max,number,ret=1;
	int a[26]={0};
	char s[100];
	scanf("%s",&s);
	while(s[i]!='\0')
	{
		b=s[i]-'a';
		a[b]+=1;
		i++;		
	}

	for(i=0;i<26;i++)
	{
		if(a[i]!=0)
		{
			min=a[i];
			break;
		}
	}
	for(i=0;i<26;i++)
	{
		if(a[i]<min&&a[i]!=0)
			min=a[i];
	}
	max=a[0];
	for(i=0;i<26;i++)
	{
		if(a[i]>max)
			max=a[i];
	} 
	number = max - min;
	for(i=2;i<number;i++)
	{
		if(number%i==0)
		{
			ret = 0;
			break;
		}
	}
	if(ret==0||max==min||number==1)
		printf("No Answer\n0");
	else	if(ret==1)
		printf("Lucky Word\n%d",number);
	return 0;
}
*/
