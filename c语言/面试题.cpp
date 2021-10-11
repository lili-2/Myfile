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
//	printf("sum地址%ox\n",p);
//	printf("arr10地址%x\n",i);
//	printf("arr首地址%ox\n",j);
//	
////	printf("%ox\n",j-i);
//	return 0; 
//}
//



/*
#include<stdio.h>
int main()
{
	printf("请输入要判断数字\n");
	int number;	
	scanf("%d",&number);
	
	if (number&1==1) 
	{
	    printf("该数为奇数");
	} 
	else printf("该数是偶数"); 
	
	return 0; 
}
*/



/*
第一题，北京天坛 
#include<stdio.h>
int main()
{

	int n,s,a=9,d=9;
	for(n=1;n<=100;n++)
	{
		if (729/(9*d)==n)// 下层每一层都比中层每一层多9n块砖 
		 break;          //多的总量/每层多的数，得到n为层数 
	}
	n=3*n;
	s=n*a+n*(n-1)/2*d;
	printf("%d",s);
	return 0;
}
/*

/* 
//蜜蜂找房问题
 
#include<stdio.h>
int main()
{
	int n,a,b,c;
	printf("请输入蜜蜂的终点为几号房"); 
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


//果粒橙学长 1-2019 与 2020 互质关系 
/*
#include<stdio.h>
int main()
{
    int a=2020,b,c;
    
    for (b=1;b<2020;b+2)
    {   
			while ((c=a%b)!=0) //a被除数2020 ，b除数，c余数
			{    
			    if (b==1)
			    {
					printf("%d与该数互质",b);
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
//求互质  gcd是欧几里得算法
#include<stdio.h>
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){    
	int number,i,a,b=2020,c;
    for(a = 1; a < 2020;a += 2)
        if(gcd(a, 2020) == 1)
			printf("%d与该数互质\n",a);
	return 0;
}
*/

// 用二分法查找一个数的位置 
//
//#include<stdio.h>
//int main()
//{    
//    int n=8,left,right,key,arr[8]={1,2,3,4,5,6,7,8};
//    
//    printf("请输入要查找的数字");
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
// 第三题 看结构体长度 
#include<stdio.h>
int main()
{    
    int slong; 

	struct S
	{
	   union S1           //  规定： union  共用体 所占内存大小必须是最大类型					    
	   {                  //       (注意不是所占的最大字节数，一定要理解什么是类型，数组不是类型，
	       int a;         //只有int ,double,char 等才是)的整数倍
		   double c;     //共用体需要取整，即 double为八 int为4 char应为8的倍数 即 16
		   char e[13];   
    	}s;
        char a;            // 结构体 字节对齐 规定：每个变量存储时它的起始地址也必须是它类型的整数倍，
		int t;               //char 占用一个字节
	};                      // int t 它必须存到以4的位数开头的地址上，从 20开始 四位即24 
	slong = sizeof(S);       
	printf("%d",slong);

	return 0;
}
*/ 

	
