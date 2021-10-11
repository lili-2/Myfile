#include <stdio.h>
#include <stdlib.h>
//定义栈的节点 
typedef struct node{
	int data;
	struct node * next;
}NODE, * pNode;
//struct Node = NODE, struct Node * = pNode ; 

//定义指向栈头尾的指针 
typedef struct stack{
	pNode pTop;
	pNode pBottom;
}STACK,*pStack;
///ruct stack = STACK, struct stack * = pStack

//搭建栈的框架 
void init(pStack PS)
{
	PS->pTop = (pNode)malloc(sizeof(NODE));
	if(PS->pTop==NULL){
		printf("内存分配失败！\n");
		exit(-1);
	}
	else{
		PS->pBottom = PS->pTop;
		//将头节点（没有存放数据）的指针域清空 
		PS->pBottom->next = NULL;
	}
}

//压栈 
void push(pStack PS,int x)
{
	pNode pNew = (pNode)malloc(sizeof(NODE));
	pNew->data = x;
	//压栈 
	pNew->next = PS->pTop;
	//移动 
	PS->pTop = pNew;
	return;
}

//判断栈是否为空
bool is_empty(pStack PS)
{
	if(PS->pTop==PS->pBottom)
		return true;
	else
		return false;
} 

//出栈 
bool pop(pStack PS,int *val)
{
	pNode p = PS->pTop;
	p->data = * val;
	p = p->next;
	return true;
}

//输出 
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
	printf("\n出栈元素是%d\n",val);
	return 0;
}

