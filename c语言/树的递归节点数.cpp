#include<stdio.h>
#include<malloc.h>
#include<string.h> 
typedef struct node
{
    char c;
    struct node * LChild;
    struct node * RChild;
}Node;
int a = 0,b = 0,c = 0;
char arr[15];
int i = 0;
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
void fun(Node * root)
{
	if(root == NULL)
		return ;
	if(root->LChild != NULL && root->RChild != NULL){
		c++;
	}
	else if(root->LChild == NULL && root->RChild == NULL){
		a++;
		arr[i] = root->c;
		i++;
	}
	else{
		b++;
	}
	fun(root->LChild);
	fun(root->RChild);
}
int main()
{
	Node * root;
	root = creatTree();
    fun(root);
    printf("%d %d %d\n",a,b,c);
    int j = 0;
	for(j;j < i;j++)
	{
		printf("%c",arr[j]);
	}
   	return 0;
}
