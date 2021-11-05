#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct CSNode
{
    DataType data;
    struct CSNode * FirstChild;
    struct CSNode * NextSibling;
}CSNode,*CSTree;

CSTree CreatCSTree(); //�Զ�Ӧ����������չ����������д�����
int NumOfLeaf(CSTree  rt);

main()
{
    CSTree root;
    root=CreatCSTree();
    printf("%d\n",NumOfLeaf(root));
}

CSTree CreatCSTree()//�Զ�Ӧ����������չ����������д����� 
{
    CSTree root;
    char ch;
    ch=getchar();
    if(ch=='^')
        return NULL;
    root=(CSTree )malloc(sizeof(CSNode));
    root->data=ch;
    root->FirstChild = CreatCSTree();
    root->NextSibling = CreatCSTree();
    return root;
}


/* ����������д�� */
int NumOfLeaf(CSTree  rt)
{
    if(rt == NULL)
        return 0;
  	if(rt->FirstChild == NULL)
    {
        return NumOfLeaf(rt->NextSibling) + 1;
    }else
	{
    	 return NumOfLeaf(rt->FirstChild);
	}
}
