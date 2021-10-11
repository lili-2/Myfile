/*
// 指针 ； mallon函数的用法 动态内存


#include <stdio.h>
#include <malloc.h>
               //通过f 修改*p的值 将这四个字节的内容改写 
void f(int *q) //q 是 p 的拷贝 q和p 的内容一样 q 中也为那四个字节地址 *q 代表这四个字节 
{
			    //*p=200;//error p在main函数定义  只能在main中使用
	*q = 200;   //q = 200; // q 是 指针 整型变量的地址
			    //**q = 200;  *q 代表整型变量 不能加*
    			//free(q);把q所指向的内存释放掉 释放掉那四个字节的内存 后面 就不会输出了
	 
}
int main()
{
    int * p = (int *)malloc(sizeof(int)); //sizeof（int）返回值是int所占的字节数 
	*p = 10;
	
	printf("%d\n",*p); //10 
	f(p);  //p是 int *类型 
	printf("%d\n",*p);//200 
	
	return 0;	
} 
*/

/* 
# include <stdio.h>
# include <malloc.h>

int main()
{
	//int a[5];
	int len;
	int * pArr;
	int i;
	printf("请输入你要存放的与元素的个数");
	scanf("%d", &len);
	pArr = (int *)malloc(4 * len);  //动态的构造 类似于 int pArr[len] 
							//pArr指向第一个字节的地址    类型为 int * 指向前四个字节 加1后 指向第二个四个字节 
							//int *)malloc(sizeof(int)*len)	
	for (i=0; i<len; ++i)
	    scanf("%d",&pArr[i]);
	    
	for(i=0; i<len ;++i)
	    printf ("%d\n",pArr[i]);   
	    
	free(pArr);//释放动态分配的数组 
}
*/ 
//动态内存是在dui里面分配的
