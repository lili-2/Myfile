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
    printf("请输入9个要进入队列的元素\n");
    for(int i = 0;i < 9;++i){
        scanf("%d",&data);
        arr[i] = data;
        tail = i;
        printf("%d  \n",tail);
    }
    while(flag){
        printf("请输入对应的数对队列进行操作：\n");
        printf("1.判断队列是否为空\n");
        printf("2.判断队列是否已满\n");
        printf("3.入队\n");
        printf("4.出队\n");
        printf("5.获取队首元素\n");
        printf("6.遍历队列\n");
        printf("7.操作结束\n");
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
//判断队列是否为空
int isEmpty(){
    if(head == tail){
        printf("队列为空\n");
        return 1;
    }
    else{
        printf("队列不为空\n");
        return 0;
    }
}
// 判断队列是否已满
int isFull(){
    if((tail + 1) % maxSize == head%maxSize){
        printf("队列已满\n");
        return 1;
    }else{
        printf("队列还有空间\n");
        return 0;
    }
}
// 入队
void add_queue(){
    int n;
    printf("是输入要入队的数：\n");
    scanf("%d",&n);
    if((tail + 1) % maxSize == head){
        printf("队列已满，不能再添加元素\n");
    }
    else{
    	tail = (tail+1) % maxSize;
    	arr[tail] = n;
    }
    for(int i = head;i < (tail+1)%maxSize;i++){
    	printf("%d ",arr[i]);
	} 
}
// 出队
void get_queue(){
    if(isEmpty() == 1){
        printf("队列中没有元素出队");
    }else{
        printf("%d\n",arr[head]);
        head = (head + 1) % maxSize;
    }
}
// 取队首元素
void get_firstvalue(){
   if(isEmpty() == 1){
        printf("队列中没有元素出队");
    }else{
        printf("队首元素为：%d\n",arr[head]);
        head = (head + 1) % maxSize;
    }
    printf("\n%d %d\n",head,tail);
}
// 打印队列元素
void out_put(){
     if(tail != head){
        while(tail != head){
            printf("%d\n",arr[head]);
            head = (head + 1)%maxSize;
            printf("head = %d tail = %d",head,tail);
        }
    }else{
        printf("队列中没有元素\n");
    }
}

