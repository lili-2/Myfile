 #include <stdio.h>
 #include <stdlib.h> 
 typedef struct TNode
 {
 	char str;
 	struct TNode *LChild;
 	struct TNode *RChild;
 }TreeNode;
 typedef struct Node   //队列节点，队列中储存的是指向节点的指针 
 {
 	TreeNode *r;
 	struct Node *next;
 }node;
 //队列的初始化
 node* start()
 {
 	node *head;
 	head = (node *)malloc(sizeof(node));
 	head->r = NULL;
 	head->next = NULL;
 	return head;
 } 
 //入队 
 node *PushQueue(node *head, TreeNode *t)
 {
 	node *p,*tail;
 	p = (node *)malloc(sizeof(node));
 	tail = head;
 	p->r = t;
 	p->next = NULL;
 	tail->next = p;
 	tail = p;
	return head;
 }
 //出队
 void PopQueue(node *head)
 {
 	TreeNode *t;
 	if(head->next == NULL)
 	{
 		printf("出队失败\n");
	}
	else
	{
		head = head->next;
	}
	return;
 } 
 int isEmpty(node *head)
 {
 	if(head->next == NULL)
 	{
 		return 1;
	}
	else
	{
		return 0;
	}
 } 
 //树的创建
 TreeNode* create()
 {
 	char c;
 	TreeNode *root;
 	c = getchar();
 	printf("%c\n",c); 
 	if(c == '#')
 	{
 		return NULL;	
	}
	else
	{
		root = (TreeNode *)malloc(sizeof(TreeNode));
		root->str = c;
		printf("树的创建：%c\n",root->str);
		root->LChild = create();
		root->RChild = create();
	}
	return root;
 }
TreeNode *topQueue(node *head)
{
	TreeNode *h;
	if(head->next == NULL) return NULL;
	else
	{
		h = head->r;
	}	
	printf("栈顶元素：%d %c\n",h,h->str);
	return h;
}
 // 层序  (用队列实现)
  void levelOrder(TreeNode *root)
  {
  	printf("!!!!!!!!!!!!!!!!!!!!\n");
  	printf("%d %c",root,root->str);
  	node *head;
  	TreeNode *r1;
  	head = start();
  	if(root == NULL)
  	{
  		printf("11111111111111\n");
  		return;
	}
	else
	{
		printf("22222222222222\n");
		PushQueue(head,root);  //入根 
		while(!isEmpty(head))
		{
			printf("3333333333333\n");
			r1 = topQueue(head);
			PopQueue(head);	
			printf("%c",r1->str);
			if(r1->LChild != NULL) 
			head = PushQueue(head,r1->LChild);
			if(r1->RChild != NULL)
			head = PushQueue(head,r1->RChild);
		}
	}
  }
  //树的遍历 先序 
 void PreOrder(TreeNode *root)
 {
 	if(root == NULL)
 	{
 		return;
	}
	else
	{
		printf("%c",root->str);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
 }
 int main()
 {
 	TreeNode *root;
	printf("输入你要创建的树\n");
	root = create();
	printf("先序遍历：\n");
	PreOrder(root);
	printf("\n层序遍历：\n");
	levelOrder(root);
	return 0;
 }

