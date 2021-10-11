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
	printf("\t\t\t\t  ***************欢迎来到XX影院****************\n");
	printf("\t\t\t\t  ******************您是*************************\n");
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  ********     1.影院负责人    ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      2.影院管理人员     ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      3.影院售票人员     ***************\n");
	printf("\n"); 
	printf("\t\t\t\t  *******      4.顾客             ***************\n");
	printf("\n");
	printf("\t\t\t\t  	     选择你的类型:");
}
void Input()
{
	users a,b;
	FILE *fp;
	char temp[20];
	printf("\t\t\t\t  -------------欢迎来到注册界面！-----------------\n");
	Sleep(1000);
	printf("请输入用户名:");
	scanf("%s",a.id);
	printf("请输入密码:");
	scanf("%s",a.pwd);
	printf("请确认密码:");
	scanf("%s",temp);
	do
	{
	 	if(!strcmp(a.pwd,temp)){
	 		fp = fopen("D:\\user.text","a");
	        fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("账号注册成功，请登录！\n"); 
	        Sleep(500);
	        fclose(fp);
			return;
		}else
		{
		 	printf("两次密码不匹配！请重新输入！\n");
	        scanf("%s",a.pwd);
	        printf("请确认密码:\n");
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
			    printf("注册页面\n");
	            Input();
	            break;	
        	default:
            	printf("输入异常！！！请重新输入\n");
            	break; 
    	}
    }while(1);
    return 0;
}
