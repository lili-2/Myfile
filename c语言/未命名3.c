#include<stdio.h>
int main()
{
	int m,i,cishu=0,key=0;//���� ��¼ÿ5����Ϣһ�� 
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
			cishu++;//�����ʱ����ı仯		
			time = time+t;
			hp=hp-n;
			if(hp<=0) continue;//��������ѭ�� 
			rage=rage+s+time*t;//���˼���ʱ��仯��������ŭ��ֵ 
			if(rage>60&&cishu%5!=0)
			{
				key=1;//key��¼ ������Ӯ�� 
				continue;
			}		
			if(cishu%5==0) // ������޺�������Ҫ�ָ��Ĺ��� 
			{
				hp=hp-0.5*n;//���ϵ������ ��������˺� 
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
			printf("�����˲�����£�������Ӯ��");
		else
			printf("����û���䣬����Ӯ��") ;
	} 
	return 0;
}
