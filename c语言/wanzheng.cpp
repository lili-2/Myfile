#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<windows.h> 
#include<conio.h> 
char n[5];   		//��� 
char na[20]; 	//���� 
int num;    	//ʣ���� 
int pc;     	//�۸� 
typedef struct Medicine{
	char id[5];					//ҩƷ���
	char name[20];			//ҩƷ����
	int sum;				//ʣ���� 
	int  price;				//�۸�
	struct Medicine *next;	//ָ���� 
	
}Linklist;
struct user
{
	char username[20];
	char usermima[20];
};
//���� 
void first();
void zhuce();
void denglu();
Linklist* add_medicine(Linklist *head);        //���ҩƷ��Ϣ 
Linklist* delet_medicine(Linklist *head);      //ɾ��ҩƷ��Ϣ 
void change_medicine(Linklist *head);          //�޸�ҩƷ��Ϣ 
void find(Linklist *head);                     //��ѯ 
void findnum_medicine(Linklist *head);         //����ҩƷ��Ϣ(���) 
void findname_medicine(Linklist *head);        //����ҩƷ��Ϣ(����)
void sort(Linklist *head);                     //����
void price_medicine(Linklist *head);           //����ҩƷ�۸��������� 
void number_medicine(Linklist *head);          //����ҩƷʣ�������򣨽��� 
void sum_medicine(Linklist *head);             //ͳ����ҩƷʣ���� 
void keep_medicine(Linklist *head);            //����Ϣ�������ļ��� 
void findprice_medicine(Linklist *head);       //��ѯҩƷ�۸� 
void insert_medicine(Linklist *head);          //����ҩƷ��Ϣ 
Linklist* open_medicine();                     //���ļ� 
void print_medicine(Linklist *head);           //���ҩƷ��Ϣ

void first()                                           
{       
    printf(" ___________________________________________________________\n");
    printf("|                 ��ӭʹ��ҩ�����ϵͳ                      |\n");
	printf("|                        1-��¼                             |\n");
    printf("|                        2-ע��                             |\n");
    printf("|                        0-�˳�                             |\n");
    printf("|___________________________________________________________|\n");
    printf("��ѡ������� ") ;
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    	case 1:
    		system("cls");
    		denglu();                      
			system("cls");                    
			break;
		case 2:
			system("cls");
			zhuce();
			system("cls");
			first();
			break;
		case 0:
			exit(1); 
		default:first();
	}
 } 
void zhuce()
{
	
	FILE *fp;
	int i,j,flag=0;
	char ch,bh;
	struct user a;
	char name[20];
	char code1[20];
	char code2[20];
	while(1)
	{	
		printf("��ӭʹ��ҩ�����ϵͳ!\n");
		printf("�û�ע��\n");
		printf("�������û�����\n");
		scanf("%s",name);
		if(strlen(name)>20)
    {
    	printf("�û���λ�����࣬����������\n");
    	scanf("%s",name);
	}
		fflush(stdin); 
		fp= fopen("zhanghao.txt","r");
		if(fp==NULL)
		{
			fp= fopen("zhanghao.txt","w");
			fclose(fp);
			fp= fopen("zhanghao.txt","r");
		}
		flag=0;
		while(!feof(fp))
		{
			fscanf(fp,"%s %s\n",a.username,a.usermima);
			if(strcmp(a.username,name)==0)
			{
				flag=1;
				break;
			}	
		}
		fclose(fp);
		if(flag==1)
		{
			printf("���û����Ѵ��ڣ�"); 
			Sleep(1000);
			system("cls");
			first();
		}
		else
		{
			
			while(1)
			{
				printf("\n���������룺\n");
				while((ch=getch())!='\r')//�ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
				{
					if(ch=='\b')
					{
						if(i!=0)
						{
							printf("\n");
						    i--;	
						}
					}
					else
					{
						putchar('*');
						code1[i++]=ch;
					}
				}
				code1[i]='\0';
				i=0;
				j=0;
				printf("\n���ٴ���������:   "); 
				while((bh=getch())!='\r')
				{
					if(bh=='\b')
					{
						if(j!=0)
						{
							printf("\n");
						    j--;	
						}
					}
					else
					{
						putchar('*');
						code2[j++]=bh;
					}
				}
				code2[j]='\0';
				j=0;
				if(strcmp(code1,code2)==0)
				{
					fp = fopen("zhanghao.txt","a"); 
					fprintf(fp,"%s %s\n",name,code1);
					fclose(fp);
					break;
				}
			}
			printf("\nע��ɹ�!\n");
			printf("����������(1)\n");
			printf("��������������ע��\n");
			if(getchar()=='1')
				break;
			Sleep(1000);
			system("cls");
		}
	}
 } 
