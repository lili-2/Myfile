#include<stdio.h>
#include<malloc.h>
#include<string.h> 
typedef struct node
{
    char c;
    struct node * LChild;
    struct node * RChild;
}Node;
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
int fun(Node * root)
{
	if(root == NULL)
		return 0;
	else
		return (fun(root->LChild) > fun(root->RChild)) ? fun(root->LChild) + 1 : fun(root->RChild) + 1; 
}
int main()
{
	Node * root;
	root = creatTree();
    int high = fun(root);
    printf("%d",high);
   	return 0;
}
