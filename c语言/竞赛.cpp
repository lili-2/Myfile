#include<stdio.h>
#include<string.h>
char s[1005];
int main()
{
	int flag = 1;
	scanf("%s",s);
	strlen(s);
	int i = 0;
	if(s[i]!='a' && s[i]!='e' && s[i]!= 'i' && s[i]!= 'o' && s[i]!='u')
	{
		while(s[++i]!='a' && s[i]!='e' && s[i]!= 'i' && s[i]!= 'o' && s[i]!='u');
		
		while(s[++i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i]=='u');
		while(s[++i]!='a' && s[i]!='e' && s[i]!= 'i' && s[i]!= 'o' && s[i]!='u');
				
	    while(s[++i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i]=='u');
					if(i == strlen(s))
					{
						printf("yes %d",i);
						return 0; 
					}
					else
					{
						printf("no %d\n",i);
						return 0;
					}
		
	}
	else
	{
		printf("no %d\n",i);
		return 0;
	}
	printf("%d ",i);
	return 0;
} 
