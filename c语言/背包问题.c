/*
    ��Ŀ ��N����Ʒ��һ��������V�ı���
	��i����Ʒ�������vi����ֵ��wi
	��⽫��Щ��Ʒװ�뱳�� ��ʹ��Щ��Ʒ��������������������������ܼ�ֵ���
	 
    f[i][j] ��ʾֻ��ǰi����Ʒ���������j������� �ܼ�ֵ����Ƕ���
    
	result = max {f[n][0~V]}
	
	f[i][j] =  ;
	
	1.��ѡ��i����Ʒ f[i][j] = f[i-1][j];
	2.ѡ��i����Ʒ   f[i][j] = f[i-1][j-v[i]];
	
	f[i][j] = max{1,2}
	
	��ʼ״̬ f[0][0] = 0 

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
        scanf("%d",c[i]);//��ֵ
        
    for (i = 1; i <= n; i++)
        scanf("%d",w[i]);//���
    */    
    for (i = 0; i <= n; i++)
        f[i][0] = 0;
        
    for (i = 1; i <= n; i++)
    {
	   // for (j = 1; j <= v; j++)
        //{
		  //  if (j-f[i-1][j] >= w[i])//������������
		if (v-f[i-1][j-1] >= w[i])//������������
            {
            	a = f[i - 1][j - w[i]] + c[i];//װ��i����Ʒ 
            	b = f[i - 1][j];               //��װ��i����Ʒ 
			    f[i][j] = max(a,b);
            } 
			else//������������
                f[i][j] = f[i - 1][j];
        //}
    }
    printf("%d %d %d",f[6][6],f[5][6],f[5][5]);
    //cout << f[n][v] << endl;
    return 0;
}
