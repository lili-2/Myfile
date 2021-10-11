#include<stdio.h>
struct stu{
    int num;
    float score;
    int rank;
}student[105]; 

void sort(struct stu* ps,int n)
{
	struct stu t;
	
	int k;
	
    for(int i=1;i<=n;i++)
    {
    	for(int j =1;j<=n-1;j++)
    	{
    		if(ps[j].score == ps[j+1].score)
    		{
    			ps[j+1].rank = ps[j].rank;
			}
    		else if(ps[j].score < ps[j+1].score)
    		{
    			k=ps[j].rank;
    			ps[j].rank = ps[j+1].rank;
    			ps[j+1].rank = k;
    			t=ps[j];
    			ps[j]=ps[j+1];
    			ps[j+1]=t;
			}
		}
	}

	for(int i =1;i<=n;i++)
	{
		printf("%d %d %.2f\n",ps[i].rank,ps[i].num,ps[i].score);
	}
	
}
int main(void)
{
	int n;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&student[i].num);
		scanf("%f",&student[i].score);
		student[i].rank = i;
	}
	
	sort(student,n);

	return 0;
 }

