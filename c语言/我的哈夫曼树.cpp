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
    
    int len = 1;
    while(top -> next != NULL)
    {
	
    	p = top->next;
    	while(p != NULL)
		{
			len++;
    		printf("%c",p->c->c);
    		p = p->next;
		}
	
		while(len--)
		{
			q = PopQueue(top);
			if(q->LChild != NULL){
				unshiftQueue(top,q->LChild);
			}
			if(q->RChild != NULL){
				unshiftQueue(top,q->RChild);	
			}
		}
	}
   	return 0;
}

