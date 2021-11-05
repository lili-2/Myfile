#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 30
#define M 2 * N - 1
#define CrCode char **

typedef struct
{
    int Weight;
    int Parent, Lchild, Rchild;

} HTNode, HuffmanTree[M + 1];

void select(HuffmanTree ht, int n, int *s1, int *s2)
{
	int i; 
    if(ht[1].Weight > ht[2].Weight){
        *s1 = 2;
        *s2 = 1;
    }else{
        *s1 = 1;
        *s2 = 2;
    }
    for(i = 3;i < n;i++){
       
        if(ht[i].Weight < ht[*s1].Weight){
            *s2 = *s1;
            *s1 = i;
        }
    }
}

void CrtHuffman(HuffmanTree ht, int w[], int n)
{
    int m = 2 * n - 1;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        ht[i].Weight = w[i];
        ht[i].Parent = 0;
        ht[i].Lchild = 0;
        ht[i].Rchild = 0;
    }
    int k;
    for(k = 1;k <= n;k++){
    	printf("%d %d %d %d\n",ht[k].Weight,ht[k].Parent,ht[k].Lchild,ht[k].Rchild);
	}
    int s1, s2;
    for (i = n + 1; i <= m; i++)
    {
        select(ht, i - 1, &s1, &s2);
        printf("s1 = %d s2 = %d\n",s1,s2);
        ht[i].Weight = ht[s1].Weight + ht[s2].Weight;
        ht[i].Lchild = s1;
        ht[i].Rchild = s2;
        ht[s1].Parent = i;
        ht[s2].Parent = i;
    }
    for(k = 1;k <= n;k++){
    	printf("%d %d %d %d\n",ht[k].Weight,ht[k].Parent,ht[k].Lchild,ht[k].Rchild);
	}
}

//void CrtHuffmanCode(HuffmanTree ht, CrCode hc[], int n)
//{
//    char *cd;
//    int start;
//    int i, c, p;
//    cd = (char *)malloc(n * sizeof(char));
//    cd[n - 1] = '\0';
//    for(i = 1;i <= n;i++){
//        start = n-1; c = i; p = ht[i].Parent;
//        while(p != 0){
//            --start;
//            if(ht[p].Lchild == c) cd[start] = '0';
//            else cd[start] = '1';
//            c = p;
//            p = ht[p].Parent;
//        }
//        hc[i] = (char *)malloc((n-start) * sizeof(char));
//        hc[i] = &cd[start];
//    }
//    free(cd);
//}
int main()
{
    int w[7] = {0,4,10,8,6,5,1};
    HuffmanTree ht;
    int n = 6,m = 2*n - 1;
    CrtHuffman(ht, w, n);
    int i = 0;
//    char *hc[10];
//    CrtHuffmanCode(ht,hc, n);
    return 0;
}
