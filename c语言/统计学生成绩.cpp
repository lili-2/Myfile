
#include<stdio.h>

void sort(int *a,int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main()
{
    int a[6]={10,2,8,-8,11,0};
	int i = 0;
	
	
	sort(a,6);
	
	for(i=0;i<6;i++)
	{
		printf("%d ",a[i]);
	}	
	printf("\n");
} 
*/



#include<stdio.h>
#include<malloc.h>

struct student
{
	int age;
    float score;
	char name[100];
};

int main(void)
{
	int len;
    struct student  * parr;
	int i;
	int j;
	struct student t;
	
	printf("������ѧ���ĸ���\n");
	scanf("%d",&len);
	
	parr = (struct student *)malloc(len * sizeof(struct student));
	
	for(i=0;i<len;i++)
	{
		printf("�������%d��ѧ������Ϣ",i+1);
		printf("���� ");
		scanf("%d",&parr[i].age);
		
		printf("name= ");
		scanf("%s",parr[i].name);//name����������������Ѿ���������Ԫ�صĵ�ַ������parr[i].name
		
		printf("scare = ");
		scanf("%f",&parr[i].score) ;		
	}
	
	//��ѧ���ɼ�����
	for(i=0;i<len-1;i++)
	{
	    for(j=0;j<len-1-i;j++)
		{
		    if(parr[j].score>parr[j+1].score)
			{
				t = parr[j];
				parr[j]=parr[j+1];
				parr[j+1]=t;
			}	
		} 
	}
	for(i=0;i<len;i++)
	{
		printf("��%d��ѧ������Ϣ",i+1);
	
		printf("%d\n",parr[i].age);
		

		printf("%s",parr[i].name);//name����������������Ѿ���������Ԫ�صĵ�ַ������parr[i].name
		
	
		printf("%f",parr[i].score) ;		
		
		printf("\n");
	}
}
