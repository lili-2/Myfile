#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//����ͼ����Ϣ�ṹ 
typedef struct book{
	char*name;
	int id;
	int count;
	int status;
	structbook *next;
}
Book *head = NULL;
intnbook =0;

//�����¼��Ա��Ϣ 
typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users;

void menu();//ϵͳ��ҳ�� 

void menu()
{
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  ***************��ӭ����XXͼ���****************\n");
	printf("\t\t\t\t  ******************����*************************\n");
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  *******      1.ͼ�������Ա@_@  ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      2.ѧ��@_@          ***************\n");
	printf("\n");
	printf("\t\t\t\t  	     ѡ���������:");
}


//��¼ע�� 
void Input()
{
	system("read");                        //��ͣ 
	system("cls");
	users a,b;//�ṹ�� The_users ����������
	FILE *fp;
	char temp[20];
	printf("\t\t\t\t  -------------��ӭ����ע����棡-----------------\n");
	                  
	Sleep(1000);
	printf("\t\t\t\t        �������û���:");
	scanf("\t\t\t\t\t\t\t%s",a.id);
	printf("\t\t\t\t         ����������:");
	scanf("\t\t\t\t\t\t\t%s",a.pwd);
	printf("\t\t\t\t         ��ȷ������:");
	scanf("\t\t\t\t\t\t\t%s",temp);
	do
	{
	 	if(!strcmp(a.pwd,temp)){
	 		fp = fopen("D:\\user.text","a");
	        fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("\t\t\t\t        �˺�ע��ɹ������¼��\n"); 
	        Sleep(500);
	        fclose(fp);
	        system("read");                        //��ͣ 
			system("cls");
			return;
		}else
		{
		 	printf("\t\t\t\t        �������벻ƥ�䣡���������룡\n");
	        scanf("\t\t\t\t\t\t%s",a.pwd);
	        printf("\t\t\t\t        ��ȷ������:\n");
	        scanf("\t\t\t\t\t\t%s",temp);
		}
	}while(1);
}
int main()
{
	system("color f0");
	int n;
	while(1)
	{
		menu();
		scanf("\t\t\t\t  %d",&n);
		switch (n)
		{
			case 1:
				Input();
				break;
			default :
				printf("\t\t\t\t  ************�����쳣������������*******************\n");
				break;	
		}
		system("read");                        //��ͣ 
	    system("cls");                          //������û��������ظ�����Ŀ¼���� 
	}
	return 0;
}
