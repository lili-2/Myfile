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
struct BOOK        //ͼ����Ϣ 
{
	char number[10];   //��¼�� 
	char name[10];     //���� 
	char author[10];    //������ 
	char type[10];      //���� 
	char time[8];        //����ʱ�� 
	float price;       //�۸� 
	int num;         //���� 
	int x;
	struct BOOK *next;   //ָ���� 
};
typedef struct BOOK Book;
typedef Book *book;	

void menu_main();     //���˵� 
void manager();       //�����߲˵� 
void student();       //ѧ���˵� 

void Input();		  //����Աע�� 
int  Input_login();   //����Ա��½ 
void S_Input();       //ѧ��ע�� 
int S_login(); 		  //ѧ����½ 

void input_book();    //ͼ����� 
void amend_book();    //�޸���Ϣ 
void del_book();      //ɾ��ͼ�� 
void print_book();    //ͼ������ 
void sort_book();     //����Ž������� 
void find_book();     //��ѯ 
void find_name_book();      //��������ѯ 
void find_author_book();    //�����߲�ѯ 
void find_number_book();    //����Ų�ѯ

void less_book();        //���� 
void add_book();         //���� 
void over();             //�˳� 


int length_list(book head);  //���������� 
void save_book(book p);//��ͼ����Ϣ�����ļ� 
book ss();//���ļ��ж�ͼ����Ϣ���γ�����������ͷ��� 

