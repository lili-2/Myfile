/* 
#include <stdio.h>
#include <math.h> 
void swap(int *a,int *b,int *c);
int main()
{
  	int a,b,c,t;
  	scanf("%d%d%d",&a,&b,&c);
	if(a+b<c||a+c<b||b+c<a) printf("Not triangle");
	if(a+b>c&&a+c>b&&b+c>a)
	{
		swap(&a,&b,&c);
		if(pow(b,2)+pow(c,2)>pow(a,2)) 
		{
			printf("Acute triangle");
		
		}
		if(pow(b,2)+pow(c,2)==pow(a,2)) 
		{
			printf("Right triangle");
		
		}
	    if(pow(b,2)+pow(c,2)<pow(a,2))
		{
			printf("Obtuse triangle");
		
		} 
		if(a==b||b==c||a==c)
		{
			printf("\n");
			printf("Isosceles triangle");
		}
			if(a==b&&a==c) 
		{
			printf("\n");
			printf("Equilateral triangle");
	    } 
  }
  }
  void swap(int *a,int *b,int *c)
   {
   	int t=*a;
   	if(*a<*b) t=*b;
	else if(*a<*c) t=*c; 
   	if(t!=*a)
	{
	    if(*b>*c)
	    {
	    	t=*b;
	   	    *b=*a;
			*a=t; 
	    }
		else 
		{
			t=*c;
			*c=*a;
			*a=t;
		}	
    } 
}
*/ 
 
//������ 
#include<stdio.h>
int main()
{
	int n,i,j,k,b,count=0;
	scanf("%d",&n);
	int a[1000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0; i<n-1; i++)   
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				
				if(a[i]+a[j]==a[k])
				{
					count++;
				}
			}
		}
	}
	printf("%d",count);
	return 0;
} 

/*

//������ 
#include <stdio.h>
int main()
{
	int a,b,c;
 	scanf("a b c",&a,&b,&c);
	printf("%d %d %d",a,b,c);
	
	if(a<b+c)
	{
  		printf("Not triangle\n");
 	}
	else
	{
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
		{
	   		printf("Right triangle\n");
	  	}
	  	
	  	if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])
		{
	   		printf("Acute triangle\n"); 
	  	}
	  	
		if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])
		{
	   		printf("Obtuse triangle\n");
	  	}
	  	
	  	if(a[0]==a[1])
		{
	   		printf("Isosceles triangle\n");
	  	}
	  	
	  	if(a[0]==a[1]&&a[0]==a[2])
		{
	   		printf("Equilateral triangle\n");
	  	}
	}	
 	return 0;
}
void swap(int *a,int *b,int *c)
   {
   	int t=*a;
   	if(*a<*b) t=*b;
	else if(*a<*c) t=*c; 
   	if(t!=*a)
	{
	    if(*b>*c)
	    {
	    	t=*b;
	   	    *b=*a;
			*a=t; 
	    }
		else 
		{
			t=*c;
			*c=*a;
			*a=t;
		}	
    } 
}
*/

/*
#include<stdio.h>
int main()
{
	int n,i,j,count=0,s=0;
	scanf("%d",&n);
	int a[100][3];
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			s=s+a[i][j];		
		}
		if(s>1)
		{
			count++;
		}
		s=0;
	}
	printf("%d",count);
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int n,i,j,max;
	scanf("%d",&n);
	int a[100];
	int b[100];
	int c[100]={0};
	for(i=1;i<(n+1);i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	c[0]=0;
	for(i=1;i<(n+1);i++)
	{
		c[i]=c[i-1]-a[i]+b[i];
	}
	max=c[0];
	for(i=1;i<(n+1);i++)
	{
		if(c[i]>max) max=c[i];
	}
	printf("%d",max);
	return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
 
int main(){
	int n, a[7], b[1005][7];  // ���� a ��¼�н����� ����ά���� b ��¼ÿ�Ų�Ʊ����
	scanf("%d", &n);
	for(int i=0; i<7; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n; i++){    //���������󣬲���7�� scanf �����룬���͸��Ӷ�
		scanf("%d", &b[i][0]);
		scanf("%d", &b[i][1]);
		scanf("%d", &b[i][2]);
		scanf("%d", &b[i][3]);
		scanf("%d", &b[i][4]);
		scanf("%d", &b[i][5]);
		scanf("%d", &b[i][6]);
	}
	 
	int buf[8];                    //buf ��¼7�������У�ÿ�������н����� 
	memset(buf, 0, sizeof(buf));  //������ buf ȫ���� 0 
	for(int i=0; i<n; i++){        //ѭ������ n �� 
		int flag = 0;              // flag ��¼�м�����ͬ���룬ͬʱ�� buf �±�
		for(int j=0; j<7; j++){    // j ���н��������� a ���±� 
			if(b[i][j] == a[0]) flag += 1;
			if(b[i][j] == a[1]) flag += 1;
			if(b[i][j] == a[2]) flag += 1;
			if(b[i][j] == a[3]) flag += 1;
			if(b[i][j] == a[4]) flag += 1;
			if(b[i][j] == a[5]) flag += 1;
			if(b[i][j] == a[6]) flag += 1;
		}
		buf[flag] += 1;  //flag = 7 ʱ��ʾ�صȽ��� flag = 0 ��ʾû���н� 
	} 
	
	printf("%d ", buf[7]);
	for(i=6; i>0; i--){
		printf("%d ", buf[i]);
	} 
	
	return 0;
}

*/
