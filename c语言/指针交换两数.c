&a 整个数组的首地址
&a+1 下一个数组的首地址
a 第一个元素的首地址
a+1 第二个元素首地址

 
//交换变量
#include <stdio.h>
void f(int *a,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	
	
	
}
int main()
{
	int a=1;
	int b=2;
	f(&a,&b);
	printf("%d %d",a,b);
	
} 



/* 
#include<stdio.h>
int main()
{
    int i =	10;
    int * p = &i;
    int ** q = &p;
    int *** r = &q;
    
    //***r等价于i 
} 
*/ 