//���˵� 
void menu_main()
{
	system("cls"); 
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t|  * - * - * ��ӭ����ͼ�����ϵͳ * - * -*|\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   �û�ע��                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   �û���¼                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   ����Աע��                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   ����Ա��¼                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   �˳�ϵͳ                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
//����Ա�˵� 
void manager()    
{
	do
	{
		system("cls");  //���� 
		system("color f0");    //������ɫ 
		int t;
		printf("\t\t\t\t\t");
		printf(" ͼ���ѯ����ϵͳ\n\n");
		printf("\t\t\t\t\t");
		printf("|     1.ͼ�����    	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     2.�޸���Ϣ   	   	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     3.ɾ����Ϣ      	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     4.ͼ���ѯ      	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     5.ͼ������          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     6.����Ž�������	  |\n\n");
		printf("\t\t\t\t\t");
		printf("|     7.�˳�����          |\n\n");
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
//ѧ���˵� 
void student()    
{
	do
	{
		system("cls");  //���� 
		system("color f0");    //������ɫ 
		char t;
		printf("\t\t\t\t\t");
		printf(" ͼ���ѯ����ϵͳ\n\n");
		printf("\t\t\t\t\t");
		printf("|     1.����          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     2.����          |\n\n");
		printf("\t\t\t\t\t");
		printf("|     3.ͼ���ѯ      |\n\n");
		printf("\t\t\t\t\t");
		printf("|     4.ͼ������      |\n\n");
		printf("\t\t\t\t\t");
		printf("|     5.�˳�����      |\n\n");
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
//����Աע�� 
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
	 		fp = fopen("manager5.text","a");
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
//����Ա��¼ 
int  Input_login()
{
	system("cls");
    users a,b;//����ṹ��The_users����
    FILE *fp;
    printf("\t\t\t\t   -----------  ��ӭ������¼���棡   -----------------\n");
    Sleep(1000);
    fp = fopen("manager5.text","r");
    fread(&b, sizeof(struct The_users), 1, fp);
    printf("\t\t\t\t		�������˺�:");
    scanf("\t\t\t\t\t\t\t\t%s",a.id);   
    while (1)
   {   
       if (strcmp(a.id, b.id)==0)         //����д��û���
       {
           break;       
       }
       else 
       {
            if (!feof(fp))  //����ļ�û�ж���                            
        	{
               fread(&b, sizeof(struct The_users), 1, fp);
            }
            else
           {
               printf("\t\t\t\t                    ���û��������ڣ����������룡\n");
			   Sleep(500); 
               fclose(fp);  
			   return 0;              
           }
       }
    }
    printf("\t\t\t\t		����������:");
   	scanf("\t\t\t\t\t\t\t\t\t%s",a.pwd); 		
	do
	{   
        if (strcmp(a.pwd, b.pwd)==0)            /*�������ƥ��*/
		{  
		    fclose(fp);
		    printf("\t\t\t\t		��¼�ɹ�,��ӭʹ��!");
		    Sleep(500);
		    printf("\t\t\t\t         �������Ա����!");
		    manager();
		    return 1;
		}
	   else  
	   {    printf("\t\t\t\t		���벻��ȷ!��������������:");
	   		scanf("\t\t\t\t\t\t\t\t%s",&a.pwd);         
	   }
    }while(strcmp(a.pwd, b.pwd)==0);   
}
//ѧ��ע�� 
void S_Input()
{
//	system("read");                        //��ͣ 
	system("cls");
	stus a,b;//�ṹ�� The_users ����������
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
	 		fp = fopen("students5.text","a");
	        fwrite(&a, sizeof(struct The_stus), 1, fp);
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
/*ѧ����¼ϵͳ*/ 
int S_login()
{
//	system("read");                         
	system("cls");
    stus a,b;//����ṹ��The_users����
    FILE *fp;
    printf("\t\t\t\t   -----------  ��ӭ������¼���棡   -----------------\n");
    Sleep(1000);
    fp = fopen("students5.text","r");
    fread(&b, sizeof(struct The_stus), 1, fp);
    printf("\t\t\t\t		�������˺�:");
    scanf("\t\t\t\t\t\t\t\t%s",a.id);   
    while (1)
   {   
       if (strcmp(a.id, b.id)==0)         //����д��û���
       {
           break;       
       }
       else 
       {
            if (!feof(fp))  //����ļ�û�ж���                            
        	{
               fread(&b, sizeof(struct The_stus), 1, fp);
            }
            else
           {
               printf("\t\t\t\t                    ���û��������ڣ����������룡\n");
			   Sleep(500); 
               fclose(fp);  
			   return 0;              
           }
       }
    }
    printf("\t\t\t\t		����������:");
   	scanf("\t\t\t\t\t\t\t\t\t%s",a.pwd); 		
	do
	{   
        if (strcmp(a.pwd, b.pwd)==0)            /*�������ƥ��*/
		{  
		    fclose(fp);
		    printf("\t\t\t\t		��¼�ɹ�,��ӭʹ��!");
		    Sleep(500);
		    printf("\t\t\t\t         ����ѧ������!");
		    student();
		    return 1;
		}
	   else  
	   {    printf("\t\t\t\t		���벻��ȷ!��������������:");
	   		scanf("\t\t\t\t\t\t\t\t%s",&a.pwd);         
	   }
    }while(strcmp(a.pwd, b.pwd)==0);   
}
//ͼ��¼�� 
void input_book()    
{
	do
	{
		system("cls");
		system("color f0");
		char t;
		book p;
		p=(book)malloc(N);     //����ռ� 
		//����ͼ����Ϣ
		printf("\n\t\t\t\t");
		printf("������ͼ����(С��10λ��):");
		scanf("%s",p->number);getchar();
		printf("\n\t\t\t\t");
		printf("����������(С��10λ��)��");
		scanf("%s",p->name);getchar();
		printf("\n\t\t\t\t");
		printf("������������(С��10λ��)��");
		scanf("%s",p->author);getchar();
		printf("\n\t\t\t\t");
		printf("������ͼ�����(С��10λ��)��");
		scanf("%s",p->type);getchar();
		printf("\n\t\t\t\t");
		printf("������ͼ�����ʱ��(С��8λ��)��");
		scanf("%s",p->time);getchar();
		printf("\n\t\t\t\t");
		printf("������ͼ��۸�(float)");
		scanf("%f",&p->price);getchar();
		printf("\n\t\t\t\t");
		printf("������ͼ��������(int)");
		scanf("%d",&p->num);
		save_book(p);
		printf("\n\t\t\t\t\t");
		printf("���ڱ���....");
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("| ����ɹ����Ƿ������  |");
		printf("\n\t\t\t\t\t");
		printf("| 1.��             2.�� |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		while(1)    //������ѭ������Ч��ֹ������������ 
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
//ͼ������ 
void print_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	int sum=0;
	head=ss();
	printf("\n\t");
	printf("***********************************ͼ������**********************************************");
	printf("\n\t");
	printf("----------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("    ���       ����        ������         ͼ�����     ����ʱ��       �۸�        ����");
	printf("\n\t");
	printf("----------------------------------------------------------------------------------------");
	if(head==NULL)
	{
		printf("\n\t\t\t\t\t");
		printf("�����ʱû����Ŷ~�Ͽ�ȥ��Ӽ�����^_^(�����������)");
		getch();
		manager();
	}
	p=head;
	while(p!=NULL)
	{
		printf("\n\t");
		printf("%6s%14s%15s%14s%13s%13.2f%10d\n",p->number,p->name,p->author,p->type,p->time,p->price,p->num);
		i++;
		sum+=p->num;//����ͼ������ 
		p=p->next;
	}
	printf("\n\t\t\t\t\t");
	printf("ͼ������Ϊ��%d",sum);
	printf("\n\t\t\t\t\t");
	printf("�����������");
	getch();//�����Ժ��� 
}
//ɾ����Ϣ 
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
		head=ss();    //���ú��������ر�ͷ��ַ 
		printf("\n\t\t\t\t\t");
		printf("��������Ҫɾ����ͼ���������");
		scanf("%s",name);getchar();
		p=head;
		printf("\n\t");
		printf("*****************************************ͼ����Ϣ*******************************************");
		printf("\n\t");
		printf("----------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  ���        ����        ������         ͼ�����       ����ʱ��          �۸�        ����");
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
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("\n\t");
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("��������Ҫɾ����ͼ��ı�ţ�");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("�����������������!");
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
		printf("|     �Ƿ�ȷ��ɾ����    |");
		printf("\n\t\t\t\t\t");
		printf("| 1.��             2.�� |");
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
			printf("���ļ�ʧ��"); 
		}
		if(fwrite(head,N,1,fp)!=1)
		{
			printf("д���ļ�ʧ��!"); 
		}
		fclose(fp);
		if(head!=NULL)
		{
			p=head->next;
			fp=fopen("mylikebooks","ab");
			if(fp==NULL)
			{
				printf("���ļ�ʧ��"); 
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)
				{
					printf("д���ļ�ʧ��!"); 
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		printf("\t\t\t\t\t");
		printf("����ɾ�������Ժ�....");
		Sleep(500);
		system("cls");
		printf("\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("|  ɾ���ɹ����Ƿ������ |");
		printf("\n\t\t\t\t\t");
		printf("| 1.��             2.�� |");
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
//�޸�ͼ����Ϣ 
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
		FILE *fp;    //�ļ�ָ�� 
		char _name[10];
		char number[10];   //��� 
		char name[10];     //���� 
		char author[10];    //������ 
		char type[10];      //���� 
		char time[8];        //����ʱ�� 
		float price;       //�۸� 
		int num;         //���� 
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("��������Ҫ�޸ĵ�ͼ���������");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************ͼ����Ϣ*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  ���    ����        ������         ͼ�����            ����ʱ��          �۸�        ����");
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
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("\n\t\t\t\t\t");
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("��������Ҫ�޸ĵ�ͼ��ı�ţ�");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("�����������������!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //��p����ָ���ͷ 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //���������ѯ���������Ľ�� 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //���p��Ϊ�� 
		{
			//����Ҫ�޸ĵ���Ϣ 
			printf("\n\t\t\t\t\t");
			printf("������ͼ����(С��10λ��)��");
			scanf("%s",number);getchar();strcpy(p->number,number);
			printf("\n\t\t\t\t\t");
			printf("����������(С��10λ��)��");
			scanf("%s",name);getchar();strcpy(p->name,name);
			printf("\n\t\t\t\t\t");
			printf("������������(С��10λ��)��");
			scanf("%s",author);getchar();strcpy(p->author,author);
			printf("\n\t\t\t\t\t");
			printf("������ͼ�����(С��10λ��)��");
			scanf("%s",type);getchar();strcpy(p->type,type);
			printf("\n\t\t\t\t\t");
			printf("������ͼ�����ʱ��(С��8λ��)��");
			scanf("%s",time);getchar();strcpy(p->time,time);
			printf("\n\t\t\t\t\t");
			printf("������ͼ��۸�");
			scanf("%f",&price);getchar();p->price=price;
			printf("\n\t\t\t\t\t");
			printf("������ͼ��������");
			scanf("%d",&num);getchar();p->num=num;
		}
		system("color f0");
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("|     �Ƿ�ȷ���޸ģ�    |");
		printf("\n\t\t\t\t\t");
		printf("| 1.��             2.�� |");
		printf("\n\t\t\t\t\t");
		printf("|                       |");
		printf("\n\t\t\t\t\t");
		printf("-------------------------");
		printf("\n\t\t\t\t\t");
		while(1)   //������ѭ����ֹ������������ 
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
		printf("�����޸ģ����Ժ�....");
		fp=fopen("mylikebooks","wb");   //��ֻд�ķ�ʽ����Ϊmybook�Ķ������ļ����򿪵�ͬʱ����ļ��е����� 
		if(fp==NULL)
		{
			printf("���ļ�ʧ��"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //��headд��fp��ָ����ļ��� 
		{
			printf("д���ļ�ʧ��!"); 
		}
		fclose(fp);   //�ر��ļ� 
		if(head!=NULL)   //���head��Ϊ�� 
		{
			p=head->next;     //��pָ��ڶ������ 
			fp=fopen("mylikebooks","ab");   //��׷�ӵķ�ʽ���ļ� 
			if(fp==NULL)
			{
				printf("���ļ�ʧ��");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//��pд��fp��ָ����ļ���
				{
					printf("д���ļ�ʧ��!");
				}
				p=p->next;
			}
			fclose(fp);  //�ر��ļ� 
		}
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("�޸ĳɹ��������Զ��������˵�....");
		Sleep(500);
		break;
	}while(1);
}
//���������� 
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
//����Ž������� 
void sort_book()
{
	do
	{
		system("cls");
		system("color f0");
		book head,p,pre=NULL,q;
		
		char ch,t;
		FILE *fp;    //�ļ�ָ�� 
		char _name[10];
		char number[10];   //��� 
		char name[10];     //���� 
		char author[10];    //������ 
		char type[10];      //���� 
		char time[8];        //����ʱ�� 
		float price;       //�۸� 
		int num;         //���� 
		
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
					//ת���м���� 
					strcpy(_name,p->name);
					strcpy(number,p->number);
					strcpy(name,p->name);
					strcpy(author,p->author);
					strcpy(type,p->type);
					strcpy(time,p->time);
					price = p->price;
					num = p->num; 
					//���� 
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
		printf("�����������Ժ�....");
		
		fp=fopen("mylikebooks","wb");   //��ֻд�ķ�ʽ����Ϊmybook�Ķ������ļ����򿪵�ͬʱ����ļ��е����� 
		if(fp==NULL)
		{
			printf("���ļ�ʧ��"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //��headд��fp��ָ����ļ��� 
		{
			printf("д���ļ�ʧ��!"); 
		}
		fclose(fp);   //�ر��ļ� 
		if(head!=NULL)   //���head��Ϊ�� 
		{
			p=head->next;     //��pָ��ڶ������ 
			fp=fopen("mylikebooks","ab");   //��׷�ӵķ�ʽ���ļ� 
			if(fp==NULL)
			{
				printf("���ļ�ʧ��");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//��pд��fp��ָ����ļ���
				{
					printf("д���ļ�ʧ��!");
				}
				p=p->next;
			}
			fclose(fp);  //�ر��ļ� 
		}
		
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("����ɹ��������Զ��������˵�....");
		Sleep(1000);
		break;
	}while(1);
}
//��ѯͼ�� 
void find_book()  
{
	do
	{
		system("cls");  //���� 
		system("color f0");
		char t;
		printf("\n\n\t\t\t\t");
		printf(" ͼ���ѯ");
		printf("\n\n\t\t\t\t");
		printf("|     1.����  ��ѯ      |");
		printf("\n\n\t\t\t\t");
		printf("|     2.����  ��ѯ      |");
		printf("\n\n\t\t\t\t");
		printf("|     3.���  ��ѯ      |");
		printf("\n\n\t\t\t\t");
		printf("��0�������˵�");
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
 //�����ֲ�ѯ 
void find_name_book() 
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char name[10];
	printf("\n\t\t\t\t");
	printf("��������Ҫ��ѯͼ���������");
	scanf("%s",name);
	printf("\n\t\t\t\t");
	printf("���ڲ�ѯ....");
	Sleep(500);
	p=head;
	system("cls");
	printf("\n\t");
	printf("***************************************ͼ������*******************************************");
	printf("\n\t");
	printf("-----------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   ���        ����       ������         ͼ�����      ����ʱ��          �۸�        ����");
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
	printf("����������أ�");
	getch();
	return ;
}
//����������ѯ 
void find_author_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char author[10];
	printf("\n\t\t\t\t");
	printf("��������Ҫ��ѯͼ�����������");
	scanf("%s",author);
	printf("\n\t\t\t\t");
	printf("���ڲ�ѯ....");
	Sleep(500);
	p=head;
	system("cls");
	printf("\n\t");
	printf("************************************ͼ������***********************************************");
	printf("\n\t");
	printf("-------------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   ���         ����        ������         ͼ�����      ����ʱ��          �۸�        ����");
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
	printf("����������أ�");
	getch();
	return;
} 
//��ͼ���Ų�ѯ 
void find_number_book()   
{
	system("cls");
	system("color f0");
	book head,p;
	int i=11;
	head=ss();
	char number[10];
	printf("\n\t\t\t\t");
	printf("��������Ҫ��ѯͼ��ı�ţ�");
	scanf("%s",number);
	printf("\n\t\t\t\t");
	printf("���ڲ�ѯ....");
	Sleep(500);
	p=head;
	printf("\n\t");
	printf("******************************************ͼ������********************************************");
	printf("\n\t");
	printf("-----------------------------------------------------------------------------------------------");
	printf("\n\t");
	printf("   ���        ����        ������         ͼ�����         ����ʱ��          �۸�        ����");
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
	printf("����������أ�");
	getch();
	return ; 
}
void save_book(book p)   //��p������д���ļ� 
{
	FILE *fp;    //�ļ�ָ�� 
	fp=fopen("mylikebooks","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ� 
	if(fp==NULL)
	{
		printf("�ļ���ʧ��");
	}
	if(fwrite(p,N,1,fp)!=1)   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ��� 
	{
		printf("д�����");
	}
	fclose(fp);    //�ر��ļ�  
} 

book ss()      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;       //�ļ�ָ�� 
	int n=0;
	book head=NULL;
	book p2,p,pr=NULL;
	fp=fopen("mylikebooks","ab+");     //��ֻ���ķ�ʽ���ļ� 
	if(fp==NULL)
	{
		printf("�ļ���ʧ��\n");
	}
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
	   n++;
	   	p=(book)malloc(N); //���ڴ�����һ�οռ� 
	   fread(p,N,1,fp);     //��fp��ָ����ļ��е����ݸ���p 
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //�������� 
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
    fclose(fp);    //�ر��ļ� 
    return head;   //����ͷָ�� 
}
//���� 
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
		FILE *fp;    //�ļ�ָ�� 
		char _name[10];
		char number[10];   
		int num;          
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("��������Ҫ���ͼ���������");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************ͼ����Ϣ*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  ���    ����        ������         ͼ�����            ����ʱ��          �۸�        ����");
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
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("\n\t\t\t\t\t");
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("��������Ҫ���ͼ��ı�ţ�");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("�����������������!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //��p����ָ���ͷ 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //���������ѯ���������Ľ�� 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //���p��Ϊ�� 
		{
			printf("\n\t\t\t\t\t");
			printf("������Ҫ���ͼ��������");
			scanf("%d",&num);getchar();
			if(p->num - num >= 0)
			{
				p->num=p->num - num;
			}else
			{
				Sleep(3000);
				printf("\n\t\t\t\t"); 
				printf("��Ǹ��ͼ�������������½���ѡ��");
				return ; 
			} 
		}
		fp=fopen("mylikebooks","wb");   //��ֻд�ķ�ʽ����Ϊmybook�Ķ������ļ����򿪵�ͬʱ����ļ��е����� 
		if(fp==NULL)
		{
			printf("���ļ�ʧ��"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //��headд��fp��ָ����ļ��� 
		{
			printf("д���ļ�ʧ��!"); 
		}
		fclose(fp);   //�ر��ļ� 
		if(head!=NULL)   //���head��Ϊ�� 
		{
			p=head->next;     //��pָ��ڶ������ 
			fp=fopen("mylikebooks","ab");   //��׷�ӵķ�ʽ���ļ� 
			if(fp==NULL)
			{
				printf("���ļ�ʧ��");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//��pд��fp��ָ����ļ���
				{
					printf("д���ļ�ʧ��!");
				}
				p=p->next;
			}
			fclose(fp);  //�ر��ļ� 
		}
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("����ɹ��������Զ��������˵�....");
		Sleep(500);
		break;
	}while(1);
}
//���� 
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
		FILE *fp;    //�ļ�ָ�� 
		char _name[10];
		char number[10];   //��¼�� 
		int num;         //���� 
		head=ss();
		p=head;
		printf("\n\t\t\t\t\t");
		printf("��������Ҫ����ͼ���������");
		scanf("%s",_name);getchar();
		printf("\n\t");
		printf("***********************************ͼ����Ϣ*************************************************");
		printf("\n\t");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n\t");
		printf("  ���    ����        ������         ͼ�����            ����ʱ��          �۸�        ����");
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
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("\n\t\t\t\t\t");
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("\n\t\t\t\t\t");
			printf("��������Ҫ����ͼ��ı�ţ�");
			scanf("%s",x);getchar();
			if(strcmp(x,number))
			{
				printf("\n\t\t\t\t\t");
				printf("�����������������!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p=head;     //��p����ָ���ͷ 
		strcpy(number,p->number);
		while(p!=NULL&&strcmp(x,number))  //���������ѯ���������Ľ�� 
		{
			p=p->next;
			strcpy(number,p->number);
		}
		if(p)    //���p��Ϊ�� 
		{
			//����Ҫ�޸ĵ���Ϣ 
			printf("\n\t\t\t\t\t");
			printf("������Ҫ����ͼ��������");
			scanf("%d",&num);getchar();
			p->num=p->num + num;
		}
		fp=fopen("mylikebooks","wb");   //��ֻд�ķ�ʽ�򿪶������ļ����򿪵�ͬʱ����ļ��е����� 
		if(fp==NULL)
		{
			printf("���ļ�ʧ��"); 
		}
		if(fwrite(head,N,1,fp)!=1)   //��headд��fp��ָ����ļ��� 
		{
			printf("д���ļ�ʧ��!"); 
		}
		fclose(fp);   //�ر��ļ� 
		if(head!=NULL)   //���head��Ϊ�� 
		{
			p=head->next;     //��pָ��ڶ������ 
			fp=fopen("mylikebooks","ab");   //��׷�ӵķ�ʽ���ļ� 
			if(fp==NULL)
			{
				printf("cannot open file");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)//��pд��fp��ָ����ļ���
				{
					printf("write error!");
				}
				p=p->next;
			}
			fclose(fp);  //�ر��ļ� 
		}
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		printf("\n\t\t\t\t\t");
		printf("����ɹ��������Զ��������˵�....");
		Sleep(500);
		break;
	}while(1);
}
//�˳���� 
void over()       
{
	system("cls");
	char t;
	printf("\n\n\t\t\t\t\t");
	printf("-----------------------");
	printf("\n\n\t\t\t\t\t");
	printf("|   ��ȷ��Ҫ�˳���  |");
	printf("\n\n\t\t\t\t\t");
	printf("| 1.ȷ��     2.ȡ��   |");
	printf("\n\n\t\t\t\t\t");
	printf("-----------------------");
	printf("\n\n\t\t\t\t\t");
	while(1)
	{
		scanf("%c",&t);      //����t
		switch(t)
		{
			case '1':
			system("cls");
		    system("color f0");
			printf("\n\n\t\t\t\t\t");
			printf("���ڰ�ȫ�˳�....");
			Sleep(1000);     //��ͣ1�� 
			system("cls");
			system("color f0");
			printf("\n\n\t\t\t\t\t");
			printf("ллʹ�ã�");
			printf("\n\n\t\t\t\t\t");
			printf("by-by^_^");
			exit(0);  break; //��ֹ���� 
			case '2':
			menu_main(); break;   //���ú���������˵� 
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
				printf("\t\t\t\t  ************�����쳣������������*******************\n");
				break;	
		}
	    system("cls");                   //������û��������ظ�����Ŀ¼���� 
		if(n==0)
			break;
	}
	return 0;
}
