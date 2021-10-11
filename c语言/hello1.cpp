/*
#include<stdio.h>
#include<string.h>
#include<math.h>
long long jinzhi(long long l,char * s,int b)
{
	long long i,number=0;
	for(i=l-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			number+=(s[i]-'0')*pow(b,l-1-i);
		}
		else
		{
			number+=(s[i]-'A'+10)*pow(b,l-1-i);
		}
	}
	return number;
}
int main()
{
	long long int i=0,l; 
	int b;
	char s3[10000];
	long long number1=0,number2=0,number=0;
	scanf("%d",&b);
	char s1[10000];
	char s2[10000];
	scanf("%s",s1);
	scanf("%s",s2);
	l=strlen(s1);
	number1=jinzhi(l,s1,b);
	l=strlen(s2);
	number2=jinzhi(l,s2,b);
	number=number1+number2;
	while(number!=0)
	{
		if(number%b>9)
			s3[i] = number%b -10 + 'A';
		else
			s3[i] = number%b + '0';
		number/=b;
		i++;
	}
	l=strlen(s3);
	for(i=l-1;i>=0;i--)
	{
		printf("%c",s3[i]);
	}
	return 0;
}*/

