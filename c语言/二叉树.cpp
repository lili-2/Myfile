// #include <stdio.h>
// #include <stdlib.h>
// struct BTNode
// {
// 	char data;
// 	struct BTNode *pLchild;
// 	struct BTNode *pRchild;
// };
// 
// void  C(struct BTNode * root)
// {
// 	if(root)
// 	{
// 		root->pLchild = (struct BTNode)malloc(sizeof(struct BTNode));
// 		char a;
// 		scanf("%c",&a);
// 		
//	 }
// }
// 
// struct BTNode *CreatBTree();
//void PreTraverseBTRee(struct BTNode *pT);
//void InTraverseBTRee(struct BTNode *pT);
//void PostTraverseBTRee(struct BTNode *pT);
// int main()
// {	
// 	struct BTNode *pT=CreatBTree();//返回根节点的地址 
// 	//PreTraverseBTRee(pT);
// 	//InTraverseBTRee(pT);
// 	PostTraverseBTRee(pT);
// 	return 0;
// }
// struct BTNode *CreatBTree()
// {
// 	struct BTNode *pA=(struct BTNode *)malloc(sizeof(struct BTNode));
// 	struct BTNode *pB=(struct BTNode *)malloc(sizeof(struct BTNode));
// 	struct BTNode *pC=(struct BTNode *)malloc(sizeof(struct BTNode));
// 	struct BTNode *pD=(struct BTNode *)malloc(sizeof(struct BTNode));
// 	struct BTNode *pE=(struct BTNode *)malloc(sizeof(struct BTNode));
// 	
// 	pA->data='A';
// 	pB->data='B';
// 	pC->data='C';
// 	pD->data='D';
// 	pE->data='E';
// 	
// 	pA->pLchild=pB;
// 	pA->pRchild=pC;
// 	pB->pLchild=pB->pRchild=NULL;
// 	pC->pLchild=pD;
// 	pC->pRchild=NULL;
// 	pD->pLchild=NULL;
// 	pD->pRchild=pE;
// 	pE->pLchild=pE->pRchild=NULL;
// 	return pA;
// }
// void PreTraverseBTRee(struct BTNode *pT)//先访问根节点，再访问左子树，最后访问右子树 
// {
// 	if(pT!=NULL)
// 	{
// 		printf("%c\n",pT->data) ;
// 		if(pT->pLchild!=NULL)
// 		{
// 			PreTraverseBTRee(pT->pLchild);
//		 }
//		 if(pT->pRchild!=NULL)
//		 {
//		 	PreTraverseBTRee(pT->pRchild);
//		 }
//	}
//}
// 	
// 	
// 	
// 	void InTraverseBTRee(struct BTNode *pT)//先访问左子树，再放问根节点，最后访问右子树 
//   {
//	 	if(pT!=NULL)
//	 	{
//	 		if(pT->pLchild!=NULL)
//	 		{
//	 			PreTraverseBTRee(pT->pLchild);
//			 }
//			 printf("%c\n",pT->data) ;
//			 if(pT->pRchild!=NULL)
//			 {
//			 	PreTraverseBTRee(pT->pRchild);
//			 }
//		}
//   } 
//void PostTraverseBTRee(struct BTNode *pT)//先访问左子树，再放问右子树，最后访问根节点 
//{
// 	if(pT!=NULL)
// 	{
// 		if(pT->pLchild!=NULL)
// 		{
// 			PreTraverseBTRee(pT->pLchild);
//		 }
//		 if(pT->pRchild!=NULL)
//		 {
//		 	PreTraverseBTRee(pT->pRchild);
//		 }
//		 printf("%c\n",pT->data) ;
//	}
//}
//// 	先访问根节点
////	在访问左子树
////	在访问右子树

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node * L;
	struct Node * R;
}Node;

void C(Node *root) {
	 	root->L = (Node *)malloc(sizeof(Node));
	 	root->L->L = 0x0;
	 	root->L->R = 0x0;
	 	root->R = (Node *)malloc(sizeof(Node));
	 	root->R->L = 0x0;
	 	root->R->R = 0x0;
	 	char data;
		scanf("%c",&data);
		getchar();
		printf("!!!!!!!!!!!!!\n");
		if(data == 's'){
			return ;
		}
		root->data = data;
	 	C(root->L);
	 	C(root->R);
	 	//printf("%c ",data);
	 
}

void p(Node * root) {
	if(root) {
		printf("%c ",root->data);
		p(root->L);
		p(root->R);
	}
} 

int main()
{
	
	Node *A = (Node *)malloc(sizeof(Node));
	C(A);
	p(A);
	return 0;
}

