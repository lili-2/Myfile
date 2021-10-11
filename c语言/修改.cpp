#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct book
{
	int id;
    char name[100];
    int count;
    int status;
    struct book *next;
}book;
//定义登录人员信息 
typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users;
void zjts()//增加图书
{
	FILE*fp;
	char i;
	int many=0;
    float price=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen("library.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
	fp=fopen("library.txt","a");
	
	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 出版社 类别 进库量 单价");
	
	for(;i!=27;)//为了实现输入一次后按esc退出
	{
		printf("请输入:\n");
		scanf("%s%s%s%s%s%d%f",num,nam,aut,pub,cat,&many,&price);
		fprintf(fp,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",num,nam,aut,pub,cat,many,price);
	    printf("继续输入请按回车，结束输入请按Esc\n");
        i=getch();//暂停程序当i接收后继续下一条指令
        for (;i!=13&&i!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
        i=getch();
     }

	fclose(fp);
    printf("\n保存成功，按任意键返回上一层!");
    getch();
	tsmain();//返回上一层
}
void output_book()
{
	char name[11];
	book* head, * r, * s, * p;
	FILE* fp = fopen("booklist.txt", "rt");      //打开文件
	head = (book*)malloc(sizeof(book));
	head->next = NULL;                            //建立头结点
	r = head;
	while (!feof(fp))
	{
		s = (book *)malloc(sizeof(book));        //读文件并建立链表
		fscanf(fp, "%d %s %d %lf",p->id,p->name,p->count,p->status);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	fclose(fp);                                   //关闭文件
	system("cls");
	p = head->next;
	while (p)                                    //遍历链表查找信息
	{
		printf("%d %s %d %lf",p->id,p->name,p->count,p->status);
		p = p->next;
	}
	printf("\n\n\t\t\t\t\t");
	system("pause");
	system("cls");
	return;
}
void menu_main()
{
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t|  * - * - * 欢迎来到图书管理系统 * - * -*|\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   用户注册                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   用户登录                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   管理员注册                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   管理员登录                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   退出系统                  | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
void menu_user()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
	printf("\t\t\t| | * - * - * -会-员-界-面- * - * - * | |\n");
	printf("\t\t\t| *                                   * |\n");
	printf("\t\t\t| |  [1]   查找图书信息               | |\n");
	printf("\t\t\t| *  [2]   借阅图书                   * |\n");
	printf("\t\t\t| |  [3]   归还图书                   | |\n");
	printf("\t\t\t| |  [4]   修改账户信息               | |\n");
	printf("\t\t\t| *  [5]   退出用户界面               * |\n");
	printf("\t\t\t| |                                   | |\n");
	printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}
//管理员菜单栏
void menu_manager()
{
	printf("\n\n");
	printf("\t\t\t *======================================*\n");
	printf("\t\t\t| | * - * - * 管-理-员-界-面 * - * - * | |\n");
	printf("\t\t\t| *                                    * |\n");
	printf("\t\t\t| |  [1]   添加图书                    | |\n");
	printf("\t\t\t| *  [2]   删减图书                    * |\n");
	printf("\t\t\t| |  [3]   修改图书信息                | |\n");
	printf("\t\t\t| *  [4]   查找图书信息                * |\n");
	printf("\t\t\t| |  [5]   显示全部图书信息            | |\n");
	printf("\t\t\t| *  [6]   显示所有会员信息            * |\n");
	printf("\t\t\t| |  [7]   统计所有借阅信息            | |\n");
	printf("\t\t\t| |  [8]   显示罚款信息详情            | |\n");
	printf("\t\t\t| *  [9]   退出管理员界面              * |\n");
	printf("\t\t\t| |                                    | |\n");
	printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
	printf("\t\t\t *======================================*\n");
}
void manager()
{
	system("cls");
	int n;
	while(1)
	{
		menu_manager();
		scanf("\t\t\t\t  %d",&n);
		switch (n)
		{
			case 1:
				creat_Book();
				break;
			case 4: 
				output_book();
				break;
			default :
				printf("\t\t\t\t  ************输入异常，请重新输入*******************\n");
				break;	
		}
		system("read");                        //暂停 
	    system("cls");                          //清屏，没有这个会重复出现目录界面 
		if(n==0)
			break;
	}
}
//注册 
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
	 		fp = fopen("manager.text","a");
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
/*登录系统*/ 
int  Input_login()
{
//	system("read");                         
	system("cls");
    users a,b;//定义结构体The_users别名
    FILE *fp;
    printf("\t\t\t\t   -----------  欢迎来到登录界面！   -----------------\n");
    Sleep(1000);
    fp = fopen("manager.text","r");
    fread(&b, sizeof(struct The_users), 1, fp);
    printf("\t\t\t\t		请输入账号:");
    scanf("\t\t\t\t\t\t\t\t%s",a.id);   
    while (1)
   {   
       if (strcmp(a.id, b.id)==0)         //如果有此用户名
       {
           break;       
       }
       else 
       {
            if (!feof(fp))  //如果文件没有读完                            
        	{
               fread(&b, sizeof(struct The_users), 1, fp);
            }
            else
           {
               printf("\t\t\t\t                    此用户名不存在，请重新输入！\n");
			   Sleep(500); 
               fclose(fp);  
			   return 0;              
           }
       }
    }
    printf("\t\t\t\t		请输入密码:");
   	scanf("\t\t\t\t\t\t\t\t\t%s",a.pwd); 		
	do
	{   
        if (strcmp(a.pwd, b.pwd)==0)            /*如果密码匹配*/
		{  
		    fclose(fp);
		    printf("\t\t\t\t		登录成功,欢迎使用!");
		    Sleep(500);
		    printf("\t\t\t\t         进入管理员界面!");
		    manager();
		    return 1;
		}
	   else  
	   {    printf("\t\t\t\t		密码不正确!请重新输入密码:");
	   		scanf("\t\t\t\t\t\t\t\t%s",&a.pwd);         
	   }
    }while(strcmp(a.pwd, b.pwd)==0);   
}


//删除信息 
//void Delete(book *head)
//{
//	int n;
//	char i[20];
//	book *p,*p1=head;
//	p=p1->next;
//	printf("\t\t\t\t  *               请输入 1 进行删除操作:");
//	scanf("%d",&n);
//	switch(n)
//	{
//		case 1:
//			printf("\t\t\t\t  *               请输入要删除的编号:");
//			scanf("%s",i);
//			while(p!=NULL)
//			{
//				if(strcmp(p->id,i) == 0) //比较要删除的编号与p所指的编号 
//				{
//					printf("\t\t\t\t  *               【以下是你要删除的电影信息】\n\n");
//					printf("\t\t\t\t  *%s\t%s\t%d\t%.2lf\t\n",p->id,p->name,p->count,p->status);
//					p1->next=p->next; //将p所指的下一个结点的地址赋值给上一个结点 
//					free(p); //释放空间 
//					printf("\t\t\t\t  -----------------【已经安全删除】--------------\n");
//				}
//				p1=p;
//				p=p->next;
//			}
//			break;
//		default:
//			printf("\t\t\t\t  ------------【输入非法！请重新输入】------------\n");
//			break;
//	}
//}
// 

//链表的遍历 
//void output_book()
//{
//	book *q;
// 	q=read();//打开文件，读出所储存的数据，重新创建一个链表并返回头指针 
//	output(q);
//	printf("\t\t\t\t  ------------------【影片遍历完成】-----------------------\n");
//}
int main()
{
	system("color f0");
	int n;
	while(1)
	{
		menu_main();
		scanf("\t\t\t\t  %d",&n);
		switch (n)
		{
			case 3:
				Input();
				break;
			case 4: 
				Input_login();
				break;
			default :
				printf("\t\t\t\t  ************输入异常，请重新输入*******************\n");
				break;	
		}
		system("read");                        //暂停 
	    system("cls");                          //清屏，没有这个会重复出现目录界面 
		if(n==0)
			break;
	}
	return 0;
}
