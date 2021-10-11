#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//定义图书信息结构 
typedef struct book{
	char*name;
	int id;
	int count;
	int status;
	structbook *next;
}
Book *head = NULL;
intnbook =0;

//定义登录人员信息 
typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users;

void menu();//系统主页面 

void menu()
{
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  ***************欢迎来到XX图书馆****************\n");
	printf("\t\t\t\t  ******************您是*************************\n");
	printf("\t\t\t\t  ***********************************************\n");
	printf("\t\t\t\t  *******      1.图书管理人员@_@  ***************\n");
	printf("\n");
	printf("\t\t\t\t  *******      2.学生@_@          ***************\n");
	printf("\n");
	printf("\t\t\t\t  	     选择你的类型:");
}


//登录注册 
void Input()
{
	system("read");                        //暂停 
	system("cls");
	users a,b;//结构体 The_users 重命名定义
	FILE *fp;
	char temp[20];
	printf("\t\t\t\t  -------------欢迎来到注册界面！-----------------\n");
	                  
	Sleep(1000);
	printf("\t\t\t\t        请输入用户名:");
	scanf("\t\t\t\t\t\t\t%s",a.id);
	printf("\t\t\t\t         请输入密码:");
	scanf("\t\t\t\t\t\t\t%s",a.pwd);
	printf("\t\t\t\t         请确认密码:");
	scanf("\t\t\t\t\t\t\t%s",temp);
	do
	{
	 	if(!strcmp(a.pwd,temp)){
	 		fp = fopen("D:\\user.text","a");
	        fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("\t\t\t\t        账号注册成功，请登录！\n"); 
	        Sleep(500);
	        fclose(fp);
	        system("read");                        //暂停 
			system("cls");
			return;
		}else
		{
		 	printf("\t\t\t\t        两次密码不匹配！请重新输入！\n");
	        scanf("\t\t\t\t\t\t%s",a.pwd);
	        printf("\t\t\t\t        请确认密码:\n");
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
				printf("\t\t\t\t  ************输入异常，请重新输入*******************\n");
				break;	
		}
		system("read");                        //暂停 
	    system("cls");                          //清屏，没有这个会重复出现目录界面 
	}
	return 0;
}
