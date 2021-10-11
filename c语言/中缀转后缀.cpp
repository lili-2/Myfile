#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define STACK_INIT_SIZE 20   //栈的原始空间
#define STACKINCREMENT  10   //栈的扩展空间
typedef struct Node{
    char c;
    struct  Node *right;
    struct Node *left;
}Sqstack;
//初始化
Sqstack * InitStack(Sqstack *s)
{
	s->right = NULL;
    s->left = NULL;
}
//入栈
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
       printf("栈为空\n");
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
		//加减运算符 
		if(str[i] == '+' ||str[i] == '-')
		{
			if(s->right==NULL)       //栈顶元素为空就执行后面语句 
			{
				Push(s,str[i]);
			}
			else{                       //栈顶元素不为空，先将“栈顶优先级高的元素”出栈、打印出来，遇到左括号则出栈，不打印，重新压栈 
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
				Push(s,str[i]);      //然后将第i个运算符进栈 
			}
		}
		//遇右括号 
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
		//直接压栈的乘除以及左括号 
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			Push(s,str[i]);
		}
		//退栈 
		else if(str[i]=='\0')
        {
            break;
        }
        //格式错误 
        else
        {
            printf("\n输入格式错误！\n");
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
    printf("请输入中缀式，输入空格视为结束：\n");
    gets(str);
    Sqstack *s1 = malloc(sizeof(Sqstack));
    str1= Change(s,str);
    print("%s",str1);
    return 0;
}