void denglu()
{
	FILE *fp;
	int i=0;
	char ch;
	struct user a;
	char code[20];
	char name[20];
	int	flag=0;
	fp=fopen("zhanghao.txt","r");
	printf("\n�û���¼\n");
	fclose(fp); 
	do
	{
		fp=fopen("zhanghao.txt","r");
		printf("\n�������û���:");
		scanf("%s",name);
		if(strlen(name)>20)
    {
    	printf("�û���λ�����࣬����������\n");
    	scanf("%s",name);
	}
		printf("\n����������:");
		while((ch=getch())!='\r')
		{
			if(ch=='\b')
			{
				if(i!=0)
				{
					printf("\b \b");
				    i--;	
				}
			}
			else
			{
				putchar('*');
				code[i++]=ch;
			}
		}
		code[i]='\0';
		while(!feof(fp))
		{
			fscanf(fp,"%s %s\n",a.username,a.usermima);   
			if(strcmp(name,a.username)==0 && strcmp(code,a.usermima)==0)
			{
				flag=1;
				break;
			} 
		}
		fclose(fp);
		if(flag)
		{
			printf("\n��½�ɹ���\n");
			Sleep(1000);
			break;
		}
		else
		{
			printf("�������\n\n");
			printf("�����½���ѡ��\n");
			Sleep(1000);
			system("cls");
				first();	
			
					
		}
		
	}while(ch=='1');
}

