void staff_input()
{
	node1* head, * r, * s;
	char choice;
	head = (node1*)malloc(sizeof(node1));
	head->next = NULL;                                      //���������ͷ���
	r = head;
	do
	{
		system("cls");
		s = (node1*)malloc(sizeof(node1));                  //�����½ڵ�
		printf("\n\t\t\t\t\t*¼��Ա����Ϣ*\n\n");           //���½ڵ�¼����Ϣ
		printf("\t\t\t\t\t������");
		scanf("%s", s->name);
		printf("\n\t\t\t\t\t�Ա�");
		scanf("%s", s->sex);
		printf("\n\t\t\t\t\t���䣺");
		scanf("%d", &s->age);
		printf("\n\t\t\t\t\t��ϵ��ʽ��");
		scanf("%s", s->phone);
		r->next = s;                                       //β�巨��������
		r = s;
		printf("\n\t\t\t\t\t�Ƿ����¼��Ա����Ϣ��(Y/N)");
		choice = getch();
	} while (choice == 'y' || choice == 'Y');             
	r->next = NULL;
	node1 * p;
	FILE* fp = fopen("stafflist.txt", "at");              //��׷�ӷ�ʽ���ļ�
	for (p = head->next; p != NULL; p = p->next)          //���ļ���д��Ϣ
		fprintf(fp, "%s %s %d %s\n", p->name, p->sex, p->age, p->phone);
	fclose(fp);                                           //�ر��ļ�
	printf("\n\n\t\t\t\t\t��Ϣ¼��ɹ���");
	system("pause");
	return;
}
//2.ɾ����Ϣ����
void staff_delet()
{
	char name[20];
	int flag=0;
	node1* s;
	FILE* fp = fopen("stafflist.txt", "rt");             //�Զ���ʽ��ԭ�ļ�
	FILE* ft = fopen("temp2.txt", "wt");                 //������ʱ�ļ�
	s = (node1*)malloc(sizeof(node1));
	s->next = NULL;
	system("cls");
	if (fp == NULL || ft == NULL) {
		printf("����\n");
		return;
	}
	printf("\n\t\t\t\t\t��������Ҫɾ����Ա��������");
	scanf("%s", name);
	while (!feof(fp))     //
	{
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);  
		if (strcmp(name, s->name) != 0)           //������Ҫɾ������Ϣ��д����ʱ�ļ�
		{
			fprintf(ft, "%s %s %d %s\n", s->name, s->sex, s->age, s->phone);
		}
		else                                      //���������κβ���
			flag = 0;
	}
	fclose(fp);
	fclose(ft);
	remove("stafflist.txt");                      //�Ƴ�ԭ�ļ�
	rename("temp2.txt", "stafflist.txt");         //����ʱ�ļ�����Ϊԭ�ļ���
	if (flag) printf("\n\t\t\t\t\t��ǸTTû���ҵ���Ա����Ϣ��");
	else 
	{
		printf("\n\t\t\t\t\tԱ����Ϣɾ���ɹ���");
		printf("\n\t\t\t\t\t");
	}
	system("pause");
	system("cls");
	return;
}
//3.�޸���Ϣ����
void staff_change()
{
	char name[11];
	int flag = 1;
	FILE* fp = fopen("stafflist.txt", "rt");       //�Զ���ʽ��ԭ�ļ�
	FILE* ft = fopen("temp.txt", "wt");            //������ʱ�ļ�
	node1* s = (node1*)malloc(sizeof(node1));
	s->next = NULL;
	system("cls");
	printf("\n\t\t\t\t\t������Ҫ�޸���Ϣ��Ա��������");
	scanf("%s", name);
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);
		if (strcmp(s->name, name) != 0)           //������Ҫɾ������Ϣ��д����ʱ�ļ�
		{
			fprintf(ft, "%s %s %d %s\n", s->name, s->sex, s->age, s->phone);
		}
		else if(strcmp(s->name, name)==0)
		{
			flag = 0;                             //��������������Ϣ��д����ʱ�ļ�

			printf("\n\n\t\t\t\t\t��Ա��ԭ��ϢΪ��");
			printf("\n\n\t\t\t\t\t������%s", s->name);
			printf("\n\t\t\t\t\t�Ա�%s", s->sex);
			printf("\n\t\t\t\t\t���䣺%d", s->age);
			printf("\n\t\t\t\t\t�绰��%s", s->phone);
			printf("\n\n\t\t\t\t\t����������Ϣ��");
			printf("\n\n\t\t\t\t\t������");
			scanf("%s", s->name);
			printf("\n\t\t\t\t\t�Ա�");
			scanf("%s", s->sex);
			printf("\n\t\t\t\t\t���䣺");
			scanf("%d", &s->age);
			printf("\n\t\t\t\t\t��ϵ��ʽ��");
			scanf("%s", s->phone);
			printf("\n\t\t\t\t\t�޸ĳɹ���");
		}
	}
	fclose(fp);
	fclose(ft);
	remove("stafflist.txt");                   //�Ƴ�ԭ�ļ�
	rename("temp.txt", "stafflist.txt");       //����ʱ�ļ�����Ϊԭ�ļ���
	if (flag) printf("\n\t\t\t\t\t��ǸTTδ�ҵ���Ա����Ϣ��");
	system("\n\t\t\t\t\tpause");
	system("cls");
	return;
}
//4.������Ϣ����
void staff_search()
{
	char name[11];
	node1* head, * r, * s, * p;
	FILE* fp = fopen("stafflist.txt", "rt");      //���ļ�
	head = (node1*)malloc(sizeof(node1));
	head->next = NULL;                            //����ͷ���
	r = head;
	while (!feof(fp))
	{
		s = (node1*)malloc(sizeof(node1));        //���ļ�����������
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	fclose(fp);                                   //�ر��ļ�
	system("cls");
	printf("\n\t\t\t\t\t��������Ҫ��ѯ��Ա��������");
	scanf("%s", name);
	p = head->next;
	while (p)                                    //�������������Ϣ
	{
		if (strcmp(p->name, name) != 0)
			p = p->next;
		else
			break;
	}
	if (p == NULL)
		printf("\n\t\t\t\t\t��ǸTTδ�ҵ���Ա����Ϣ!");
	else
	{

		printf("\n\t\t\t\t\t**********��ѯ���*********");  //�ҵ����ӡ��Ϣ
		printf("\n\t\t\t\t\t ���� * %s", p->name);
		printf("\n\t\t\t\t\t �Ա� * %s", p->sex);
		printf("\n\t\t\t\t\t ���� * %d", p->age);
		printf("\n\t\t\t\t\t �绰 * %s", p->phone);
	}
	printf("\n\n\t\t\t\t\t");
	system("pause");
	system("cls");
	return;
}

