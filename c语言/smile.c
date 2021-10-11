/*
#include<stdio.h>
int main()
{
    int t,i,year,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&year);
        n=year%4;
        if(n==0)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
        return 0;
    }
}
*/

#include<stdio.h>
int digui(n)
{
    if(n==1) return n;
    else
    {
    	return n+digui(n-1);
	}
} 
int main()
{
	int number;
	scanf("%d",&number);
	printf("%d",digui(number));
}

/*
#include<stdio.h>
int main()
{
    int t,i,year;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&year);
       
        if(year%4 == 0 && year%100 != 0||year%400 == 0)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
        return 0;
    }
}
*/

