  #include <stdio.h>
 struct queue
 {
 	int data[100];//���е����壬������������ 
 	int head;//���� 
 	int tail;//��β 
 };
 int main()
 {
 	struct queue q;
 	int i;
 	//��ʼ������ 
 	q.head=1;
 	q.tail=1;
 	for(i=1;i<=9;i++)
 	{
 		//����������в���9���� 
 		scanf("%d",&q.data[q.tail]);
 		q.tail++;
	 }
	 while(q.head<q.tail)//�����в�Ϊ��ʱ��ִ��ѭ�� 
	 {
	 	//��ӡ���ף��������׳��� 
	 	printf("%d\n",q.data[q.head]);
	 	q.head++;
	 	
	 	//�Ƚ��¶��׵�����ӵ���β 
	 	q.data[q.tail]=q.data[q.head];
	 	q.tail++;
	 	//�ٽ����׳���
		 q.head++; 
	 }
	 //�Ƚ�����ɾ�����ٽ��µ�����������β���Դ�ѭ���� 
 	getchar();getchar();
 	return 0;
 }

