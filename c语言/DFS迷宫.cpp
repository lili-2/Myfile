#include<stdio.h>
using namespace std;
int p,q,min=999999; 
int a[100][100];//1��ʾ�յ� 2��ʾ�ϰ��� 
int v[100][100];//0��ʾδ���� 1��ʾ���� 
void dfs(int x,int y,int step)

{
	if(x==p && y==q)
	{
		if(step<min)
			min = step;
		return;
	}
	//˳ʱ����̽ 
	//��
	 if(a[x][y+1] == 1 && v[x][y+1] == 0)
	 {
	 	v[x][y+1] = 1;
	 	dfs(x,y+1,step+1);
	 	v[x][y+1] = 0;
	 }
	 //�� 
	 if(a[x+1][y] == 1 && v[x+1][y] == 0)
	 {
	 	v[x+1][y] = 1;
	 	dfs(x+1,y,step+1);
	 	v[x+1][y] = 0;
	 }
	 //�� 
	 if(a[x][y-1] == 1 && v[x][y-1] == 0)
	 {
	 	v[x][y-1] = 1;
	 	dfs(x,y-1,step+1);
	 	v[x][y-1] = 0;
	 }
	 //�� 
	if(a[x-1][y] == 1 && v[x-1][y] == 0)
	 {
	 	v[x-1][y] = 1;
	 	dfs(x-1,y,step+1);
	 	v[x-1][y] = 0;
	 }
	 return;
}
int main()
{
	scanf("%d %d",&m,&n);
	for(int i = 1;i <=m;i++)
	{
		
	}
}
