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
            for(y=x;y<=n-x-1;y++) //��д����ĵ�һ�� 
                map[x][y]=k++; 
            for(y=x+1;y<=n-x-1;y++) //��д��������һ�� 
                map[y][n-x-1]=k++;
            for(y=n-x-2;y>=x;y--) //��д��������һ�� 
                map[n-x-1][y]=k++; 
            for(y=n-x-2;y>x;y--) //��д��������һ�� 
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

