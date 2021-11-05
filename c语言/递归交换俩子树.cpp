#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
typedef struct Node
{
    DataType data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;

BiTree CreatBiTree(); //����չ����������д�����������
void SwapLR(BiTree bt);
void PrintTree(BiTree bt,int h); //����״��ӡ���������α�P168�㷨6-16

main()
{
    BiTree root;
    root=CreatBiTree();
    SwapLR(root);
    PrintTree(root,0);
}

BiTree CreatBiTree()//����չ����������д�����������
{
    BiTree bt;
    char ch;
    ch=getchar();
    if(ch=='^')
        return NULL;
    bt=(BiTree )malloc(sizeof(BiTNode));
    bt->data=ch;
    bt->Lchild = CreatBiTree();
    bt->Rchild = CreatBiTree();
    return bt;
}

void PrintTree(BiTree bt,int h)
{
    if(bt == NULL)
        return ;
    PrintTree(bt->Rchild,h+1);
    for(int i=0;i<h;i++)
        printf("  ");
    printf("%c\n",bt->data);
    PrintTree(bt->Lchild,h+1);
}

/* ����������д�� */
void SwapLR(BiTree bt)
{
    if(bt != NULL)
    {
    	SwapLR(bt->Lchild);
		SwapLR(bt->Rchild);
		BiTree temp;
		temp = bt->Lchild;
		bt->Lchild = bt->Rchild;
		bt->Rchild = temp; 
	}
}
