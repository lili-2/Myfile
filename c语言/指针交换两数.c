&a ����������׵�ַ
&a+1 ��һ��������׵�ַ
a ��һ��Ԫ�ص��׵�ַ
a+1 �ڶ���Ԫ���׵�ַ

 
//��������
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
    
    //***r�ȼ���i 
} 
*/ 