Linklist* add_medicine(Linklist *head) 		   //���ҩƷ��Ϣ 
{
	printf("������ҩƷ��Ϣ��\n");
	printf("ҩƷ��ţ�");
	scanf("%s",n);
	Linklist *q;
	q=head;
	while (q->next!=NULL)
	{
		if(strcmp(q->next->id, n)==0)
		{
			printf("��ҩƷ�Ѵ��ڣ����������\n");
			break;
		}
	    q=q->next;
	}
	if(q->next==NULL)
	{
		Linklist *p;
		p=(Linklist*)malloc(sizeof(Linklist));
		strcpy(p->id,n);   
		printf("ҩƷ����");
		scanf("%s",p->name);
		printf("ʣ������");
			scanf("%d", &num);
			p->sum=num;
		printf("ҩƷ�۸�");
			scanf("%d", &pc);
			p->price=pc;
			p->next=q->next;
			q->next=p;
	}
	return head;
}
Linklist* delet_medicine(Linklist *head)//ɾ��ҩƷ��Ϣ 
{
	Linklist *q,*p;
	q=head;
	printf("������ҩƷ��Ϣ:\n");
	printf("ҩƷ���:");
	scanf("%s",&n);
	while(q->next!=NULL)
	{
		if(strcmp(q->next->id,n)==0)
		{
			p=q->next;
			q->next=p->next;
			free(p);
			printf("ҩƷ��Ϣɾ���ɹ�\n");
			break;
		}
		q=q->next;
	}
	if(q->next==NULL)
	{
		printf("û�е�ǰҩƷ��Ϣ��\n");
	}
	return head;
}
void change_medicine(Linklist *head)//�޸�ҩƷ��Ϣ 
{
	int choice;
	Linklist *p,*q;
    int  m;
	q=head;
	printf("������Ҫ�޸ĵ�ҩƷ��Ϣ:\n");
	printf("ҩƷ���:");
	scanf("%s",&n);
	while(q->next!=NULL)
	{
		if(strcmp(q->next->id,n)==0)
		{
			p=q->next;
			printf("�Ѿ���ѯ����ҩƷ��Ϣ:\n");
			printf("ҩƷ���:%s ����:%s ʣ����:%d �۸�%d\n",
		        p->id,p->name,p->sum,p->price);
		    printf("----------------------------------------------------------------\n");
		    
		    printf("��ѡ��Ҫ�޸ĸ�ҩƷ����Ϣ\n");
			printf("1.���   2.����   3.ʣ����   4.�۸�   5.ȫ��\n");
			scanf("%d",&choice);
			if (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5)
			{
				printf("������������������������롣\n");
				scanf("%d",&choice);
			}
		    if(choice==5)
		    {
			printf("�������µ�ҩƷ��Ϣ:\n");
			printf("������ҩƷ��ţ�");
			scanf("%s",&n);
			strcpy(p->id,n);
			printf("������ҩƷ����: ");
			scanf("%s",na);
			strcpy(p->name,na);
			printf("������ʣ������");
			scanf("%d",&num);
			p->sum= num;
			printf("������ҩƷ�۸�");
			scanf("%d",&pc);
			p->price=pc;
			printf("�޸ĳɹ�!\n"); 
			break; 
	        }
	        
	        if(choice==1)
		    {
			printf("�������µ�ҩƷ��Ϣ:\n");
            printf("������ҩƷ��ţ�");
			scanf("%s",&n);
			strcpy(p->id,n);
  			printf("�޸ĳɹ�!\n"); 
			break; 
	        }
	        
	        if(choice==2)
		    {
			printf("�������µ�ҩƷ��Ϣ:\n");
            printf("������ҩƷ����: ");
			scanf("%s",na);
			strcpy(p->name,na);
  			printf("�޸ĳɹ�!\n"); 
			break; 
	        }
	        
	        if(choice==3)
		    {
			printf("�������µ�ҩƷ��Ϣ:\n");
            printf("������ʣ������");
			scanf("%d",&num);
			p->sum= num;
  			printf("�޸ĳɹ�!\n"); 
			break; 
	        }
	        
	        if(choice==4)
		    {
			printf("�������µ�ҩƷ��Ϣ:\n");
            printf("������ҩƷ�۸�");
			scanf("%d",&pc);
			p->price=pc;
  			printf("�޸ĳɹ�!\n"); 
			break; 
	        }
	}
	    q=q->next;
	
}
	if(q->next==NULL)
	{
		printf("û�д�ҩƷ��Ϣ!\n");
    }	
}
void find(Linklist *head)  //���� 
{
	int n;
	printf("��ѡ����ҷ�ʽ: 1.����Ų���\t  2.�����Ʋ���\t\n");
    scanf("%d",&n);
	switch(n)
	{
	    case 1:
	        findnum_medicine(head);
	        break;
	    case 2:
	   	    findname_medicine(head);
	   	    break;
	    default:
		    printf("������������\n");
		    break;
    }
}
void findnum_medicine(Linklist *head)//����ҩƷ��Ϣ (���) 
{
	Linklist *q,*p;
	q=head;
	printf("������ҩƷ���:");
	scanf("%s",&n);
	while(q->next!=NULL)
	{
		if(strcmp(q->next->id,n)==0)
		{
			p=q->next;
			printf("ҩƷ��Ϣ���£�\n"); 
			printf("ҩƷ��:%s\n",p->name);
			printf("ʣ����:%d\n", p->sum);
			printf("�۸�:%d\n", p->price);
			break;
		}
		q=q->next;
	}
	if (p==NULL) 
	{
		printf("û�е�ǰҩƷ��Ϣ��");
	}
}

