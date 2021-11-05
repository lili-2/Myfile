 #include <stdio.h>
 #include <stdlib.h> 
 typedef struct TNode
 {
 	char str;
 	struct TNode *LChild;
 	struct TNode *RChild;
 }TreeNode;
 typedef struct Node   //���нڵ㣬�����д������ָ��ڵ��ָ�� 
 {
 	TreeNode *r;
 	struct Node *next;
 }node;
 //���еĳ�ʼ��
 node* start()
 {
 	node *head;
 	head = (node *)malloc(sizeof(node));
 	head->r = NULL;
 	head->next = NULL;
 	return head;
 } 
 //��� 
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
 //����
 void PopQueue(node *head)
 {
 	TreeNode *t;
 	if(head->next == NULL)
 	{
 		printf("����ʧ��\n");
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
 //���Ĵ���
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
		printf("���Ĵ�����%c\n",root->str);
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
	printf("ջ��Ԫ�أ�%d %c\n",h,h->str);
	return h;
}
 // ����  (�ö���ʵ��)
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
		PushQueue(head,root);  //��� 
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
  //���ı��� ���� 
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
	printf("������Ҫ��������\n");
	root = create();
	printf("���������\n");
	PreOrder(root);
	printf("\n���������\n");
	levelOrder(root);
	return 0;
 }

