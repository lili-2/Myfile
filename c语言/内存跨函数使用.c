#include<stdio.h>
#include<malloc.h>

//��̬�������ܿ纯��ʹ�� 
/* 
void g(int ** q)
{
	int i = 5;
	
	*q = &i ;
}
/* 
int main()
{   int *p;            pָ��һ����ַ  ��p�ĵ�ַ���� q  *q���� p ��i�ĵ�ַ����p pָ��i 
    f(&p);
    printf("%d\n",*p); �﷨û������ �߼���ͨ  i�ں���������ͱ��ͷ��� ��ʱָ���i�ĵ�ַ����û��i ���ܻ�Σ�� 
}
*/ 

//��̬�������Կ纯��ʹ�� 
void f(int ** q)
{
	*q = (int *)malloc(sizeof(int));//�ȼ��� p = (int *)malloc(sizeof(int));
	
	**q = 5; //���������ǳ�ջ�Ĺ��� ��̬�ڴ����ջ�� ��̬�ڴ���ڶ��� 
}

int main()
{
	
    int *p;
    f(&p);
    printf("%d\n",*p);
    
    return 0;
} 
