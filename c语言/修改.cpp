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
//�����¼��Ա��Ϣ 
typedef struct The_users   
{
    char id[11]; 
    char pwd[20];
}users;
void zjts()//����ͼ��
{
	FILE*fp;
	char i;
	int many=0;
    float price=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen("library.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
	fp=fopen("library.txt","a");
	
	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ��� ������ ����");
	
	for(;i!=27;)//Ϊ��ʵ������һ�κ�esc�˳�
	{
		printf("������:\n");
		scanf("%s%s%s%s%s%d%f",num,nam,aut,pub,cat,&many,&price);
		fprintf(fp,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",num,nam,aut,pub,cat,many,price);
	    printf("���������밴�س������������밴Esc\n");
        i=getch();//��ͣ����i���պ������һ��ָ��
        for (;i!=13&&i!=27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
        i=getch();
     }

	fclose(fp);
    printf("\n����ɹ����������������һ��!");
    getch();
	tsmain();//������һ��
}
void output_book()
{
	char name[11];
	book* head, * r, * s, * p;
	FILE* fp = fopen("booklist.txt", "rt");      //���ļ�
	head = (book*)malloc(sizeof(book));
	head->next = NULL;                            //����ͷ���
	r = head;
	while (!feof(fp))
	{
		s = (book *)malloc(sizeof(book));        //���ļ�����������
		fscanf(fp, "%d %s %d %lf",p->id,p->name,p->count,p->status);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	fclose(fp);                                   //�ر��ļ�
	system("cls");
	p = head->next;
	while (p)                                    //�������������Ϣ
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
	printf("\t\t\t| |  [5]   �˳�ϵͳ                  | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
void menu_user()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
	printf("\t\t\t| | * - * - * -��-Ա-��-��- * - * - * | |\n");
	printf("\t\t\t| *                                   * |\n");
	printf("\t\t\t| |  [1]   ����ͼ����Ϣ               | |\n");
	printf("\t\t\t| *  [2]   ����ͼ��                   * |\n");
	printf("\t\t\t| |  [3]   �黹ͼ��                   | |\n");
	printf("\t\t\t| |  [4]   �޸��˻���Ϣ               | |\n");
	printf("\t\t\t| *  [5]   �˳��û�����               * |\n");
	printf("\t\t\t| |                                   | |\n");
	printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}
//����Ա�˵���
void menu_manager()
{
	printf("\n\n");
	printf("\t\t\t *======================================*\n");
	printf("\t\t\t| | * - * - * ��-��-Ա-��-�� * - * - * | |\n");
	printf("\t\t\t| *                                    * |\n");
	printf("\t\t\t| |  [1]   ���ͼ��                    | |\n");
	printf("\t\t\t| *  [2]   ɾ��ͼ��                    * |\n");
	printf("\t\t\t| |  [3]   �޸�ͼ����Ϣ                | |\n");
	printf("\t\t\t| *  [4]   ����ͼ����Ϣ                * |\n");
	printf("\t\t\t| |  [5]   ��ʾȫ��ͼ����Ϣ            | |\n");
	printf("\t\t\t| *  [6]   ��ʾ���л�Ա��Ϣ            * |\n");
	printf("\t\t\t| |  [7]   ͳ�����н�����Ϣ            | |\n");
	printf("\t\t\t| |  [8]   ��ʾ������Ϣ����            | |\n");
	printf("\t\t\t| *  [9]   �˳�����Ա����              * |\n");
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
				printf("\t\t\t\t  ************�����쳣������������*******************\n");
				break;	
		}
		system("read");                        //��ͣ 
	    system("cls");                          //������û��������ظ�����Ŀ¼���� 
		if(n==0)
			break;
	}
}
//ע�� 
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
	 		fp = fopen("manager.text","a");
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
/*��¼ϵͳ*/ 
int  Input_login()
{
//	system("read");                         
	system("cls");
    users a,b;//����ṹ��The_users����
    FILE *fp;
    printf("\t\t\t\t   -----------  ��ӭ������¼���棡   -----------------\n");
    Sleep(1000);
    fp = fopen("manager.text","r");
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


//ɾ����Ϣ 
//void Delete(book *head)
//{
//	int n;
//	char i[20];
//	book *p,*p1=head;
//	p=p1->next;
//	printf("\t\t\t\t  *               ������ 1 ����ɾ������:");
//	scanf("%d",&n);
//	switch(n)
//	{
//		case 1:
//			printf("\t\t\t\t  *               ������Ҫɾ���ı��:");
//			scanf("%s",i);
//			while(p!=NULL)
//			{
//				if(strcmp(p->id,i) == 0) //�Ƚ�Ҫɾ���ı����p��ָ�ı�� 
//				{
//					printf("\t\t\t\t  *               ����������Ҫɾ���ĵ�Ӱ��Ϣ��\n\n");
//					printf("\t\t\t\t  *%s\t%s\t%d\t%.2lf\t\n",p->id,p->name,p->count,p->status);
//					p1->next=p->next; //��p��ָ����һ�����ĵ�ַ��ֵ����һ����� 
//					free(p); //�ͷſռ� 
//					printf("\t\t\t\t  -----------------���Ѿ���ȫɾ����--------------\n");
//				}
//				p1=p;
//				p=p->next;
//			}
//			break;
//		default:
//			printf("\t\t\t\t  ------------������Ƿ������������롿------------\n");
//			break;
//	}
//}
// 

//����ı��� 
//void output_book()
//{
//	book *q;
// 	q=read();//���ļ�����������������ݣ����´���һ����������ͷָ�� 
//	output(q);
//	printf("\t\t\t\t  ------------------��ӰƬ������ɡ�-----------------------\n");
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
				printf("\t\t\t\t  ************�����쳣������������*******************\n");
				break;	
		}
		system("read");                        //��ͣ 
	    system("cls");                          //������û��������ظ�����Ŀ¼���� 
		if(n==0)
			break;
	}
	return 0;
}
