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
int main()
{
	Node * root;
	root = creatTree();
    Stacknode * top;
	top = (Stacknode *)malloc(sizeof(Stacknode));
	top->next = NULL;
	Node * p = NULL;
	while(root != NULL || (top->next != NULL))
    {
    	while(root != NULL)
    	{
			PushStack(top,root);
            root = root->LChild;
		}
		root = PopStack(top);
        if(root->RChild == NULL || p == root->RChild)
        {
        	printf("%c",root->c);
        	p = root;
        	root = NULL;
        }else{
			PushStack(top,root);
        	root = root->RChild;	
		}
    }
   	return 0;
}
