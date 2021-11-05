#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int h;
    int l;
    int k;//�����±�
    struct Node *next;
}node;
typedef struct{
    int x;
    int y;
    int d[8];//��ǵ�i�������Ƿ��Ѿ��߹���0��ʾ��1��ʾ�Ѿ��߹�
}pos;   
int dir[2][9] = {{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}}; 
int weight[8][8];
int board[8][8];
void InitWeight();
void SetWeight(int i,int j);
void UnSetWeight(int i,int j);
void push(node *top,int i,int j, int k);
void pop(node *top);
int NextDirection(pos Cur);
int main()
{
    int step = 0,m,n,before = 0,i,count;
    node *top =(node *) malloc(sizeof(node));
    node *p;
    InitWeight();
    printf("���������ʼλ�ã�\n");
    scanf("%d %d",&m,&n);
    SetWeight(m,n);
    pos Cur,Next;
    Cur.x = m;
    Cur.y = n;
    while(step < 63){
        i = before + 1;
        count = NextDirection(Cur);
        if(count == 0){
            Cur.x = top->next->h;
            Cur.y = top->next->l;
            before = top->next->k;
            Cur.d[before] = 1;
            pop(top);
            UnSetWeight(Cur.x,Cur.y);
        }else{
            push(top,Cur.x,Cur.y,count);
            SetWeight(Cur.x,Cur.y);
            board[Cur.x][Cur.y] = step ++;
            Cur.x = Cur.x + dir[0][count +1];
            Cur.y = Cur.y + dir[1][count +1];
        }
    }
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
//            if(board[i][j] == 0){
//                printf("64");
//            }
            printf("%2d ",board[i][j]);
        }
        printf("\n");
    }

}
//���̳�ʼ��
void InitWeight(){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            for(int k = 1;k <= 8;k++){
                if(i + dir[0][k] < 8 && i + dir[0][k] >= 0 && j + dir[1][k] < 8 && j + dir[1][k] >= 0){
                    weight[i][j] ++;
                }
            }
        }
    }
}
//�����ǰ�ڵ���ջ���޸�����
void SetWeight(int i,int j){
    pos Cur,Next;
    Cur.x = i;
    Cur.y = j;
    weight[i][j] = 9;
    for(int p = 1;p <= 8;p++){
        Next.x = Cur.x + dir[0][p];
        Next.y = Cur.y + dir[1][p];
        if(Next.x < 8 && Next.x >= 0 && Next.y < 8 && Next.x >=0 && weight[Next.x][Next.y] < 9){
            weight[Next.x][Next.y] --;      
        }
    }
}
//��ջ�޸�����
void UnSetWeight(int i,int j){
    pos Cur,Next;
    Cur.x = i;
    Cur.y = j;
    weight[i][j] = 0;
    for(int p = 1;p <= 8;p++){
        Next.x = Cur.x + dir[0][p];
        Next.y = Cur.y + dir[1][p];
        if(Next.x < 8 && Next.x >= 0 && Next.y < 8 && Next.x >=0 && weight[Next.x][Next.y] < 9){
            weight[Next.x][Next.y] ++;
            weight[i][j] ++;       
        }
    }
}
void push(node *top,int i,int j, int k){  //��ջ
    node *p = (node *)malloc(sizeof(node));
    p->h = i;
    p->l = j;
    p->k = k;
    p->next = top->next;
    top->next = p;
}
void pop(node *top){  //��ջ���ط����±�
    node *p;
    if(top->next == NULL){
        printf("·������\n");
    }else{
        p = top->next;
        top = p->next;
        free(p);
    }
}
int NextDirection(pos Cur){ //Ѱ�����ŵķ���
    int minDir = 0,min = 9;
    pos Next;
    for(int p = 0;p < 8;p++){
        Next.x = Cur.x + dir[0][p+1];
        Next.y = Cur.y + dir[1][p+1];
        if(Next.x < 8 && Next.x >= 0 && Next.y < 8 && Next.x >=0 && Cur.d[p] == 0 && weight[Next.x][Next.y] < 9){
            minDir = p;
            min = weight[Next.x][Next.y];
        }
    }
    return min;
}

