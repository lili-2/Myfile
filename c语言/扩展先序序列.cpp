#include<stdio.h>
int main()
{
    char a[30];
    char c;
    int i;
    scanf("%c",&c);
    do{
        a[i] = c;
        i++;
    }while(c != EOF);
    printf("%d",i);
    i= 0 ;
   	for(i = 0;i < 9;i++){
	printf("%c %d\n",a[i],i);
   }
    return 0; 
}
