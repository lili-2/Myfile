#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node{
    char data;
    struct node * LChild;
    struct node * RChild;
}Node;
Node * creatTree(){
    char c;
    c = getchar();
    if(c == '#')
    {
        return NULL;
	}
	Node * a = (Node *)malloc(sizeof(Node));
    a->data = c;
    a->LChild = creatTree();
    a->RChild = creatTree();
    return a;
}
void preOrder(Node * root)
{
	if(root != NULL)
	{
		printf("%c",root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
void inOrder(Node * root)
{
	if(root != NULL)
	{
		preOrder(root->LChild);
		printf("%c",root->data);
		preOrder(root->RChild);
	}
}
void postOrder(Node * root)
{
	if(root != NULL)
	{
		preOrder(root->LChild);
		preOrder(root->RChild);
		printf("%c",root->data);
	}
}
int main()
{
	Node * root = creatTree();
	preOrder(root);
	return 0; 
}
