#include "stdio.h"

void fun1(void)
{
?? ?printf("fun1 \r\n");?? ?
}?
void fun2(void)
{
?? ?printf("fun2 \r\n");?? ?
}
void fun3(void)
{
?? ?printf("fun3 \r\n");?? ?
}

int main()
{
	int i=0;
	void (*p1)(void)=NULL;
	void (*p2)(void)=NULL;
	void (*p3)(void)=NULL;?? ?
	void(*p_arry[3])(void)={NULL,NULL,NULL};
	p1=fun1;
	p2=fun2;
	p3=fun3;
	p_arry[0]=p1;
	p_arry[1]=p2;
	p_arry[2]=p3;
	for(i=0;i<3;i++)
	{
		(*(p_arry+i))();
?? ?}
?? ?printf("*************************\r\n");
?? ?p1();
?? ?p2();
?? ?p3();
?? ?return 0;
?}?
��������������������������������
��Ȩ����������ΪCSDN������Tim-For-Yang����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_23117727/article/details/103908894
