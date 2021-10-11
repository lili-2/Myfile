#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N sizeof(struct BOOK)
typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users;
typedef struct The_stus 
{
    char id[11]; 
    char pwd[20];
}stus;
struct BOOK        //图书信息 
{
	char number[10];   //登录号 
	char name[10];     //书名 
	char author[10];    //作者名 
	char type[10];      //类型 
	char time[8];        //出版时间 
	float price;       //价格 
	int num;         //数量 
	int x;
	struct BOOK *next;   //指针域 
};
typedef struct BOOK Book;
typedef Book *book;	

void menu_main();     //主菜单 
void manager();       //管理者菜单 
void student();       //学生菜单 

void Input();		  //管理员注册 
int  Input_login();   //管理员登陆 
void S_Input();       //学生注册 
int S_login(); 		  //学生登陆 

void input_book();    //图书入库 
void amend_book();    //修改信息 
void del_book();      //删除图书 
void print_book();    //图书总览 
void sort_book();     //按编号进行排序 
void find_book();     //查询 
void find_name_book();      //按书名查询 
void find_author_book();    //按作者查询 
void find_number_book();    //按编号查询

void less_book();        //借书 
void add_book();         //还书 
void over();             //退出 


int length_list(book head);  //计算链表长度 
void save_book(book p);//将图书信息存入文件 
book ss();//从文件中读图书信息，形成链表，并返回头结点 

