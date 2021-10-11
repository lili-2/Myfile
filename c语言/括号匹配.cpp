#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define Stack_Size 50
typedef char ElemType;
typedef struct
{      ElemType  data[Stack_Size]; 
       int  top; 
}SeqStack;

//ջ�Ļ���������������
SeqStack* InitStack();  //ջ��ʼ��
int IsEmpty(SeqStack *S); //ջ�п�
int IsFull(SeqStack *S);  //ջ����
int Push(SeqStack * S, ElemType x);  //  ��ջ
int Pop(SeqStack * S, ElemType *x);  //  ��ջ
int GetTop(SeqStack *S, ElemType *x); // ȡջ��Ԫ��


int IsBracketMatch(char *str);//�ж�str�������Ƿ�ƥ�䡣

main()
{
    char s[20];
    scanf("%s",s);
    if( IsBracketMatch(s))
        printf("Match!\n"); 
    else
        printf("Not Match!\n");
}


SeqStack* InitStack()
{
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}
int IsEmpty(SeqStack *S)     
{
      return(S->top==-1?TRUE:FALSE);
}
int IsFull(SeqStack *S)
{
   return(S->top== Stack_Size-1?TRUE:FALSE);
}
int Push(SeqStack * S, ElemType x)
{
     if(S->top== Stack_Size-1)  
         return(FALSE); 
     S->top++;
     S->data[S->top]=x;
     return(TRUE);
}
int Pop(SeqStack * S, ElemType *x)
{     if(S->top==-1)     
             return(FALSE);
      *x= S->data[S->top];
      S->top--;    
      return(TRUE);
}
int GetTop(SeqStack *S, ElemType *x)
{  
      if(S->top==-1)
            return(FALSE);
      *x = S->data[S->top];
      return(TRUE);
}

int IsBracketMatch(char *str)
{
	int i = 0;
	char x; 
	SeqStack *s = InitStack();
	while(str[i] != '\0')
	{
		if(str[i] == '(')	Push(s,')');
		if(str[i] == '[')   Push(s,']');
		if(str[i] == '{')   Push(s,'}');
		if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{  
			Pop(s,&x);
			if(str[i] != x) return 0;
		}
		i++;
	}
	return 1;
} 
