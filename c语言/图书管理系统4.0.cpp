#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//����α���Ϣ 
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
}musers;
//���˵� 
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
	printf("\t\t\t| |  [5]   �˳�ϵͳ                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
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
//¼����Ϣ 
void creat_book()
{
	system("cls");//���� 
	int n,i;
	FILE*fp;
	book *head, *node, *end;
	head=(book*)malloc(sizeof(book)); //���ٿռ� ,��ʼ��ͷָ�� 
	end=head;
	do
	{
		system("cls"); 
		node=(book*)malloc(sizeof(book));//ÿ����һ���������ᴴ��һ���µĿռ� 
		printf("\t\t\t\t  ***********************************************\n");
	    printf("\t\t\t\t  *          ��ӭ�����鼮¼�����           *\n");
	 	printf("\t\t\t\t  ***********************************************\n");
		printf("\t\t\t\t  *               �����鼮���                  *\n");
		printf("\t\t\t\t\t\t      ");
	    scanf("%d",&node->id);
	
		printf("\t\t\t\t  *               ¼���鼮����                  *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%s",node->name); 
	
		printf("\t\t\t\t  *               ¼���鼮����                 *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&node->count); 
		
		printf("\t\t\t\t  *               ¼���鼮����ʱ��                *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&node->status); 
		printf("\t\t\t\t  ---------------��¼���鼮��Ϣ��ɡ�-----------*\n");
		printf("\t\t\t\t  ***********************************************\n");
		end->next=node; //β���½ڵ� 
		end=node;      //ָ��β��� 
		printf("\t\t\t\t  *               1.��\t2.��                    *\n");
		printf("\t\t\t\t  *               �������Ƿ�Ҫ¼������:         *\n");
		printf("\t\t\t\t\t\t      ");
		scanf("%d",&n);
	}while(n==1);
	end->next=NULL;//β�ڵ��ָ����ָ��� 
	book* p;
	if((fp=fopen("books.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
      fp=fopen("books.txt","w");
      fclose(fp);
    }
	fp=fopen("books.txt","a"); //��׷�ӷ�ʽ���ļ�

	for (p = head->next; p != NULL; p = p->next)          //���ļ���д��Ϣ
	{
		printf("%d %s %d %f\n", p->id, p->name, p->count, p->status);
		fprintf(fp, "%d %s %d %f\n", p->id, p->name, p->count, p->status);
	}
	fclose(fp);                                           //�ر��ļ�
	printf("\n\n\t\t\t\t\t��Ϣ¼��ɹ���");
	system("pause");
}
void output_book()
{
	book* head, * r ,* p;
	FILE* fp = fopen("booklist.txt", "rt");      //���ļ�
	head = (book*)malloc(sizeof(book));
	head->next = NULL;                            //����ͷ���
	r = head;
	while(!feof(fp))
	{
		p=(book *)malloc(sizeof(book));                                       //���ٿռ� 
		fscanf(fp,"%d\t%s\t%d\t%f",&p->id,p->name,&p->count,&p->status);   
	
		r->next=p;
		p->next=NULL;
		r=p;
	}
	
	fclose(fp);                                   //�ر��ļ�
	system("cls");
	p = head->next;
	while (p)                                    //�������������Ϣ
	{
		printf("\t\t\t ��ı��\t�������\t�������\t��ĳ�������\n");
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
		printf("\t\t\t��������� :");
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
				printf("\t\t\t\t  ************�����쳣������������*******************\n");
				break;	
		}
		system("read");                        //��ͣ 
	    system("cls");                          //������û��������ظ�����Ŀ¼���� 
		if(n==0)
			break;
	}
}
/*��¼ϵͳ*/ 
int  manager_login()
{
//	system("read");                         
	system("cls");
    musers a,b;//����ṹ��The_users����
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
void manager_Input()
{
	system("read");                        //��ͣ 
	system("cls");
	musers a,b;//�ṹ�� The_users ����������
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
	 		fp = fopen("managers.text","a");
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
int main()
{
	system("color f0");
	int n;
	while(1)
	{
		//���˵� 
		menu_main();
		printf("\t\t\t��������� :");
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
