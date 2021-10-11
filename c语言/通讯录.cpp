#include <stdio.h>
#include<string.h>
  struct People
  {
  	char name[10];
  	char data[11];
  	char c;
  	char num1[16];
  	char num2[16];
  };
  int main()
  {
  		struct People people[11];
  		int n,i,m;
  		int a[11];
  		scanf("%d",&n);
  		for(i=0;i<n;i++)
  		{
  			scanf("%s %s %c %s %s",people[i].name,people[i].data,&people[i].c,people[i].num1,people[i].num2);
		}
		for(i=0;i<n;i++)
	    {
			printf("%s %s %c %s %s\n",people[i].name,people[i].num1,people[i].num2,people[i].c,people[i].data);
		}
  		scanf("%d",&m);
  		for(i=0;i<m;i++)
  		scanf("%d",&a[i]);
  		for(i=0;i<m;i++)
  		{
  			if(a[i]>=n) printf("Not Found\n");
  			else printf("%s %s %c %s %s\n",people[i].name,people[i].num1,people[i].num2,people[i].c,people[i].data);
		}
		return 0;
  }

