#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define STACK_INIT_SIZE 20   //ջ��ԭʼ�ռ�
#define STACKINCREMENT  10   //ջ����չ�ռ�
typedef struct Node{
    char c;
    struct  Node *right;
    struct Node *left;
}Sqstack;
//��ʼ��
Sqstack * InitStack(Sqstack *s)
{
	s->right = NULL;
    s->left = NULL;
}
//��ջ
void Push(Sqstack *s,char e)
{
	Sqstack *p=(Sqstack *)malloc(sizeof(Sqstack));
    p->c = e;
    if(s->right==NULL)
    {
        p->right=NULL;
        s->right=p;
        p->left=s;
    }
    else
	{
        p->right=s->right;
        p->left=s;
        p->right->left=p;
        s->right=p;
    }
}

char Pop(Sqstack *s)
{ 
	char e;
	if(s->right==NULL)
       printf("ջΪ��\n");
	else
	{
		Sqstack *p=s->right;
		if(p->right == NULL)
		{
			s->right = NULL;
		}else{
			s->right=p->right;
			p->right->left=s;
		}
		e = p->c;
		free(p);
		return e;
	} 
} 

char Change(Sqstack *s,char str[])
{
	char e;
	InitStack(s);
    int i = 0, j=0,k=0;
    char str1[100];
	while(str[i]!='\0')
	{
		while(isdigit(str[i]))        
		{
            str1[k++] = str[i];
			printf("%c",str[i++]);
			if(!isdigit(str[i]))
				printf(" ");
		}
		//�Ӽ������ 
		if(str[i] == '+' ||str[i] == '-')
		{
			if(s->right==NULL)       //ջ��Ԫ��Ϊ�վ�ִ�к������ 
			{
				Push(s,str[i]);
			}
			else{                       //ջ��Ԫ�ز�Ϊ�գ��Ƚ���ջ�����ȼ��ߵ�Ԫ�ء���ջ����ӡ�������������������ջ������ӡ������ѹջ 
				do{
					e = Pop(s);
					if(e=='('){
						Push(s,e);
					}
					else{
						printf("%c ",e);
                        str1[k++] = e;
					}
				}while(s->right!=NULL && e != '(' );
				Push(s,str[i]);      //Ȼ�󽫵�i���������ջ 
			}
		}
		//�������� 
		else if(str[i]==')')
		{
			e=Pop(s);
			while(e!='(')
			{
				printf("%c ",e);
                str1[k++] = e;
				e = Pop(s);
				
			}
		}
		//ֱ��ѹջ�ĳ˳��Լ������� 
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			Push(s,str[i]);
		}
		//��ջ 
		else if(str[i]=='\0')
        {
            break;
        }
        //��ʽ���� 
        else
        {
            printf("\n�����ʽ����\n");
            break;
        }
        i++;
	}
	while(s->right!=NULL)
    {
        e=Pop(s);
        if(e!='('||e!=')') 
        printf("%c ",e);
        str1[k++] = e;
        str1[j]=e;
        j++;       
    }
	for(int p = 0;p < 5;p++)
    printf("%c\n",str1[p]);
    return str1;
}

int main()
{
    char str[100];
    char str1[100];
    Sqstack *s = malloc(sizeof(Sqstack));
    printf("��������׺ʽ������ո���Ϊ������\n");
    gets(str);
    Sqstack *s1 = malloc(sizeof(Sqstack));
    str1= Change(s,str);
    print("%s",str1);
    return 0;
}