void findname_medicine(Linklist *head)//����ҩƷ��Ϣ(����) 
{
	Linklist *q,*p;
	q=head;
	printf("������ҩƷ����:\n");
	scanf("%s",&na);
	while(q->next!=NULL)
	{
		if(strcmp(q->next->name,na)==0)
		{
			p=q->next;
			printf("ҩƷ��Ϣ���£�\n"); 
			printf("ҩƷ���:%s\n",p->id); 
			printf("ҩƷ��:%s\n",p->name);
			printf("ʣ����:%d\n", p->sum);
			printf("�۸�:%d\n", p->price);
			break;
		}
		q=q->next;
	}
	if (p==NULL) 
	{
		printf("û�е�ǰҩƷ��Ϣ��");
	}
}
void sort(Linklist *head)//���� 
{
	int n; 
   	printf("��ѡ������ʽ: 1.���۸���������   2.��ҩƷʣ������������   \n");
	scanf("%d",&n);
	switch(n)
	{
	    case 1:
	        price_medicine(head);
	        break;
	    case 2:
	   	    number_medicine(head);
	   	    break;
	    default:
		    printf("������������\n");
		    break;
    }
}
void price_medicine(Linklist *head)//���۸�����ð�ݣ� 
{
	Linklist *h,*p,*q,*c;
	h=head->next;
	if(h==NULL)
	{
		printf("û���κ�ҩƷ��Ϣ");
	}
	while(h!=NULL)
	{
		p=h;
		q=h->next;
		Linklist *t;  //�ݴ�ڵ� 
		t=(Linklist*)malloc(sizeof(Linklist));
		while(q!=NULL)
		{
			if(q->price<p->price)
			{
				strcpy(t->id,q->id);  //�ȸ���q�����Ϣ��t 
				strcpy(t->name,q->name);
				t->sum=q->sum;
				t->price=q->price;
				
				strcpy(q->id,p->id);  //����p�����Ϣ��q
				strcpy(q->name,p->name);
				q->sum=p->sum;
				q->price=p->price;
				
				strcpy(p->id,t->id);  //�����ݴ�����Ϣ��p
				strcpy(p->name,t->name);
				p->sum=t->sum;
				p->price=t->price;
			}
			q=q->next;
		}
		h=h->next;
	}
	printf("������ҩƷ��ϢΪ��\n");
	c=head->next;
	while(c!=NULL)
	{
	   printf("ҩƷ���:%s ����:%s ʣ����:%d �۸�%d\n",
		      c->id,c->name,c->sum,c->price);
	   c=c->next;
    }
 } 
 void number_medicine(Linklist *head)//��ҩƷʣ��������ð�ݣ� 
 {
 	Linklist *h,*p,*q,*c;
	h=head->next;
	if(h==NULL)
	{
		printf("û���κ�ҩƷ��Ϣ");
	}
	while(h!=NULL)
	{
		p=h;
		q=h->next;
		Linklist *t;  //�ݴ�ڵ� 
		t=(Linklist*)malloc(sizeof(Linklist));
		while(q!=NULL)
		{
			if(q->sum>p->sum)
			{
				strcpy(t->id,q->id);  //�ȸ���q�����Ϣ��t 
				strcpy(t->name,q->name);
				t->sum=q->sum;
				t->price=q->price;
				
				strcpy(q->id,p->id);  //����p�����Ϣ��q
				strcpy(q->name,p->name);
				q->sum=p->sum;
				q->price=p->price;
				
				strcpy(p->id,t->id);  //�����ݴ�����Ϣ��p
				strcpy(p->name,t->name);
				p->sum=t->sum;
				p->price=t->price;
			}
			q=q->next;
		}
		h=h->next;
	}
	printf("������ҩƷ��ϢΪ��\n");
	c=head->next;
	while(c!=NULL)
	{
	   printf("ҩƷ���:%s ����:%s ʣ����:%d �۸�%d\n",
		      c->id,c->name,c->sum,c->price);
	   c=c->next;
    }
 }
 void insert_medicine(Linklist *head)//����ҩƷ��Ϣ 
{
	Linklist *p,*q;
	q=head;
	p=(Linklist*)malloc(sizeof(Linklist));
	printf("������Ҫ����ҩƷ��ǰһ��ҩƷ��ţ�");
	scanf("%s",n);
	while(q->next!=NULL)
	{
		if(strcmp(q->id,n)==0)
		{
			printf("������ҩƷ��Ϣ:\n"); 
			printf("ҩƷ��ţ�");
			scanf("%s",p->id );
			printf("ҩƷ����");
			scanf("%s",p->name );
			printf("ʣ������");
			scanf("%d", &num);
			p->sum= num;
			printf("ҩƷ�۸�");
			scanf("%d", &pc);
			p->price = pc;
			p->next=q->next;
			q->next=p;
			q=p;
			printf("����ҩƷ��Ϣ�ɹ�\n"); 
			break;
		}
		q=q->next;
   }
			
} 
 void sum_medicine(Linklist *head)//ͳ����ҩƷʣ����
{
	int s=0;
	Linklist *p;
	p=head->next;
	if(p==NULL)
	{
		printf("��ǰû���κ�ҩƷ��Ϣ");
	}
	while(p!=NULL)
	{
		s+=p->sum;
		p=p->next;
	}
	printf("��ҩƷʣ����Ϊ��%d\n",s);
}
 void findprice_medicine(Linklist *head)//����ҩƷ�۸� 
{
	Linklist *q,*p;
	q=head;
	printf("��������Ҫ����ҩƷ����Ϣ:\n");
	printf("������ҩƷ��:");
	scanf("%s",&na);
	while(q->next!=NULL)
	{
		if(strcmp(q->next->name,na)==0)
		{
			p=q->next;
			printf("�۸�:%d\n", p->price);
			break;
		}
		q=q->next;
	}
	if (p==NULL) 
	{
		printf("û�е�ǰҩƷ��Ϣ��");
	}
}
 void keep_medicine(Linklist *head)//����Ϣ�������ļ���
{
	Linklist *p;
	p=head->next;
	if(p==NULL) 
	{
		printf("��ǰû���κ�ҩƷ��Ϣ��");
    }
	while(p!=NULL)
	{
		FILE *medicine= fopen("medi.txt", "a");
		fprintf(medicine, "ҩƷ���:%s  ����:%s  ʣ����:%d  �۸�%d\n",
		      p->id,p->name,p->sum,p->price);
		fclose(medicine);
		p=p->next;
	}
	printf("����ɹ�\n");
}
 Linklist* open_medicine()//���ļ� 
{
	Linklist *p,*q,*head;
	head=(Linklist*)malloc(sizeof(Linklist));
	FILE *fp;
	fp=fopen("medi.txt", "r");
	if(fp==NULL)
	{
	    printf("��ȡ�ļ�������������˳�!");
		exit(1);                                   //�޷���ȡ���˳����� 
	}
	if(fp!=NULL)      //��ȡ�ļ������ݵ������� 
	{
		head->next=NULL;
		q=head;
		while(!feof(fp))  //�ļ��������� 
		{
		    p=(Linklist*)malloc(sizeof(Linklist));       //����һ���µĽ�㣬��Ŷ�ȡ����Ϣ
			fscanf(fp,"ҩƷ���:%s  ����:%s  ʣ����:%d  �۸�%d\n",  //������ 
		           p->id,p->name,&p->sum,&p->price); 
		    q->next=p;
		    q=p;
		}
		q->next=NULL;
		fclose(fp);
		printf("\n�ļ���Ϣ����ȷ����\n");
	}
	return head;
}
void print_medicine(Linklist *head){         //���ҩƷ��Ϣ
	Linklist *p;
	int n;
		for(p=head->next;p!=NULL;p=p->next)
		{
	        printf("----------------------------------------\n");
	        printf("���:%s\n",p->id);
	     	printf("����:%s\n",p->name);
		    printf("ʣ����:%d\n",p->sum);
		    printf("�۸�:%d\n\n",p->price);
		    printf("----------------------------------------\n");
		}
}
main()
{
	first();
    int select=1; 
    Linklist *head;
	head=(Linklist*)malloc(sizeof(Linklist));
	head->next =NULL;
	head=open_medicine();
//	system("cls");
    while(select != 0)
    {
        printf("                              ******************************************************\n");
        printf("                              **********************ҩ�����ϵͳ********************\n");
        printf("                              **                                                  **\n");
	    printf("                              **                1. ���ҩƷ��Ϣ                   **\n");
	    printf("                              **                2. ɾ��ҩƷ��Ϣ                   **\n");
	    printf("                              **                3. �޸�ҩƷ��Ϣ                   **\n");
        printf("                              **                4. ����ҩƷ��Ϣ                   **\n");
	    printf("                              **                5. ����ҩƷ��Ϣ                   **\n");
	    printf("                              **                6. ����ҩƷ��Ϣ                   **\n");
	    printf("                              **                7. ����ҩƷ�۸�                   **\n");
	    printf("                              **                8. ͳ����ҩƷ��ʣ����             **\n");
	    printf("                              **                9. ��ҩƷ��Ϣ���浽�ļ���         **\n");
	    printf("                              **                10.���ļ�                       **\n");
	    printf("                              **                11.���ҩƷ��Ϣ                   **\n");
	   	printf("                              **                0. �˳�                           **\n");
	    printf("                              ******************************************************\n");
	    printf("Select:");
	    scanf("%d",&select);
	    system("cls");
	    switch(select)
	    {
	      case 0:
			printf("�����˳���ϵͳ��ллʹ�ã�");
			return 0;
	      case 1:
	        head=add_medicine(head);
	        break;
	      case 2:
	        head=delet_medicine(head);
	        break;
	      case 3:
	        change_medicine(head);
	        break;
	      case 4:
	        find(head);
	        break;
	      case 5:
	      	sort(head); 
	        break;
	      case 6:
	      	insert_medicine(head);
	      	break;
	      case 7:
	      	findprice_medicine(head);
	      	break;
	      case 8:
	      	sum_medicine(head);
	      	break;
	      case 9:
	        keep_medicine(head);
	      	break;
	      case 10:
	      	head=open_medicine();
	      	break;
	      	case 11:
	      	print_medicine(head);
	      	break;
	      default:
	        break;
	    }
	}
	  return 0;
}

