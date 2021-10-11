#include <stdio.h>
# define maxSize  10
int arr[maxSize];
int head = 0,tail = 0;
int isEmpty();
int isFull();
void add_queue();
void get_queue();
void get_firstvalue();
void out_put();
int main(){
    int data,n;
    int flag = 1;
    printf("������9��Ҫ������е�Ԫ��\n");
    for(int i = 0;i < 9;++i){
        scanf("%d",&data);
        arr[i] = data;
        tail = i;
        printf("%d  \n",tail);
    }
    while(flag){
        printf("�������Ӧ�����Զ��н��в�����\n");
        printf("1.�ж϶����Ƿ�Ϊ��\n");
        printf("2.�ж϶����Ƿ�����\n");
        printf("3.���\n");
        printf("4.����\n");
        printf("5.��ȡ����Ԫ��\n");
        printf("6.��������\n");
        printf("7.��������\n");
        scanf("%d",&n);
        switch(n){
            case 1 :
                isEmpty();
                break;
            case 2 :
                isFull();
                break;
            case 3 :
                add_queue();
                break;
            case 4 :
                get_queue();
                break;
            case 5 :
                get_firstvalue();
                break;
            case 6 :
                out_put();
                break;
            case 7 :
                flag = 0;
                break;
        }
    }
}
//�ж϶����Ƿ�Ϊ��
int isEmpty(){
    if(head == tail){
        printf("����Ϊ��\n");
        return 1;
    }
    else{
        printf("���в�Ϊ��\n");
        return 0;
    }
}
// �ж϶����Ƿ�����
int isFull(){
    if((tail + 1) % maxSize == head%maxSize){
        printf("��������\n");
        return 1;
    }else{
        printf("���л��пռ�\n");
        return 0;
    }
}
// ���
void add_queue(){
    int n;
    printf("������Ҫ��ӵ�����\n");
    scanf("%d",&n);
    if((tail + 1) % maxSize == head){
        printf("�������������������Ԫ��\n");
    }
    else{
    	tail = (tail+1) % maxSize;
    	arr[tail] = n;
    }
    for(int i = head;i < (tail+1)%maxSize;i++){
    	printf("%d ",arr[i]);
	} 
}
// ����
void get_queue(){
    if(isEmpty() == 1){
        printf("������û��Ԫ�س���");
    }else{
        printf("%d\n",arr[head]);
        head = (head + 1) % maxSize;
    }
}
// ȡ����Ԫ��
void get_firstvalue(){
   if(isEmpty() == 1){
        printf("������û��Ԫ�س���");
    }else{
        printf("����Ԫ��Ϊ��%d\n",arr[head]);
        head = (head + 1) % maxSize;
    }
    printf("\n%d %d\n",head,tail);
}
// ��ӡ����Ԫ��
void out_put(){
     if(tail != head){
        while(tail != head){
            printf("%d\n",arr[head]);
            head = (head + 1)%maxSize;
            printf("head = %d tail = %d",head,tail);
        }
    }else{
        printf("������û��Ԫ��\n");
    }
}

