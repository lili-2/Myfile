/*
    题目 有N件物品和一个容量是V的背包
	第i件物品的体积是vi，价值是wi
	求解将哪些物品装入背包 可使这些物品的总体积不超过背包容量，且总价值最大
	 
    f[i][j] 表示只看前i个物品，总体积是j的情况下 总价值最大是多少
    
	result = max {f[n][0~V]}
	
	f[i][j] =  ;
	
	1.不选第i个物品 f[i][j] = f[i-1][j];
	2.选第i个物品   f[i][j] = f[i-1][j-v[i]];
	
	f[i][j] = max{1,2}
	
	初始状态 f[0][0] = 0 

*/ 
/*
#include<stdio.h>
int main()
{
	int n,m,i,j;
	
	scanf("%d %d",&n,&m);
	int f[N][N];
	int v[N],w[N];
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			f[i][j] = max(f[j],f[j-v[i]]+w[i])
	 
		}
	}
	
	int res = 0;
	for(i=0;i<=m;i++)
	{
		res = max(res,f[n][i]);
	}
	return 0;
}
*/
#include<stdio.h> 
int max(a,b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
    int i,n=5,v=10,j,a,b;
    int c[6] = {0,1,3,3,2,4};
    int w[6] = {0,2,1,3,4,2};
    int f[6][6];
    /*
    for (i = 1; i <= n; i++)
        scanf("%d",c[i]);//价值
        
    for (i = 1; i <= n; i++)
        scanf("%d",w[i]);//体积
    */    
    for (i = 0; i <= n; i++)
        f[i][0] = 0;
        
    for (i = 1; i <= n; i++)
    {
	   // for (j = 1; j <= v; j++)
        //{
		  //  if (j-f[i-1][j] >= w[i])//背包容量够大
		if (v-f[i-1][j-1] >= w[i])//背包容量够大
            {
            	a = f[i - 1][j - w[i]] + c[i];//装第i个物品 
            	b = f[i - 1][j];               //不装第i个物品 
			    f[i][j] = max(a,b);
            } 
			else//背包容量不足
                f[i][j] = f[i - 1][j];
        //}
    }
    printf("%d %d %d",f[6][6],f[5][6],f[5][5]);
    //cout << f[n][v] << endl;
    return 0;
}
