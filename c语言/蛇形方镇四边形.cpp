 #include<stdio.h>
#define N 100
int map[N][N];
int main()
{         
    int x,y,n,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(x=0,k=1;x<=(n-1)/2;x++)
        {
            for(y=x;y<=n-x-1;y++) //填写输出的第一行 
                map[x][y]=k++; 
            for(y=x+1;y<=n-x-1;y++) //填写输出的最后一列 
                map[y][n-x-1]=k++;
            for(y=n-x-2;y>=x;y--) //填写输出的最后一行 
                map[n-x-1][y]=k++; 
            for(y=n-x-2;y>x;y--) //填写输出最左边一列 
                map[y][x]=k++; 
        }
        for(x=0;x<n;x++)
        {
            for(y=0;y<n;y++)
                printf("%-3d ",map[x][y]);
            printf("\n");
        }
    }
    return 0;
}

