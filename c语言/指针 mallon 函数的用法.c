/*
// ָ�� �� mallon�������÷� ��̬�ڴ�


#include <stdio.h>
#include <malloc.h>
               //ͨ��f �޸�*p��ֵ �����ĸ��ֽڵ����ݸ�д 
void f(int *q) //q �� p �Ŀ��� q��p ������һ�� q ��ҲΪ���ĸ��ֽڵ�ַ *q �������ĸ��ֽ� 
{
			    //*p=200;//error p��main��������  ֻ����main��ʹ��
	*q = 200;   //q = 200; // q �� ָ�� ���ͱ����ĵ�ַ
			    //**q = 200;  *q �������ͱ��� ���ܼ�*
    			//free(q);��q��ָ����ڴ��ͷŵ� �ͷŵ����ĸ��ֽڵ��ڴ� ���� �Ͳ��������
	 
}
int main()
{
    int * p = (int *)malloc(sizeof(int)); //sizeof��int������ֵ��int��ռ���ֽ��� 
	*p = 10;
	
	printf("%d\n",*p); //10 
	f(p);  //p�� int *���� 
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
	printf("��������Ҫ��ŵ���Ԫ�صĸ���");
	scanf("%d", &len);
	pArr = (int *)malloc(4 * len);  //��̬�Ĺ��� ������ int pArr[len] 
							//pArrָ���һ���ֽڵĵ�ַ    ����Ϊ int * ָ��ǰ�ĸ��ֽ� ��1�� ָ��ڶ����ĸ��ֽ� 
							//int *)malloc(sizeof(int)*len)	
	for (i=0; i<len; ++i)
	    scanf("%d",&pArr[i]);
	    
	for(i=0; i<len ;++i)
	    printf ("%d\n",pArr[i]);   
	    
	free(pArr);//�ͷŶ�̬��������� 
}
*/ 
//��̬�ڴ�����dui��������
