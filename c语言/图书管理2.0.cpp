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

FILE *fp;//�����ļ�ָ��fp,ָ���ļ�����ʼ��ַ
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

void mainmenu();    //���˵� 
void display();     //��ʾ 
void display2() ;   //��ʾģ��2
void input();       //���� 
void searchbook();  //��������ѯ 
void searchwriter();//����������ѯ 
void modify();      //�޸� 
void del();         //ɾ��
//	void retu();        //�黹ͼ��
void load();
void txtput();
void fun1();

int main()
{ 
	int k;
	system("cls");
	system ("color 4"); 
 	printf("******************���������ĵ�¼�˺ţ�(183)**********************\n"); //��¼ key Ϊ183  
	printf("�˺�Ϊ��");
    scanf("%d",&k);
	if(k==183)
	{
		while(1)
			mainmenu();
	}
}
/****************************************************************************************                    ��ʾ�˵�����            ****************/
void mainmenu()
{
	char n;
	system("cls");
	system ("color f0");                 //���ó���ɫ
	printf("\n");printf("\n");printf("\n");

	printf("\t\t****************��ӭʹ��ͼ�����ϵͳ***************\n");
	printf("\t\t* ح              1.����ͼ����Ϣ                ح*\n");
	printf("\t\t* ح              2.��ʾͳ��ͼ����Ϣ            ح*\n");
	printf("\t\t* ح              3.����������ͼ����Ϣ          ح*\n");
	printf("\t\t* ح              4.�����߲���ͼ����Ϣ          ح*\n");
	printf("\t\t* ح              5.�޸�ͼ����Ϣ                ح*\n");
	printf("\t\t* ح              6.ɾ��ͼ���¼                ح*\n");
	printf("\t\t* ح              7.�˳�ͼ�����ϵͳ            ح*\n");
	printf("\t\t***************************************************\n");
	printf("��ѡ��˵�����: ");

    printf("%c ",n=getch());
	switch (n) 
	{ 
	    
		case '1':input();       break;
		case '2':display();     break;
		case '3':searchbook();  break;  //����������
		case '4':searchwriter();break;  //�����߲���
		case '5':modify();      break;
		case '6':del();         break;
		case '7':exit(0);
		default :mainmenu();
	}
	
  } 

/*************************************************************************************************               1 ͼ��¼��ģ��     *******************/
void input() 
{
	char ch;
	fp = fopen("Datebast.txt","ab");                   //��׷�ӷ�ʽ���ļ�
	do
	{ 
		printf("--------------------------------------------------------------------------------------------------\n");
	
		fflush(stdin);
		printf("������ͼ���ţ�");
		scanf("%s",book.num);
		printf("����������    ��");
		scanf("%s",book.name);
		printf("����������    ��");
		scanf("%s",book.writer);
		printf("����������  ��");
		scanf("%s",book.cat);
		printf("�����������  ��");
		scanf("%s",book.addr);
		printf("���������ʱ�䣺");
		scanf("%s",book.time);
		printf("������۸�    ��");
		scanf("%s",book.price);	                   //	���	  ����        ����    	�����       ������	    ����ʱ��        ����
		printf("--------------------------------------------------------------------------------------------------\n");
	
		getchar();
		fwrite(&book,sizeof(book),1,fp);           //���������fp��ָ�ļ��У�
		printf("\n�Ƿ���������µ�ͼ����Ϣ��\n");
		printf("��ѡ��Y/N����");
		ch=getchar();                              //�Ӽ�������һ���ַ������ݣ���ֵ��������ch
		
	}while(ch == 'y' || ch == 'Y');
	printf("�Ƿ񷵻����˵������س�������");
	fclose(fp);
}
/*****************************************************************************************************************             2 ��ʾ ģ��       *****************/
void display() 
{
	int q;
	char w;
	system("cls"); //ִ�п���̨���������������cmd�µ�cls�����������ʾ��Ϣ  
    txtput();
    system("cls");
    printf("��Ҫ���ڲ��ļ���0���������ⲿ�ļ���1��\n");
	scanf("%d",&q);
	getchar();
	system("cls");
	if(q==1)
	{
		printf("�������ļ�����");
	    scanf("%s",&w);
		fp = fopen("w","r"); 		
		if((fp1 = fopen("w","rb")) == NULL)//ֻ���������ƣ�������ص�ָ��Ϊ��,����Ӧ���ļ�
		{
			printf("\n���ܴ� %s�ļ�\n",&w);
			getchar();
		    getchar();                  
		    mainmenu();     		
		}
		else fp = fopen("w","r");
	}
	else 	fp = fopen("Datebast.txt","r"); 	//��ֻ����ʽ(r

    getchar();
	printf("\n\t\t*************** ����Ϊͼ�����ݿ�������Ϣ************\n\n");
	printf("���	   ����        ����    	  �����           ������	     ����ʱ��           ����\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	while(fread(&book,sizeof(book),1,fp) == 1)
	{ 
		printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		  //	���	  ����        ����    	�����       ������	    ����ʱ��      ����
    	printf("--------------------------------------------------------------------------------------------------\n");
	}
	getchar();
	printf("���س����������˵���");
	getchar();
	fclose(fp);
     
}
/*************************************************************************************************             ��ʾ ģ��2  �����޸ıȶԲ���      *****************/
void display2() 
{
	system("cls"); //ִ�п���̨���������������cmd�µ�cls�����������ʾ��Ϣ

	fp = fopen("Datebast.txt","r");                    //��ֻ����ʽ(r) 
	printf("\n\t\t*************** ����Ϊͼ�����ݿ�������Ϣ************\n\n");
	printf("���	   ����        ����    	  �����       ������	     ����ʱ��        ����\n");
		printf("--------------------------------------------------------------------------------------------------\n");
	
	while(fread(&book,sizeof(book),1,fp) == 1)
	{ 
	printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		  //	���	  ����        ����    	�����       ������	    ����ʱ��      ����
    	printf("--------------------------------------------------------------------------------------------------\n");
	
	}
	fclose(fp);
}

/**********************************************************************************************************              txtд��ṹ��                 ******/	
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
/******************************************************************************************************                  ����          ************/
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
				b[j+1]=temp;//����score��С����
			}
		}
	}	
}
 
/******************************                  ���ļ�����           ****************/
/*void load()
{
	int i;
	FILE *fp1;
	//	fp = fopen("Datebast.txt","ab"); 
	if((fp1 = fopen("bookdate.txt","r+"))==NULL)
	{
		printf("�ļ����ܴ򿪣�");
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

/************************        3 ���������� ģ��*****************/
void searchbook()
{
	system("cls"); //ִ�п���̨���������������cmd�µ�cls�����������ʾ��Ϣ

	char name[10];
	printf("������Ҫ���ҵ�����:");
	fflush(stdin);                      //�������
	gets(name);
	fp = fopen("Datebast.txt","rb");      //�Զ����� ֻ��
	while(!feof(fp))                    //�ж��ļ��Ƿ񵽴�ĩβ
	{
		fread(&book,sizeof(book),1,fp); //fp��ָ���ļ����ٴν�ÿ��ѧ������������뵽
		if(strcmp(name,book.name) == 0) //�ж��Ƿ�����ͬ�����֣�������Ƿ����
		{
			printf("**************************************!���ҵ�Ŀ��ͼ��!********************************************\n");
			printf("���	   ����        ����    	  �����           ������	     ����ʱ��           ����\n");
        	printf("--------------------------------------------------------------------------------------------------\n");
			printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
			,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
		              //1          2          3           4            5           6             7
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("\n���س����������˵�\n\n");			
			getchar(); 
			break;                         //�����������
		}
	}
	if(feof(fp))                           //�ж��ļ�ָ���Ƿ�ָ���ļ�ĩβ,�����
	{
		printf("������ѯ��ͼ�鲻���ڣ�");

	}
	fclose(fp); 
	getchar();
	fflush(stdin);                         //�������fflush(stdin)��stdin�Ǳ�׼�������˼��
                                           //fflush(stdin)����������ձ�׼���뻺����
}
/*************************************************************************************************            4 �����߲��� ģ��       *****************/
void searchwriter()
{
	system("cls");                         //ִ�п���̨���������������cmd�µ�cls�����������ʾ��Ϣ
	char writer[10];
	printf("������Ҫ���ҵ�������:\n");
	fflush(stdin);                         //�������
	gets(writer);
	fp = fopen("Datebast.txt","rb");         //������ ֻ��
	while(!feof(fp))                       //�ж��ļ��Ƿ񵽴�ĩβ
	{
		fread(&book,sizeof(book),1,fp);    //fp��ָ���ļ����ٴν�ÿ��ѧ������������뵽
		if(strcmp(writer,book.writer) == 0)//�ȶ��ļ����Ƿ��д����� 
		{
			printf("**************************************!���ҵ�Ŀ��ͼ��!********************************************\n");
			printf("���	   ����        ����    	  �����           ������	     ����ʱ��           ����\n");
        	printf("--------------------------------------------------------------------------------------------------\n");	
		    printf("%-10.10s  %-10.10s  %-10.10s  %-10.10s  %-20.20s   %-15.15s  %-10.10s \n"
				,book.num, book.name, book.writer , book.cat,   book.addr ,book.time,  book.price);
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("\n���س����������˵�");			
			getchar();
			break;
		}
	}
	if(feof(fp))  //�ж��ļ�ָ���Ƿ�ָ���ļ�ĩβ
	{
		printf("������ѯ��ͼ�鲻����");
		getchar();//�ȴ��û��鿴��Ϣ�����س�����������
	}
	fclose(fp);   //�ر��ļ�
	fflush(stdin);//�������
}
/************************************************************************************************            5 �޸����� ģ��      ************/
void modify()
{
    display2() ;
 	char modname[10],num[10],name[10],  writer[10], cat[10], addr[10], time[10], price[10];      //������ʱ�������������--------��ʱ����
                   //book.num,book.name,book.writer,book.cat,book.addr,book.time,book.price
	int a,b,c,d,f,g,h=1;
	int flag;
	char ch;
	FILE *fp1,*fp2;//���������ļ�ָ��fp1,fp2
	fflush(stdin); //�������
	gets(modname); //���� ���� ����

	do
	{
		if((fp1 = fopen("Datebast.txt","rb")) == NULL)//ֻ���������ƣ�������ص�ָ��Ϊ��,����Ӧ���ļ�
		{
			printf("\n���ܴ� Datebast.txt�ļ�");
			getchar();
			exit(1);                                // exit���ڵ��ô�ǿ���˳���������һ�γ���ͽ���  
		}
		if((fp2 = fopen("temp.txt","wb")) == NULL)  //������ʱ�ļ�
			                                        //ֻд�������ƣ�������ص�ָ��Ϊ��
		{
			printf("\n���ܴ� Datebast.txt�ļ�");
			getchar();
			exit(1);
		}
	
		
		printf("������Ҫ�ĵ�ͼ������");
		gets(modname);                             //����Ҫ�޸ĵ�����
		printf("------------------------------------------------------------------\n");
		flag=0;                                    //flag�������,ֻ��һ���û��Լ�����ı������� ������û���������һ����־�ͱ�����flag=1,ִ��ĳ����䡣flag=0����ĳЩ��䡣
		while(fread(&book,sizeof(book),1,fp1) == 1)//��ȡ�ļ�����
		{
			if(strcmp(book.name,modname) == 0)     //strcmp�Ƚ�
			{
				/*--------------------------------------------���*/
				printf("������Ҫ�ĵ�ѡ��  �� ��ţ�1����������2�������ߣ�3��������ţ�4���������磨5��������ʱ�䣨6�������ۣ�7��\n");
				printf("�޸�ͼ������(1)");     
				scanf("%d",&a);
				getchar();
					if(a == 1)
				{
					printf("��������ĺ��ͼ����Ϊ: ��");
					gets(num);
					strcpy(book.num, num);
				} 
		    	/*--------------------------------------------����*/
				printf("�޸�������    (2)");
				scanf("%d",&b);
				getchar();
				if(b == 2)
				{
					printf("��������ĺ������Ϊ��    ��");
					gets(name);
					strcpy(book.name,name);
				} 
				/*--------------------------------------------���� */
				printf("�޸���������?   (3)");
				scanf("%d",&c);
				getchar();
				if(c == 3)
				{
					printf("��������ĺ��������Ϊ��  ��");
					gets(writer);
					strcpy(book.writer,writer);
				}
				/*--------------------------------------------�����*/
				printf("�޸�ͼ��������?(4)");
				scanf("%d",&f);
				getchar();

				if(f == 4)
				{
					printf("��������ĺ��ͼ������Ϊ��");
					gets(cat);
					strcpy(book.cat,cat);
				}
				/*-------------------------------------------������*/
				printf("�޸ĳ��浥λ��?  (5)");
				scanf("%d",&d);
				getchar();

				if(d == 5)
				{
					printf("��������ĺ�ĳ��浥λΪ����");
					gets(addr);
					strcpy(book.addr,addr);
				}
				/*------------------------------------------����ʱ��*/
				printf("�޸ĳ���ʱ����?  (6)");
				scanf("%d",&f);
				getchar();

				if(f == 6)
				{
					printf("��������ĺ�ĳ���ʱ��Ϊ����");
					gets(time);
					strcpy(book.time,time);
				}
				/*--------------------------------------------����*/
				printf("�޸�ͼ��۸���?  (7)");
				scanf("%d",&g);
				getchar();

				if(g == 7)
				{
					printf("��������ĺ��ͼ��۸�Ϊ�� ��");
					gets(price);
					strcpy(book.price,price);
				}
				flag=1;
				printf("\n");
	
			}		
			fwrite(&book,sizeof(book),1,fp2); //��������Ϊһ������һ����д������ļ�
		}

		fclose(fp1);                          //�رջ���ָ��
		fclose(fp2);
		
		if(flag == 1)                         //�������б�־
		{ 
			printf("�޸ĳɹ�");
			remove("Datebast.txt");             //ɾ��ԭ�ļ�
			rename("temp.txt","Datebast.txt");  //����ʱ�ļ�����ΪDatebast.txt���������滻
		}
		else
		{
			printf("�Ҳ����˼�¼");
			getchar();
		}
		printf("�����޸���(y/n)");
		ch=getchar();
		getchar();
	}while(ch == 'Y' || ch == 'y');
}
/*********************************************************************************************************          6 ɾ��  ģ��        *************/
void del()
{
	display2() ;

	char name[10];
	int flag;
	char ch;
	FILE *fp1,*fp2;                                 //���������ļ�ָ��  fp1  , fp2
	do
	{
		if((fp1 = fopen("Datebast.txt","rb")) == NULL) //�ļ���
		{
			printf("\n���ܴ� Datebast.txt�ļ�");
			exit(1);
		}
		if((fp2 = fopen("temp.txt","wb")) == NULL)  //���������ļ�
		{
			printf("\n���ܴ� Datebast.txt�ļ�");

			exit(1);
		}

		printf("\n������Ҫɾ����ͼ����:");
		fflush(stdin);                              //�������
		gets(name); //��������
		flag = 0;   //��־λ
		while(!feof(fp1))                           //�ж��ļ�fp1�Ƿ�ָ���ļ�ĩβ
		{
			fread(&book,sizeof(book),1,fp1);
			if(strcmp(name,book.name) == 0)
			{
				flag = 1;
			}
			else
			{
				fwrite(&book,sizeof(book),1,fp2);   //��������Ϊһ������һ����д������ļ�
			}
		}
		fclose(fp1);             //�ر��ļ�
		fclose(fp2);             //�ر��ļ�

		if(flag == 1)
		{
			remove("Datebast.txt");//�Ƴ��ļ�
			rename("temp.txt","Datebast.txt");
			printf("ɾ���ɹ�!\n");
		}
		else 
		{
			printf("�Ҳ���ͼ����");
			remove("temp.txt");  //�Ƴ��ļ�
		}
		printf("����ɾ������ͼ������(y/n)");
		fflush(stdin);           //�������
		ch = getchar();
		getchar();
	}while(ch == 'y' || ch == 'Y');
	fflush(stdin);               //�������
}
//

