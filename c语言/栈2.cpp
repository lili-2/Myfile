#include <stdio.h>
#include <stdlib.h>
//����ջ�Ľڵ� 
typedef struct node{
	int data;
	struct node * next;
}NODE, * pNode;
//struct Node = NODE, struct Node * = pNode ; 

//����ָ��ջͷβ��ָ�� 
typedef struct stack{
	pNode pTop;
	pNode pBottom;
}STACK,*pStack;
///ruct stack = STACK, struct stack * = pStack

//�ջ�Ŀ�� 
void init(pStack PS)
{
	PS->pTop = (pNode)malloc(sizeof(NODE));
	if(PS->pTop==NULL){
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else{
		PS->pBottom = PS->pTop;
		//��ͷ�ڵ㣨û�д�����ݣ���ָ������� 
		PS->pBottom->next = NULL;
	}
}

//ѹջ 
void push(pStack PS,int x)
{
	pNode pNew = (pNode)malloc(sizeof(NODE));
	pNew->data = x;
	//ѹջ 
	pNew->next = PS->pTop;
	//�ƶ� 
	PS->pTop = pNew;
	return;
}

//�ж�ջ�Ƿ�Ϊ��
bool is_empty(pStack PS)
{
	if(PS->pTop==PS->pBottom)
		return true;
	else
		return false;
} 

//��ջ 
bool pop(pStack PS,int *val)
{
	pNode p = PS->pTop;
	p->data = * val;
	p = p->next;
	return true;
}

//��� 
void traverse(pStack PS)
{
	pNode p = PS->pTop;
	while(p != PS->pBottom){
		printf("%d ",p->data);
		p = p->next;
	}
	return ;
}

int main()
{
	STACK S;
	init(&S);
	push(&S,10);
	push(&S,2);
	push(&S,7);
	traverse(&S);
	int val = pop(&S,&val);
	traverse(&S);
	printf("\n��ջԪ����%d\n",val);
	return 0;
}

