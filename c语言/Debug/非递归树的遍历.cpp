#include<stdio.h>
#include<malloc.h>
#include<string.h> 
typedef struct Stacknode
{
    char c;
    struct Stacknode * next;
}Stacknode;
int PushStack(Stacknode * top,char c)
{
    Stacknode * p;
    if((p = (Stacknode *)malloc(sizeof(Stacknode))) == NULL) 
    {
        return false;
    }
    p->c = c;
    p->next = top->next;
    top->next = p;
    return true;
}
char PopStack(Stacknode * top)
{
    Stacknode * p;
    char x;
    if(top->next == NULL)
    {
        printf("Õ»¿Õ");
    }
    p = top->next;
    top->next = p->next;
    x = p->c;
    printf("%c",x);
    free(p);
    return x;
}
int main()
{
	Stacknode * top;
	top = (Stacknode *)malloc(sizeof(Stacknode));
	top->next = NULL;
    PushStack(top,'A');
    PushStack(top,'B');
    PushStack(top,'C');
    PopStack(top);
    PopStack(top);
    PopStack(top);
	return 0;
}
