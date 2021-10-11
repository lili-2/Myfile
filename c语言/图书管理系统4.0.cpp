#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//定义课本信息 
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
}musers;
//主菜单 
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
	printf("\t\t\t| |  [5]   退出系统                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
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
//录入信息 
void creat_book()
{
	system("cls");//清屏 
	int n,i;
	FILE*fp;
	book *head, *node, *end;
	head=(book*)malloc(sizeof(book)); //开辟空间 ,初始化头指针 
	end=head;
	do
	{
		system("cls"); 
		node=(book*)malloc(sizeof(book));//每读入一个数，都会创建一个新的空间 
		printf("\t\t\t\t  ***********************************************\n");
	    printf("\t\t\t\t  *          欢迎进入书籍录入界面           *\n");
	 	printf("\t\t\t\t  ***********************************************\n");
		printf("\t\t\t\t  *               输入书籍编号                  *\n");
		printf("\t\t\t\t\t\t      ");
	    scanf("%d",&node->id);
	
		printf("\t\t\t\t  *               录入书籍名称                  *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%s",node->name); 
	
		printf("\t\t\t\t  *               录入书籍数量                 *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&node->count); 
		
		printf("\t\t\t\t  *               录入书籍出版时间                *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&node->status); 
		printf("\t\t\t\t  ---------------【录入书籍信息完成】-----------*\n");
		printf("\t\t\t\t  ***********************************************\n");
		end->next=node; //尾插新节点 
		end=node;      //指向尾结点 
		printf("\t\t\t\t  *               1.是\t2.否                    *\n");
		printf("\t\t\t\t  *               请输入是否要录入数据:         *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&n);
	}while(n==1);
	end->next=NULL;//尾节点的指针域指向空 
	book* p;
	if((fp=fopen("books.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("books.txt","w");
      fclose(fp);
    }
	fp=fopen("books.txt","a"); //以追加方式打开文件

	for (p = head->next; p != NULL; p = p->next)          //向文件中写信息
	{
		printf("%d %s %d %f\n", p->id, p->name, p->count, p->status);
		fprintf(fp, "%d %s %d %f\n", p->id, p->name, p->count, p->status);
	}
	fclose(fp);                                           //关闭文件
	printf("\n\n\t\t\t\t\t信息录入成功！");
	system("pause");
}
void output_book()
{
	book* head, * r ,* p;
	FILE* fp = fopen("booklist.txt", "rt");      //打开文件
	head = (book*)malloc(sizeof(book));
	head->next = NULL;                            //建立头结点
	r = head;
	while(!feof(fp))
	{
		p=(book *)malloc(sizeof(book));                                       //开辟空间 
		fscanf(fp,"%d\t%s\t%d\t%f",&p->id,p->name,&p->count,&p->status);   
	
		r->next=p;
		p->next=NULL;
		r=p;
	}
	
	fclose(fp);                                   //关闭文件
	system("cls");
	p = head->next;
	while (p)                                    //遍历链表查找信息
	{
		printf("\t\t\t 书的编号\t书的名字\t书的数量\t书的出版日期\n");
		printf("\t\t\t %d\t\t%s\t\t%d\t\t%f\n",p->id,p->name,p->count,p->status);
		p = p->next;
	}
	printf("\n\n\t\t\t\t\t");
	system("pause");
	system("cls");
	return;
}
void manager()
{
	system("cls");
	int n;
	while(1)
	{
		menu_manager();
		printf("\t\t\t请输入操作 :");
		scanf("%d",&n);
		switch (n)
		{
			case 1:
				creat_book();
				break;
			case 5: 
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
/*登录系统*/ 
int  manager_login()
{
//	system("read");                         
	system("cls");
    musers a,b;//定义结构体The_users别名
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
void manager_Input()
{
	system("read");                        //暂停 
	system("cls");
	musers a,b;//结构体 The_users 重命名定义
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
	 		fp = fopen("managers.text","a");
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
		//主菜单 
		menu_main();
		printf("\t\t\t请输入操作 :");
		scanf("%d",&n);
		switch (n)
		{
			case 3:
				manager_Input();
				break;
			case 4: 
				manager_login();
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
