//#include<stdio.h>
//int main()
//{
//	int a[5] = {1,2,3,4,5};
//	int * ptr = (int *)(&a + 1);
//	printf("%d %d",(a+1),*(ptr-1));
//	return 0;
//} 
#include<stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr = (int*)(a + 1);
	printf("%d %d %d",a,(a+1),*(ptr-1));
	return 0;
} 

//#include<stdio.h>
//int main()
//{
//	int sum = 0;
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int i;
//	int *p=&sum;	
//	int *j=arr;
////	int *i=arr-10;
//	*(&arr+1)=(1+10)*10/2;
//	//for(i=-13;i<13;i++)
//	
//    //{
//    //    if (&sum==arr+i) printf("%d",i);
//      
// //   }
//	
//	printf("%d\n",sum);
//	printf("sum��ַ%ox\n",p);
//	printf("arr10��ַ%x\n",i);
//	printf("arr�׵�ַ%ox\n",j);
//	
////	printf("%ox\n",j-i);
//	return 0; 
//}
//



/*
#include<stdio.h>
int main()
{
	printf("������Ҫ�ж�����\n");
	int number;	
	scanf("%d",&number);
	
	if (number&1==1) 
	{
	    printf("����Ϊ����");
	} 
	else printf("������ż��"); 
	
	return 0; 
}
*/



/*
��һ�⣬������̳ 
#include<stdio.h>
int main()
{

	int n,s,a=9,d=9;
	for(n=1;n<=100;n++)
	{
		if (729/(9*d)==n)// �²�ÿһ�㶼���в�ÿһ���9n��ש 
		 break;          //�������/ÿ���������õ�nΪ���� 
	}
	n=3*n;
	s=n*a+n*(n-1)/2*d;
	printf("%d",s);
	return 0;
}
/*

/* 
//�۷��ҷ�����
 
#include<stdio.h>
int main()
{
	int n,a,b,c;
	printf("�������۷���յ�Ϊ���ŷ�"); 
	scanf("%d",&n);
	if(n==2)
	{
		printf("1\n");
	}
	else if(n==3)
	{
		printf("2\n");     
	}
	else{
		a = 1;
		b = 2;
		n = n-3;
		while(n--){
			c = a+b;
			a = b;
			b = c;
		}
		printf("%d\n",c);
	}
	return 0;
}
*/ 


//������ѧ�� 1-2019 �� 2020 ���ʹ�ϵ 
/*
#include<stdio.h>
int main()
{
    int a=2020,b,c;
    
    for (b=1;b<2020;b+2)
    {   
			while ((c=a%b)!=0) //a������2020 ��b������c����
			{    
			    if (b==1)
			    {
					printf("%d���������",b);
				    break;
			    }
     	        a=b;
    	        b=c;
    	    } 
   	}
	return 0;	 	
} 
*/
/*
//����  gcd��ŷ������㷨
#include<stdio.h>
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){    
	int number,i,a,b=2020,c;
    for(a = 1; a < 2020;a += 2)
        if(gcd(a, 2020) == 1)
			printf("%d���������\n",a);
	return 0;
}
*/

// �ö��ַ�����һ������λ�� 
//
//#include<stdio.h>
//int main()
//{    
//    int n=8,left,right,key,arr[8]={1,2,3,4,5,6,7,8};
//    
//    printf("������Ҫ���ҵ�����");
//	scanf("%d",&key); 
//	left = 0;
//	right = n-1;
//	
//	while(left<=right)
//	{    
//		int mid = (left+right)/2;
//		if (key==arr[mid])  
//		{
//		 printf("%d",mid);
//		 break;
//    	}
//	//	else if (key>arr[mid]) left=mid;
//		else if (key>arr[mid]) left=mid;
//	//	else right=mid-1; 
//		else right=mid+1; 
//		printf("left=%d right=%d\n",left,right);
//	}
//	return 0;
//}
//

/* 
// ������ ���ṹ�峤�� 
#include<stdio.h>
int main()
{    
    int slong; 

	struct S
	{
	   union S1           //  �涨�� union  ������ ��ռ�ڴ��С�������������					    
	   {                  //       (ע�ⲻ����ռ������ֽ�����һ��Ҫ���ʲô�����ͣ����鲻�����ͣ�
	       int a;         //ֻ��int ,double,char �Ȳ���)��������
		   double c;     //��������Ҫȡ������ doubleΪ�� intΪ4 charӦΪ8�ı��� �� 16
		   char e[13];   
    	}s;
        char a;            // �ṹ�� �ֽڶ��� �涨��ÿ�������洢ʱ������ʼ��ַҲ�����������͵���������
		int t;               //char ռ��һ���ֽ�
	};                      // int t ������浽��4��λ����ͷ�ĵ�ַ�ϣ��� 20��ʼ ��λ��24 
	slong = sizeof(S);       
	printf("%d",slong);

	return 0;
}
*/ 

	
