#include<stdio.h>
#include<malloc.h>
#include<string.h> 
typedef struct node
{
    char c;
    struct node * LChild;
    struct node * RChild;
}Node;

typedef struct Queuenode
{
    Node * c;
    struct Queuenode * next;
}Queuenode;

int unshiftQueue(Queuenode * top,Node * c)
{
    Queuenode * p;
    if((p = (Queuenode *)malloc(sizeof(Queuenode))) == NULL) 
    {return 0;}
    p->c = c;
    p->next = NULL;
   	while(top->next != NULL)
   	{
   		top = top->next;	
	}

	top->next = p;
    return 1;
}
Node * PopQueue(Queuenode * top)
{
    Queuenode * p;
    Node * x;
    if(top->next != NULL)
    {
	    p = top->next;
	    top->next = p->next;
	    x = p->c;
	    free(p);
	    return x;	
	}
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
	
    Queuenode * top;
	top = (Queuenode *)malloc(sizeof(Queuenode));
	top->next = NULL;
	
    unshiftQueue(top,root);
    
    Queuenode * p;
    Node * q;
    
    int len = 0;
    while(top -> next != NULL)
    {
		q = PopQueue(top);
		printf("%c",q->c);
		if(q->LChild){
			unshiftQueue(top,q->LChild);
		}
		if(q->RChild){
			unshiftQueue(top,q->RChild);
		}
	}
   	return 0;
}
