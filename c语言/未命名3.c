#include<stdio.h>
int main()
{
	int m,i,cishu=0,key=0;//次数 记录每5次休息一次 
	float hp=100,t,n,s,r,k,time=0,rage=0;
	scanf("%d",&m);
	
	for(i=1;i<=m;i++)
	{
		scanf("%d",&t);
		scanf("%d",&n);
		scanf("%d",&s);
		scanf("%d",&r);
		scanf("%d",&k);
	}
	for(i=1;i<=m;i++)
	{
		while(hp>0)
		{
			cishu++;//打鞭子时各项的变化		
			time = time+t;
			hp=hp-n;
			if(hp<=0) continue;//跳出本轮循环 
			rage=rage+s+time*t;//受伤加上时间变化而产生的怒气值 
			if(rage>60&&cishu%5!=0)
			{
				key=1;//key记录 年轻人赢了 
				continue;
			}		
			if(cishu%5==0) // 打完五鞭后老马需要恢复的过程 
			{
				hp=hp-0.5*n;//加上第五鞭子 多产生的伤害 
				if(hp<=0) continue;
				time=time+k;
				rage=rage+k*t;
				if(rage>60)
				{
					key=1;
					continue;
				}		
			}
	    }
		if(key==1)
			printf("年轻人不讲武德，年轻人赢了");
		else
			printf("马老没有输，马老赢了") ;
	} 
	return 0;
}