//主菜单 
void menu_main()
{
	system("cls"); 
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
	printf("\t\t\t| |  [5]   退出系统                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
//管理员菜单 
void manager()    
{
	do
	{
		system("cls");  //清屏 
		system("color f0");    //设置颜色 
		int t;
		printf("\t\t\t\t\t");
		printf(" 图书查询管理系统\n\n");
		printf("\t\t\t\t\t");
		printf("|     1.图书入库    	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     2.修改信息   	   	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     3.删除信息      	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     4.图书查询      	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     5.图书总览          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     6.按编号进行排序	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     7.退出程序          |\n\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1:input_book();break;
			case 2:amend_book();break;
			case 3:del_book();break;
			case 4:find_book();break;
			case 5:print_book();break; 
			case 6:sort_book();break; 
			case 7:return ;break;
			default :break;
		}
	}while(1);
} 
//学生菜单 
void student()    
{
	do
	{
		system("cls");  //清屏 
		system("color f0");    //设置颜色 
		char t;
		printf("\t\t\t\t\t");
		printf(" 图书查询管理系统\n\n");
		printf("\t\t\t\t\t");
		printf("|     1.借书          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     2.还书          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     3.图书查询      |\n\n");
		printf("\t\t\t\t\t");
		printf("|     4.图书总览      |\n\n");
		printf("\t\t\t\t\t");
		printf("|     5.退出程序      |\n\n");
		t = getch();
		switch(t)
		{
			case '1':less_book();break;
			case '2':add_book();break;
			case '3':find_book();break;
			case '4':print_book();break; 
			case '5':return ;break;
			default :break;
		}
	}while(1);
} 
//管理员注册 
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
	 		fp = fopen("manager5.text","a");
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
//管理员登录 
int  Input_login()
{
	system("cls");
    users a,b;//定义结构体The_users别名
    FILE *fp;
    printf("\t\t\t\t   -----------  欢迎来到登录界面！   -----------------\n");
    Sleep(1000);
    fp = fopen("manager5.text","r");
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
//学生注册 
void S_Input()
{
//	system("read");                        //暂停 
	system("cls");
	stus a,b;//结构体 The_users 重命名定义
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
	 		fp = fopen("students5.text","a");
	        fwrite(&a, sizeof(struct The_stus), 1, fp);
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
/*学生登录系统*/ 
int S_login()
{
//	system("read");                         
	system("cls");
    stus a,b;//定义结构体The_users别名
    FILE *fp;
    printf("\t\t\t\t   -----------  欢迎来到登录界面！   -----------------\n");
    Sleep(1000);
    fp = fopen("students5.text","r");
    fread(&b, sizeof(struct The_stus), 1, fp);
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
               fread(&b, sizeof(struct The_stus), 1, fp);
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
		    printf("\t\t\t\t         进入学生界面!");
		    student();
		    return 1;
		}
	   else  
	   {    printf("\t\t\t\t		密码不正确!请重新输入密码:");
	   		scanf("\t\t\t\t\t\t\t\t%s",&a.pwd);         
	   }
    }while(strcmp(a.pwd, b.pwd)==0);   
}
//图书录入 
void input_book()    
{
	do
	{
		system("cls");
		system("color f0");
		char t;
		book p;
		p=(book)malloc(N);     //申请空间 
		//输入图书信息
		printf("\n\t\t\t\t");
		printf("请输入图书编号(小于10位数):");
		scanf("%s",p->number);getchar();
		printf("\n\t\t\t\t");
		printf("请输入书名(小于10位数)：");
		scanf("%s",p->name);getchar();
		printf("\n\t\t\t\t");
		printf("请输入作者名(小于10位数)：");
		scanf("%s",p->author);getchar();
		printf("\n\t\t\t\t");
		printf("请输入图书类别(小于10位数)：");
		scanf("%s",p->type);getchar();
		printf("\n\t\t\t\t");
		printf("请输入图书出版时间(小于8位数)：");
		scanf("%s",p->time);getchar();
		printf("\n\t\t\t\t");
		printf("请输入图书价格：(float)");
		scanf("%f",&p->price);getchar();
		printf("\n\t\t\t\t");
		printf("请输入图书数量：(int)");
		scanf("%d",&p->num);
		save_book(p);
		printf("\n\t\t\t\t\t");
		printf("正在保存....");
		Sleep(500);   //暂停0.5秒 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("| 保存成功！是否继续？  |");
		printf("\n\t\t\t\t\t");
		printf("| 1.是             2.否 |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		while(1)    //利用死循环可有效防止其他按键干扰 
		{
			printf("\n\t\t\t\t\t");
			t=getch();
			if(t=='1')
			{
				break;
			 } 
			 else if(t=='2')
			 {
			 	manager();
			 }
		}
	}while(1);
} 
//图书总览 
void print_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	int sum=0;
	head=ss();
	printf("\n\t");
	printf("***********************************图书总览**********************************************");
	printf("\n\t");
	printf("----------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("    编号       书名        作者名         图书类别     出版时间       价格        数量");
	printf("\n\t");
	printf("----------------------------------------------------------------------------------------");
	if(head==NULL)
	{
		printf("\n\t\t\t\t\t");
		printf("书库暂时没有书哦~赶快去添加几本吧^_^(按任意键返回)");
		getch();
		manager();
	}
	p=head;
	while(p!=NULL)
	{
		printf("\n\t");
		printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
		i++;
		sum+=p->num;//计算图书总量 
		p=p->next;
	}
	printf("\n\t\t\t\t\t");
	printf("图书总量为：%d",sum);
	printf("\n\t\t\t\t\t");
	printf("按任意键返回");
	getch();//不回显函数 
}
//删除信息 
void del_book()   
{
	do
	{
		system("cls");
		system("color f0");
		FILE *fp;
		book head,p,pre=NULL; 
		int j=0,i=11;
		char x[10];
		char number[10];
		char name[10];
		char t,c,ch;
		head=ss();    //调用函数，返回表头地址 
		printf("\n\t\t\t\t\t");
		printf("请输入你要删除的图书的书名：");
		scanf("%s",name);getchar();
		p=head;
		printf("\n\t");
		printf("*****************************************图书信息*******************************************");
		printf("\n\t");
		printf("----------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  编号        书名        作者名         图书类别       出版时间          价格        数量");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,name)==0)
			{
				printf("\n\t");
				j++;
				printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
				strcpy(number,p->number);
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			printf("\n\t");
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();
				if(ch=='0')
				{
					manager();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("请输入您要删除的图书的编号：");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("输入错误，请重新输入!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		system("color f0");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("|     是否确认删除？    |");
		printf("\n\t\t\t\t\t");
		printf("| 1.是             2.否 |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		while(1)
		{
			t=getch();
			if(t=='1')
			{
				break;
			} 
			else if(t=='2')
			{
				manager();
			}
		}
		p=head;
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))
		{
			pre=p;
			p=p->next;
			strcpy(number,p->number);
		}
		if(p!=NULL)
		{
			if(pre==NULL)
			{
				head=head->next;
			}
			else
			{
				pre->next=p->next;
			}
		}
		free(p);
		fp=fopen("mylikebooks","wb");
		if(fp==NULL)
		{
			printf("打开文件失败"); 
		}
		if(fwrite(head,N,1,fp)!=1)
		{
			printf("写入文件失败!"); 
		}
		fclose(fp);
		if(head!=NULL)
		{
			p=head->next;
			fp=fopen("mylikebooks","ab");
			if(fp==NULL)
			{
				printf("打开文件失败"); 
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)
				{
					printf("写入文件失败!"); 
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		printf("\t\t\t\t\t");
		printf("正在删除，请稍后....");
		Sleep(500);
		system("cls");
		printf("\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("|  删除成功，是否继续？ |");
		printf("\n\t\t\t\t\t");
		printf("| 1.是             2.否 |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		while(1)
		{
			c=getch();
			if(c=='1')
			{
				break;
			}
			else if(c=='2')
			{
				manager();
			}
		}
	}while(1);
}
//修改图书信息 
void amend_book()    
{
	do
	{
		system("cls");
		system("color f0");
		book head,p,pre=NULL; 
		int i=11,j=0;
		char x[10];
		char ch,t;
		FILE *fp;    //文件指针 
		char _name[10];
		char number[10];   //编号 
		char name[10];     //书名 
		char author[10];    //作者名 
		char type[10];      //类型 
		char time[8];        //出版时间 
		float price;       //价格 
		int num;         //数量 
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("请输入你要修改的图书的书名：");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************图书信息*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  编号    书名        作者名         图书类别            出版时间          价格        数量");
		printf("\n\t");
		printf("-----------------------------------------------------------------------------------------");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,_name)==0)
			{
				printf("\n\t");
				j++;
				printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
				i++;
				strcpy(number,p->number);
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			printf("\n\t\t\t\t\t");
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();
				if(ch=='0')
				{
					manager();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("请输入您要修改的图书的编号：");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("输入错误，请重新输入!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //让p重新指向表头 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //遍历链表查询符合条件的结点 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //如果p不为空 
		{
			//输入要修改的信息 
			printf("\n\t\t\t\t\t");
			printf("请输入图书编号(小于10位数)：");
			scanf("%s",number);getchar();strcpy(p->number,number);
			printf("\n\t\t\t\t\t");
			printf("请输入书名(小于10位数)：");
			scanf("%s",name);getchar();strcpy(p->name,name);
			printf("\n\t\t\t\t\t");
			printf("请输入作者名(小于10位数)：");
			scanf("%s",author);getchar();strcpy(p->author,author);
			printf("\n\t\t\t\t\t");
			printf("请输入图书类别(小于10位数)：");
			scanf("%s",type);getchar();strcpy(p->type,type);
			printf("\n\t\t\t\t\t");
			printf("请输入图书出版时间(小于8位数)：");
			scanf("%s",time);getchar();strcpy(p->time,time);
			printf("\n\t\t\t\t\t");
			printf("请输入图书价格：");
			scanf("%f",&price);getchar();p->price=price;
			printf("\n\t\t\t\t\t");
			printf("请输入图书数量：");
			scanf("%d",&num);getchar();p->num=num;
		}
		system("color f0");
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("|     是否确认修改？    |");
		printf("\n\t\t\t\t\t");
		printf("| 1.是             2.否 |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		while(1)   //利用死循环防止其他按键干扰 
		{
			t=getch();
			if(t=='1')
			{
				break;
			} 
			else if(t=='2')
			{
				manager();
			}
		}
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("正在修改，请稍后....");
		fp=fopen("mylikebooks","wb");   //以只写的方式打开名为mybook的二进制文件，打开的同时清空文件中的内容 
		if(fp==NULL)
		{
			printf("打开文件失败"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //将head写入fp所指向的文件中 
		{
			printf("写入文件失败!"); 
		}
		fclose(fp);   //关闭文件 
		if(head!=NULL)   //如果head不为空 
		{
			p=head->next;     //让p指向第二个结点 
			fp=fopen("mylikebooks","ab");   //以追加的方式打开文件 
			if(fp==NULL)
			{
				printf("打开文件失败");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//将p写入fp所指向的文件中
				{
					printf("写入文件失败!");
				}
				p=p->next;
			}
			fclose(fp);  //关闭文件 
		}
		Sleep(500);   //暂停0.5秒 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("修改成功！即将自动返回主菜单....");
		Sleep(500);
		break;
	}while(1);
}
//计算链表长度 
int length_list(book head)
{
	book p = head;
	int len = 0;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}	
	return len;
}
//按编号进行排序 
void sort_book()
{
	do
	{
		system("cls");
		system("color f0");
		book head,p,pre=NULL,q;
		
		char ch,t;
		FILE *fp;    //文件指针 
		char _name[10];
		char number[10];   //编号 
		char name[10];     //书名 
		char author[10];    //作者名 
		char type[10];      //类型 
		char time[8];        //出版时间 
		float price;       //价格 
		int num;         //数量 
		
		head=ss();
		p=head;
		
		int i,j;
		int len = length_list(head);
		printf("\n---------------%d-------------\n",len);
		for(i=0,p=head;i<len-1;i++,p=p->next)
		{
			for(j=i+1,q=p->next;j<len;j++,q=q->next)
			{
				if(strcmp(p->number,q->number)>0)//a[i]>a[j]
				{
					//转移中间变量 
					strcpy(_name,p->name);
					strcpy(number,p->number);
					strcpy(name,p->name);
					strcpy(author,p->author);
					strcpy(type,p->type);
					strcpy(time,p->time);
					price = p->price;
					num = p->num; 
					//复制 
					strcpy(p->name,q->name);
					strcpy(p->number,q->number);
					strcpy(p->name,q->name);
					strcpy(p->author,q->author);
					strcpy(p->type,q->type);
					strcpy(p->time,q->time);
					p->price = q->price;
					p->num = q->num; 
				
					strcpy(q->name,_name);
					strcpy(q->number,number);
					strcpy(q->name,name);
					strcpy(q->author,author);
					strcpy(q->type,type);
					strcpy(q->time,time);
					q->price = price;
					q->num = num; 
				}
			}
		}
		
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("正在排序，请稍后....");
		
		fp=fopen("mylikebooks","wb");   //以只写的方式打开名为mybook的二进制文件，打开的同时清空文件中的内容 
		if(fp==NULL)
		{
			printf("打开文件失败"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //将head写入fp所指向的文件中 
		{
			printf("写入文件失败!"); 
		}
		fclose(fp);   //关闭文件 
		if(head!=NULL)   //如果head不为空 
		{
			p=head->next;     //让p指向第二个结点 
			fp=fopen("mylikebooks","ab");   //以追加的方式打开文件 
			if(fp==NULL)
			{
				printf("打开文件失败");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//将p写入fp所指向的文件中
				{
					printf("写入文件失败!");
				}
				p=p->next;
			}
			fclose(fp);  //关闭文件 
		}
		
		Sleep(500);   //暂停0.5秒 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("排序成功！即将自动返回主菜单....");
		Sleep(1000);
		break;
	}while(1);
}
//查询图书 
void find_book()  
{
	do
	{
		system("cls");  //清屏 
		system("color f0");
		char t;
		printf("\n\n\t\t\t\t");
		printf(" 图书查询");
		printf("\n\n\t\t\t\t");
		printf("|     1.书名  查询      |");
		printf("\n\n\t\t\t\t");
		printf("|     2.作者  查询      |");
		printf("\n\n\t\t\t\t");
		printf("|     3.编号  查询      |");
		printf("\n\n\t\t\t\t");
		printf("按0返回主菜单");
		scanf("%c",&t);
		switch(t)
		{
			case '0':return ;break;
			case '1':find_name_book();break;
			case '2':find_author_book();break;
			case '3':find_number_book();break;
			default :break;
		 } 
	}while(1);
}
 //按名字查询 
void find_name_book() 
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char name[10];
	printf("\n\t\t\t\t");
	printf("请输入您要查询图书的书名：");
	scanf("%s",name);
	printf("\n\t\t\t\t");
	printf("正在查询....");
	Sleep(500);
	p=head;
	system("cls");
	printf("\n\t");
	printf("***************************************图书总览*******************************************");
	printf("\n\t");
	printf("-----------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   编号        书名       作者名         图书类别      出版时间          价格        数量");
	printf("\n\t");
	printf("-----------------------------------------------------------------------------------------");
	while(p!=NULL)
	{
		if(p!=NULL&&strcmp(p->name,name)==0)
		{
			printf("\n\t");
			printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
			i++;
		}
		p=p->next;
	}
	printf("\n\t\t\t\t");
	printf("按任意键返回！");
	getch();
	return ;
}
//按作者名查询 
void find_author_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char author[10];
	printf("\n\t\t\t\t");
	printf("请输入您要查询图书的作者名：");
	scanf("%s",author);
	printf("\n\t\t\t\t");
	printf("正在查询....");
	Sleep(500);
	p=head;
	system("cls");
	printf("\n\t");
	printf("************************************图书总览***********************************************");
	printf("\n\t");
	printf("-------------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   编号         书名        作者名         图书类别      出版时间          价格        数量");
	printf("\n\t");
	printf("-------------------------------------------------------------------------------------------");
	while(p!=NULL)
	{
		if(p!=NULL&&strcmp(p->author,author)==0)
		{
			printf("\n\t");
			printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
			i++;
		}
		p=p->next;
	}
	printf("\n\n\t");
	printf("按任意键返回！");
	getch();
	return;
} 
//按图书编号查询 
void find_number_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char number[10];
	printf("\n\t\t\t\t");
	printf("请输入您要查询图书的编号：");
	scanf("%s",number);
	printf("\n\t\t\t\t");
	printf("正在查询....");
	Sleep(500);
	p=head;
	printf("\n\t");
	printf("******************************************图书总览********************************************");
	printf("\n\t");
	printf("-----------------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   编号        书名        作者名         图书类别         出版时间          价格        数量");
	printf("\n\t");
	printf("---------------------------------------------------------------------------------------------");
	while(p!=NULL)
	{
		if(p!=NULL&&strcmp(p->number,number)==0)
		{
			printf("\n\t");
			printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
			i++;
		}
		p=p->next;
	}
	printf("\n\t");
	printf("按任意键返回！");
	getch();
	return ; 
}
void save_book(book p)   //将p中内容写入文件 
{
	FILE *fp;    //文件指针 
	fp=fopen("mylikebooks","ab");   //以追加的方式打开名字为mybook的二进制文件 
	if(fp==NULL)
	{
		printf("文件打开失败");
	}
	if(fwrite(p,N,1,fp)!=1)   //将p所指向的一段大小为N的内容存入fp所指向的文件中 
	{
		printf("写入错误");
	}
	fclose(fp);    //关闭文件  
} 

book ss()      //将文件中的内容读出到链表中，返回值为表头地址 
{
	FILE *fp;       //文件指针 
	int n=0;
	book head=NULL;
	book p2,p,pr=NULL;
	fp=fopen("mylikebooks","ab+");     //以只读的方式打开文件 
	if(fp==NULL)
	{
		printf("文件打开失败\n");
	}
	while(!feof(fp))        //判断文件位置标志是否移动到文件末尾 
	{
	   n++;
	   	p=(book)malloc(N); //向内存申请一段空间 
	   fread(p,N,1,fp);     //将fp所指向的文件中的内容赋给p 
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //创建链表 
	    {
	    	pr=p2;
	    	p2->next=p;
	    	p2=p;
		}
    }
    if(pr!=NULL)
       pr->next=NULL;
    else
       head=NULL;
    fclose(fp);    //关闭文件 
    return head;   //返回头指针 
}
//借书 
void less_book()
{
	do
	{
		system("cls");
		system("color f0");
		book head,p,pre=NULL; 
		int i=11,j=0;
		char x[10];
		char ch,t;
		FILE *fp;    //文件指针 
		char _name[10];
		char number[10];   
		int num;          
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("请输入你要借的图书的书名：");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************图书信息*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  编号    书名        作者名         图书类别            出版时间          价格        数量");
		printf("\n\t");
		printf("-----------------------------------------------------------------------------------------");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,_name)==0)
			{
				printf("\n\t");
				j++;
				printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
				i++;
				strcpy(number,p->number);
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			printf("\n\t\t\t\t\t");
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();
				if(ch=='0')
				{
					manager();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("请输入您要借的图书的编号：");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("输入错误，请重新输入!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //让p重新指向表头 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //遍历链表查询符合条件的结点 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //如果p不为空 
		{
			printf("\n\t\t\t\t\t");
			printf("请输入要借的图书数量：");
			scanf("%d",&num);getchar();
			if(p->num - num >= 0)
			{
				p->num=p->num - num;
			}else
			{
				Sleep(3000);
				printf("\n\t\t\t\t"); 
				printf("抱歉，图书余额不够，请重新进行选择");
				return ; 
			} 
		}
		fp=fopen("mylikebooks","wb");   //以只写的方式打开名为mybook的二进制文件，打开的同时清空文件中的内容 
		if(fp==NULL)
		{
			printf("打开文件失败"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //将head写入fp所指向的文件中 
		{
			printf("写入文件失败!"); 
		}
		fclose(fp);   //关闭文件 
		if(head!=NULL)   //如果head不为空 
		{
			p=head->next;     //让p指向第二个结点 
			fp=fopen("mylikebooks","ab");   //以追加的方式打开文件 
			if(fp==NULL)
			{
				printf("打开文件失败");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//将p写入fp所指向的文件中
				{
					printf("写入文件失败!");
				}
				p=p->next;
			}
			fclose(fp);  //关闭文件 
		}
		Sleep(500);   //暂停0.5秒 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("借书成功！即将自动返回主菜单....");
		Sleep(500);
		break;
	}while(1);
}
//还书 
void add_book()
{
		do
	{
		system("cls");
		system("color f0");
		book head,p,pre=NULL; 
		int i=11,j=0;
		char x[10];
		char ch,t;
		FILE *fp;    //文件指针 
		char _name[10];
		char number[10];   //登录号 
		int num;         //数量 
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("请输入你要还的图书的书名：");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************图书信息*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  编号    书名        作者名         图书类别            出版时间          价格        数量");
		printf("\n\t");
		printf("-----------------------------------------------------------------------------------------");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,_name)==0)
			{
				printf("\n\t");
				j++;
				printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
				i++;
				strcpy(number,p->number);
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			printf("\n\t\t\t\t\t");
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();
				if(ch=='0')
				{
					student();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("请输入您要还的图书的编号：");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("输入错误，请重新输入!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //让p重新指向表头 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //遍历链表查询符合条件的结点 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //如果p不为空 
		{
			//输入要修改的信息 
			printf("\n\t\t\t\t\t");
			printf("请输入要还的图书数量：");
			scanf("%d",&num);getchar();
			p->num=p->num + num;
		}
		fp=fopen("mylikebooks","wb");   //以只写的方式打开二进制文件，打开的同时清空文件中的内容 
		if(fp==NULL)
		{
			printf("打开文件失败"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //将head写入fp所指向的文件中 
		{
			printf("写入文件失败!"); 
		}
		fclose(fp);   //关闭文件 
		if(head!=NULL)   //如果head不为空 
		{
			p=head->next;     //让p指向第二个结点 
			fp=fopen("mylikebooks","ab");   //以追加的方式打开文件 
			if(fp==NULL)
			{
				printf("cannot open file");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//将p写入fp所指向的文件中
				{
					printf("write error!");
				}
				p=p->next;
			}
			fclose(fp);  //关闭文件 
		}
		Sleep(500);   //暂停0.5秒 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("还书成功！即将自动返回主菜单....");
		Sleep(500);
		break;
	}while(1);
}
//退出软件 
void over()       
{
	system("cls");
	char t;
	printf("\n\n\t\t\t\t\t");
	printf("-----------------------");
	printf("\n\n\t\t\t\t\t");
	printf("|   您确定要退出吗？  |");
	printf("\n\n\t\t\t\t\t");
	printf("| 1.确定     2.取消   |");
	printf("\n\n\t\t\t\t\t");
	printf("-----------------------");
	printf("\n\n\t\t\t\t\t");
	while(1)
	{
		scanf("%c",&t);      //输入t
		switch(t)
		{
			case '1':
			system("cls");
		    system("color f0");
			printf("\n\n\t\t\t\t\t");
			printf("正在安全退出....");
			Sleep(1000);     //暂停1秒 
			system("cls");
			system("color f0");
			printf("\n\n\t\t\t\t\t");
			printf("谢谢使用！");
			printf("\n\n\t\t\t\t\t");
			printf("by-by^_^");
			exit(0);  break; //终止程序 
			case '2':
			menu_main(); break;   //调用函数，进入菜单 
			default :break;
		}
	}
} 
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
			case 1:
				S_Input();
				break;
			case 2:
				S_login();
				break;
			case 3:
				Input();
				break;
			case 4: 
				Input_login();
				break;
			case 5: 
				over();
				break;
			default :
				printf("\t\t\t\t  ************输入异常，请重新输入*******************\n");
				break;	
		}
	    system("cls");                   //清屏，没有这个会重复出现目录界面 
		if(n==0)
			break;
	}
	return 0;
}
