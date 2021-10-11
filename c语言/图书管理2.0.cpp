#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <iostream>
#include <fstream>
using namespace std;
struct book
{  
	char num;
	char name;
	char writer;
	char cat;
	char addr;
	char time;
	char price;
}b[20];

FILE *fp;//定义文件指针fp,指向文件的起始地址
FILE *fp1;
struct bookdate
{
    char num[20];
	char name[20];
	char writer[20];
	char cat[20];
	char addr[20];
	char time[20];
	char price[20];
}book;

void mainmenu();    //主菜单 
void display();     //显示 
void display2() ;   //显示模块2
void input();       //输入 
void searchbook();  //按书名查询 
void searchwriter();//按作者名查询 
void modify();      //修改 
void del();         //删除
//	void retu();        //归还图书
void load();
void txtput();
void fun1();

int main()
{ 
	int k;
	system("cls");
	system ("color 4"); 
 	printf("******************请输入您的登录账号！(183)**********************\n"); //登录 key 为183  
	printf("账号为：");
    scanf("%d",&k);
	if(k==183)
	{
		while(1)
			mainmenu();
	}
}
/****************************************************************************************                    显示菜单界面            ****************/
void mainmenu()
{
	char n;
	system("cls");
	system ("color f0");                 //设置成绿色
	printf("\n");printf("\n");printf("\n");

	printf("\t\t****************欢迎使用图书管理系统***************\n");
	printf("\t\t* 丨              1.输入图书信息                丨*\n");
	printf("\t\t* 丨              2.显示统计图书信息            丨*\n");
	printf("\t\t* 丨              3.按书名查找图书信息          丨*\n");
	printf("\t\t* 丨              4.按作者查找图书信息          丨*\n");
	printf("\t\t* 丨              5.修改图书信息                丨*\n");
	printf("\t\t* 丨              6.删除图书记录                丨*\n");
	printf("\t\t* 丨              7.退出图书管理系统            丨*\n");
	printf("\t\t***************************************************\n");
	printf("请选择菜单命令: ");

    printf("%c ",n=getch());
	switch (n) 
	{ 
	    
		case '1':input();       break;
		case '2':display();     break;
		case '3':searchbook();  break;  //按书名查找
		case '4':searchwriter();break;  //按作者查找
		case '5':modify();      break;
		case '6':del();         break;
		case '7':exit(0);
		default :mainmenu();
	}
	
  } 

/*************************************************************************************************               1 图书录入模块     *******************/
void input() 
{
	char ch;
	fp = fopen("Datebast.txt","ab");                   //以追加方式打开文件
	do
	{ 
		printf("--------------------------------------------------------------------------------------------------\n");
	
		fflush(stdin);
		printf("请输入图书编号：");
		scanf("%s",book.num);
		printf("请输入书名    ：");
		scanf("%s",book.name);
		printf("请输入作者    ：");
		scanf("%s",book.writer);
		printf("请输入分类号  ：");
		scanf("%s",book.cat);
		printf("请输入出版社  ：");
		scanf("%s",book.addr);
		printf("请输入出版时间：");
		scanf("%s",book.time);
		printf("请输入价格    ：");
		scanf("%s",book.price);	                   //	编号	  书名        作者    	分类号       出版社	    出版时间        单价
		printf("--------------------------------------------------------------------------------------------------\n");
	
		getchar();
		fwrite(&book,sizeof(book),1,fp);           //数据输出到fp所指文件中：
		printf("\n是否继续输入新的图书信息？\n");
		printf("请选择（Y/N）：");
		ch=getchar();                              //从键盘输入一个字符型数据，把值赋给变量ch
		
	}while(ch == 'y' || ch == 'Y');
	printf("是否返回主菜单？按回车键返回");
	fclose(fp);
}
/*****************************************************************************************************************             2 显示 模块       *****************/
void display() 
{
	int q;
	char w;
	system("cls"); //执行控制台命令‘清屏’，就是cmd下的cls，清除所有显示信息  
    txtput();
    system("cls");
    printf("您要打开内部文件（0）、还是外部文件（1）\n");
	scanf("%d",&q);
	getchar();
	system("cls");
	if(q==1)
	{
		printf("请输入文件名；");
	    scanf("%s",&w);
		fp = fopen("w","r"); 		
		if((fp1 = fopen("w","rb")) == NULL)//只读，二进制，如果返回的指针为空,无相应的文件
		{
			printf("\n不能打开 %s文件\n",&w);
			getchar();
		    getchar();                  
		    mainmenu();     		
		}
		else fp = fopen("w","r");
	}
	else 	fp = fopen("Datebast.txt","r"); 	//以只读方式(r

    getchar();
	printf("\n\t\t*************** 以下为图书数据库所有信息************\n\n");
	printf("编号	   书名        作者    	  分类号           出版社	     出版时间           单价\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	while(fread(&book,sizeof(book),1,fp) == 1)
	{ 
		printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		  //	编号	  书名        作者    	分类号       出版社	    出版时间      单价
    	printf("--------------------------------------------------------------------------------------------------\n");
	}
	getchar();
	printf("按回车键返回主菜单！");
	getchar();
	fclose(fp);
     
}
/*************************************************************************************************             显示 模块2  用于修改比对查找      *****************/
void display2() 
{
	system("cls"); //执行控制台命令‘清屏’，就是cmd下的cls，清除所有显示信息

	fp = fopen("Datebast.txt","r");                    //以只读方式(r) 
	printf("\n\t\t*************** 以下为图书数据库所有信息************\n\n");
	printf("编号	   书名        作者    	  分类号       出版社	     出版时间        单价\n");
		printf("--------------------------------------------------------------------------------------------------\n");
	
	while(fread(&book,sizeof(book),1,fp) == 1)
	{ 
	printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		  //	编号	  书名        作者    	分类号       出版社	    出版时间      单价
    	printf("--------------------------------------------------------------------------------------------------\n");
	
	}
	fclose(fp);
}

/**********************************************************************************************************              txt写入结构体                 ******/	
void txtput()
{
	int n = 0;
	ifstream in("Datebast.txt",ios::in);
	if(!in.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}
	while(!in.eof() && n < 20)
	{
		in >>b[n].num >> b[n].name >>b[n].writer>>b[n].cat>>b[n].addr>>b[n].time>>b[n].price;
		n++;
	}

	for (int i = 0; i < n; ++i)
	cout << "num:" << b[i].num << " name:" <<b[i].name << " writer:" <<b[i].writer<< "cat:" << b[i].cat << "addr:" << b[i].addr << "time:" << b[i].time << "price:" << b[i].price   << endl;
	//              1                  2                     3                         4                  5                       6                        7
	in.close();

   fun1();
	
}
/******************************************************************************************************                  排序          ************/
void fun1()
{
	int n=20;
	int i,j,count=0;
	struct book temp;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(b[j].num>b[j+1].num)
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;//根据score大小排序。
			}
		}
	}	
}
 
/******************************                  从文件读入           ****************/
/*void load()
{
	int i;
	FILE *fp1;
	//	fp = fopen("Datebast.txt","ab"); 
	if((fp1 = fopen("bookdate.txt","r+"))==NULL)
	{
		printf("文件不能打开！");
		getch();
	}
	i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s\n %s\n %s\n %s\n %s\n %s\n %s\n ",book[i].num,book[i].name,book[i].writer,book[i].cat,book[i].addr,book[i].time,book[i].price);
		i++;
	}
	fcloce(fp1);

}

*/

/************************        3 按书名查找 模块*****************/
void searchbook()
{
	system("cls"); //执行控制台命令‘清屏’，就是cmd下的cls，清除所有显示信息

	char name[10];
	printf("请输入要查找的书名:");
	fflush(stdin);                      //清除缓存
	gets(name);
	fp = fopen("Datebast.txt","rb");      //以二进制 只读
	while(!feof(fp))                    //判断文件是否到达末尾
	{
		fread(&book,sizeof(book),1,fp); //fp所指的文件中再次将每个学生数据逐个读入到
		if(strcmp(name,book.name) == 0) //判断是否有相同的文字，检查书是否存在
		{
			printf("**************************************!已找到目标图书!********************************************\n");
			printf("编号	   书名        作者    	  分类号           出版社	     出版时间           单价\n");
        	printf("--------------------------------------------------------------------------------------------------\n");
			printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		              //1          2          3           4            5           6             7
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("\n按回车键返回主菜单\n\n");			
			getchar(); 
			break;                         //跳出条件语句
		}
	}
	if(feof(fp))                           //判断文件指针是否指向文件末尾,如果是
	{
		printf("您所查询的图书不存在！");

	}
	fclose(fp); 
	getchar();
	fflush(stdin);                         //清除缓存fflush(stdin)中stdin是标准输入的意思。
                                           //fflush(stdin)的作用是清空标准输入缓冲区
}
/*************************************************************************************************            4 按作者查找 模块       *****************/
void searchwriter()
{
	system("cls");                         //执行控制台命令‘清屏’，就是cmd下的cls，清除所有显示信息
	char writer[10];
	printf("请输入要查找的作者名:\n");
	fflush(stdin);                         //清除缓存
	gets(writer);
	fp = fopen("Datebast.txt","rb");         //二进制 只读
	while(!feof(fp))                       //判断文件是否到达末尾
	{
		fread(&book,sizeof(book),1,fp);    //fp所指的文件中再次将每个学生数据逐个读入到
		if(strcmp(writer,book.writer) == 0)//比对文件，是否有此作者 
		{
			printf("**************************************!已找到目标图书!********************************************\n");
			printf("编号	   书名        作者    	  分类号           出版社	     出版时间           单价\n");
        	printf("--------------------------------------------------------------------------------------------------\n");	
		    printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
				,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("\n按回车键返回主菜单");			
			getchar();
			break;
		}
	}
	if(feof(fp))  //判断文件指针是否指向文件末尾
	{
		printf("您所查询的图书不存在");
		getchar();//等待用户查看信息，按回车键流程向下
	}
	fclose(fp);   //关闭文件
	fflush(stdin);//清除缓存
}
/************************************************************************************************            5 修改数据 模块      ************/
void modify()
{
    display2() ;
 	char modname[10],num[10],name[10],  writer[10], cat[10], addr[10], time[10], price[10];      //定义临时的数组用来存放--------临时数据
                   //book.num,book.name,book.writer,book.cat,book.addr,book.time,book.price
	int a,b,c,d,f,g,h=1;
	int flag;
	char ch;
	FILE *fp1,*fp2;//声明两个文件指针fp1,fp2
	fflush(stdin); //清除缓存
	gets(modname); //建立 书名 缓存

	do
	{
		if((fp1 = fopen("Datebast.txt","rb")) == NULL)//只读，二进制，如果返回的指针为空,无相应的文件
		{
			printf("\n不能打开 Datebast.txt文件");
			getchar();
			exit(1);                                // exit是在调用处强行退出程序，运行一次程序就结束  
		}
		if((fp2 = fopen("temp.txt","wb")) == NULL)  //建立临时文件
			                                        //只写，二进制，如果返回的指针为空
		{
			printf("\n不能打开 Datebast.txt文件");
			getchar();
			exit(1);
		}
	
		
		printf("请输入要改的图书名：");
		gets(modname);                             //输入要修改的书名
		printf("------------------------------------------------------------------\n");
		flag=0;                                    //flag不是语句,只有一种用户自己定义的变量名。 大多数用户用来当做一个标志型变量。flag=1,执行某个语句。flag=0屏蔽某些语句。
		while(fread(&book,sizeof(book),1,fp1) == 1)//读取文件内容
		{
			if(strcmp(book.name,modname) == 0)     //strcmp比较
			{
				/*--------------------------------------------编号*/
				printf("请输入要改的选项  ： 编号（1）、书名（2）、作者（3）、分类号（4）、出版社（5）、出版时间（6）、单价（7）\n");
				printf("修改图书编号吗？(1)");     
				scanf("%d",&a);
				getchar();
					if(a == 1)
				{
					printf("请输入更改后的图书编号为: （");
					gets(num);
					strcpy(book.num, num);
				} 
		    	/*--------------------------------------------书名*/
				printf("修改书名吗？    (2)");
				scanf("%d",&b);
				getchar();
				if(b == 2)
				{
					printf("请输入更改后的书名为：    （");
					gets(name);
					strcpy(book.name,name);
				} 
				/*--------------------------------------------作者 */
				printf("修改作者名吗?   (3)");
				scanf("%d",&c);
				getchar();
				if(c == 3)
				{
					printf("请输入更改后的作者名为：  （");
					gets(writer);
					strcpy(book.writer,writer);
				}
				/*--------------------------------------------分类号*/
				printf("修改图书分类号吗?(4)");
				scanf("%d",&f);
				getchar();

				if(f == 4)
				{
					printf("请输入更改后的图书分类号为（");
					gets(cat);
					strcpy(book.cat,cat);
				}
				/*-------------------------------------------出版社*/
				printf("修改出版单位吗?  (5)");
				scanf("%d",&d);
				getchar();

				if(d == 5)
				{
					printf("请输入更改后的出版单位为：（");
					gets(addr);
					strcpy(book.addr,addr);
				}
				/*------------------------------------------出版时间*/
				printf("修改出版时间吗?  (6)");
				scanf("%d",&f);
				getchar();

				if(f == 6)
				{
					printf("请输入更改后的出版时间为：（");
					gets(time);
					strcpy(book.time,time);
				}
				/*--------------------------------------------单价*/
				printf("修改图书价格吗?  (7)");
				scanf("%d",&g);
				getchar();

				if(g == 7)
				{
					printf("请输入更改后的图书价格为： （");
					gets(price);
					strcpy(book.price,price);
				}
				flag=1;
				printf("\n");
	
			}		
			fwrite(&book,sizeof(book),1,fp2); //将数据作为一个整体一次性写入磁盘文件
		}

		fclose(fp1);                          //关闭缓存指针
		fclose(fp2);
		
		if(flag == 1)                         //程序运行标志
		{ 
			printf("修改成功");
			remove("Datebast.txt");             //删除原文件
			rename("temp.txt","Datebast.txt");  //将临时文件命名为Datebast.txt、、、、替换
		}
		else
		{
			printf("找不到此记录");
			getchar();
		}
		printf("继续修改吗？(y/n)");
		ch=getchar();
		getchar();
	}while(ch == 'Y' || ch == 'y');
}
/*********************************************************************************************************          6 删除  模块        *************/
void del()
{
	display2() ;

	char name[10];
	int flag;
	char ch;
	FILE *fp1,*fp2;                                 //声明两个文件指针  fp1  , fp2
	do
	{
		if((fp1 = fopen("Datebast.txt","rb")) == NULL) //文件打开
		{
			printf("\n不能打开 Datebast.txt文件");
			exit(1);
		}
		if((fp2 = fopen("temp.txt","wb")) == NULL)  //建立缓存文件
		{
			printf("\n不能打开 Datebast.txt文件");

			exit(1);
		}

		printf("\n请输入要删除的图书名:");
		fflush(stdin);                              //清除缓存
		gets(name); //输入书名
		flag = 0;   //标志位
		while(!feof(fp1))                           //判断文件fp1是否指向文件末尾
		{
			fread(&book,sizeof(book),1,fp1);
			if(strcmp(name,book.name) == 0)
			{
				flag = 1;
			}
			else
			{
				fwrite(&book,sizeof(book),1,fp2);   //将数据作为一个整体一次性写入磁盘文件
			}
		}
		fclose(fp1);             //关闭文件
		fclose(fp2);             //关闭文件

		if(flag == 1)
		{
			remove("Datebast.txt");//移除文件
			rename("temp.txt","Datebast.txt");
			printf("删除成功!\n");
		}
		else 
		{
			printf("找不到图书名");
			remove("temp.txt");  //移除文件
		}
		printf("继续删除其他图书名吗？(y/n)");
		fflush(stdin);           //清除缓存
		ch = getchar();
		getchar();
	}while(ch == 'y' || ch == 'Y');
	fflush(stdin);               //清除缓存
}
//

