#include<stdio.h>
#include<malloc.h>
#include<string.h> 
typedef struct node
{
    char c;
    struct node * LChild;
    struct node * RChild;
}Node;
typedef struct Stacknode
{
    Node * c;
    struct Stacknode * next;
}Stacknode;
int PushStack(Stacknode * top,Node * c)
{
    Stacknode * p;
    if((p = (Stacknode *)malloc(sizeof(Stacknode))) == NULL) 
    {return 0;}
    p->c = c;
    p->next = top->next;
    top->next = p;
    return 1;
}
Node * PopStack(Stacknode * top)
{
    Stacknode * p;
    Node * x;
    if(top->next == NULL)
    {
        printf("Õ»¿Õ");
    }
    p = top->next;
    top->next = p->next;
    x = p->c;
    free(p);
    return x;
}
Node * creatTree()
{
    char c;
    Node * root;
    c = getchar();
    if(c == '#')
    {
        return NULL;
    }
    root = (Node *)malloc(sizeof(Node));
    root->c = c;
    root->LChild = creatTree();
    root->RChild = creatTree();
    return root;
}
void Pre(Node * root,Stacknode * top)
{
	while(root != NULL || (top->next != NULL))
    {
        while(root != NULL)
        {
            PushStack(top,root);
            printf("%c",root->c);
            root = root->LChild;
        }
        root = PopStack(top);
        root = root->RChild;
   }
}
void Mid(Node * root,Stacknode * top)
{
	while(root != NULL || (top->next != NULL))
    {
        while(root != NULL)
        {
            PushStack(top,root);
            root = root->LChild;
        }
        root = PopStack(top);
        printf("%c",root->c);
        root = root->RChild;
   }
} 
int main()
{
	Node * root;
	root = creatTree();
    Stacknode * top;
	top = (Stacknode *)malloc(sizeof(Stacknode));
	top->next = NULL;
    Pre(root,top);
   	printf("\n");
   	Mid(root,top);
   	return 0;
}
