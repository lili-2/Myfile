#include<stdio.h>
#include<string.h>
int main()
{
	char b[] = "Hello\0,\0";
	
	char * a = b;
	char c[255] = {0}; 
	
	printf("strlen(b) = %d\n",strlen(b)); 
	printf("strlen(b) = %d\n",sizeof(b));
	
	printf("strlen(b) = %d\n",strlen(a));
	printf("strlen(b) = %d\n",sizeof(a));
	
	printf("strlen(b) = %d\n",strlen(c));
	printf("strlen(b) = %d\n",sizeof(c));
	
	return 0; 
}
