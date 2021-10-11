 #include<stdio.h>
#include<string.h>
#define N 25
int map[N][N];
 
int main() {
    int n,k,x,y,i;
    while(scanf("%d",&n)!=EOF) {
 
        
        for(i=0,k=1;i<(n-1)/2;i++)
		{
			for(x=i,y=i;y<n-2*i-1;y++)
                map[x][y]=k++;
            for(;y>i;x++,y--)
                map[x][y]=k++;
            for(;x>i;x--)
                map[x][y]=k++;
        }
        for(x=0;x<n;x++){ 
            for(y=0;y<=n-x-1;y++)
                printf("%-4d",map[x][y]);
            printf("\n");
        }
        
    }
    return 0;
}

