#include<stdio.h>
#include<malloc.h>

//静态变量不能跨函数使用 
/* 
void g(int ** q)
{
	int i = 5;
	
	*q = &i ;
}
/* 
int main()
{   int *p;            p指向一个地址  把p的地址传给 q  *q就是 p 把i的地址赋给p p指向i 
    f(&p);
    printf("%d\n",*p); 语法没有问题 逻辑不通  i在函数结束后就被释放了 此时指向的i的地址里面没有i 可能会危险 
}
*/ 

//动态变量可以跨函数使用 
void f(int ** q)
{
	*q = (int *)malloc(sizeof(int));//等价于 p = (int *)malloc(sizeof(int));
	
	**q = 5; //函数调用是出栈的过程 静态内存存在栈中 动态内存存在堆中 
}

int main()
{
	
    int *p;
    f(&p);
    printf("%d\n",*p);
    
    return 0;
} 
