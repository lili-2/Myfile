#include<stdio.h>
#include<malloc.h>
void select(int a[], int n, int *s1, int *s2)
{
    if(a[1] > a[2]){
        * s1 = 2;
        * s2 = 1;
    }
    * s1 = 1;
    * s2 = 2;
    for(int i = 2;i <= n;i++){
        printf("%d %d\n",a[i],a[*s1]);
        if(a[i] < a[*s1]){
            *s2 = *s1;
            *s1 = i;
        }
    }
}

int main(){
    int a[10]= {5,4,8,2,1};
    int s1,s2;
    select(a,5,&s1,&s2);
    printf("%d %d",s1,s2);
    return 0;
}