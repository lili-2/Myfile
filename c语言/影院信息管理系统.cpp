#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
typedef struct Film
{
 	char num[20];
 	char name[20];
 	int money;
 	double score;
 	struct Film *next;
}film,* pFilm;

//void creatList()
//{
//	pfilm pHead = NULL;
//	pHead = (pFilm)malloc(sizeof(film));
//	int val;
//	int
//}

typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users; 


void menu();                              
void Input();
//void creatList();

void menu()
{
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  ***************��ӭ����XXӰԺ****************\n");
	printf("\t\t\t\t  ******************����*************************\n");
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  ********     1.ӰԺ������    ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      2.ӰԺ������Ա     ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      3.ӰԺ��Ʊ��Ա     ***************\n");
	printf("\n"); 
	printf("\t\t\t\t  *******      4.�˿�             ***************\n");
	printf("\n");
	printf("\t\t\t\t  	     ѡ���������:");
}
void Input()
{
	users a,b;
	FILE *fp;
	char temp[20];
	printf("\t\t\t\t  -------------��ӭ����ע����棡-----------------\n");
	Sleep(1000);
	printf("�������û���:");
	scanf("%s",a.id);
	printf("����������:");
	scanf("%s",a.pwd);
	printf("��ȷ������:");
	scanf("%s",temp);
	do
	{
	 	if(!strcmp(a.pwd,temp)){
	 		fp = fopen("D:\\user.text","a");
	        fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("�˺�ע��ɹ������¼��\n"); 
	        Sleep(500);
	        fclose(fp);
			return;
		}else
		{
		 	printf("�������벻ƥ�䣡���������룡\n");
	        scanf("%s",a.pwd);
	        printf("��ȷ������:\n");
	        scanf("%s",temp);
		}
	}while(1);
}
int main()
{
	system("Color fc");
	int n;
	do{
        menu();                                             
        scanf("%d",&n);
		switch(n)
		{
	        case 1:
			    printf("ע��ҳ��\n");
	            Input();
	            break;	
        	default:
            	printf("�����쳣����������������\n");
            	break; 
    	}
    }while(1);
    return 0;
}
