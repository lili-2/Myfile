void staff_input()
{
	node1* head, * r, * s;
	char choice;
	head = (node1*)malloc(sizeof(node1));
	head->next = NULL;                                      //建立链表的头结点
	r = head;
	do
	{
		system("cls");
		s = (node1*)malloc(sizeof(node1));                  //建立新节点
		printf("\n\t\t\t\t\t*录入员工信息*\n\n");           //向新节点录入信息
		printf("\t\t\t\t\t姓名：");
		scanf("%s", s->name);
		printf("\n\t\t\t\t\t性别：");
		scanf("%s", s->sex);
		printf("\n\t\t\t\t\t年龄：");
		scanf("%d", &s->age);
		printf("\n\t\t\t\t\t联系方式：");
		scanf("%s", s->phone);
		r->next = s;                                       //尾插法建立链表
		r = s;
		printf("\n\t\t\t\t\t是否继续录入员工信息？(Y/N)");
		choice = getch();
	} while (choice == 'y' || choice == 'Y');             
	r->next = NULL;
	node1 * p;
	FILE* fp = fopen("stafflist.txt", "at");              //以追加方式打开文件
	for (p = head->next; p != NULL; p = p->next)          //向文件中写信息
		fprintf(fp, "%s %s %d %s\n", p->name, p->sex, p->age, p->phone);
	fclose(fp);                                           //关闭文件
	printf("\n\n\t\t\t\t\t信息录入成功！");
	system("pause");
	return;
}
//2.删除信息函数
void staff_delet()
{
	char name[20];
	int flag=0;
	node1* s;
	FILE* fp = fopen("stafflist.txt", "rt");             //以读方式打开原文件
	FILE* ft = fopen("temp2.txt", "wt");                 //创建临时文件
	s = (node1*)malloc(sizeof(node1));
	s->next = NULL;
	system("cls");
	if (fp == NULL || ft == NULL) {
		printf("错误！\n");
		return;
	}
	printf("\n\t\t\t\t\t请输入想要删除的员工姓名：");
	scanf("%s", name);
	while (!feof(fp))     //
	{
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);  
		if (strcmp(name, s->name) != 0)           //若不是要删除的信息则写入临时文件
		{
			fprintf(ft, "%s %s %d %s\n", s->name, s->sex, s->age, s->phone);
		}
		else                                      //若是则不作任何操作
			flag = 0;
	}
	fclose(fp);
	fclose(ft);
	remove("stafflist.txt");                      //移除原文件
	rename("temp2.txt", "stafflist.txt");         //将临时文件名改为原文件名
	if (flag) printf("\n\t\t\t\t\t抱歉TT没有找到该员工信息！");
	else 
	{
		printf("\n\t\t\t\t\t员工信息删除成功！");
		printf("\n\t\t\t\t\t");
	}
	system("pause");
	system("cls");
	return;
}
//3.修改信息函数
void staff_change()
{
	char name[11];
	int flag = 1;
	FILE* fp = fopen("stafflist.txt", "rt");       //以读方式打开原文件
	FILE* ft = fopen("temp.txt", "wt");            //创建临时文件
	node1* s = (node1*)malloc(sizeof(node1));
	s->next = NULL;
	system("cls");
	printf("\n\t\t\t\t\t请输入要修改信息的员工姓名：");
	scanf("%s", name);
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);
		if (strcmp(s->name, name) != 0)           //若不是要删除的信息则写入临时文件
		{
			fprintf(ft, "%s %s %d %s\n", s->name, s->sex, s->age, s->phone);
		}
		else if(strcmp(s->name, name)==0)
		{
			flag = 0;                             //若是则输入新信息并写入临时文件

			printf("\n\n\t\t\t\t\t该员工原信息为：");
			printf("\n\n\t\t\t\t\t姓名：%s", s->name);
			printf("\n\t\t\t\t\t性别：%s", s->sex);
			printf("\n\t\t\t\t\t年龄：%d", s->age);
			printf("\n\t\t\t\t\t电话：%s", s->phone);
			printf("\n\n\t\t\t\t\t请输入新信息：");
			printf("\n\n\t\t\t\t\t姓名：");
			scanf("%s", s->name);
			printf("\n\t\t\t\t\t性别：");
			scanf("%s", s->sex);
			printf("\n\t\t\t\t\t年龄：");
			scanf("%d", &s->age);
			printf("\n\t\t\t\t\t联系方式：");
			scanf("%s", s->phone);
			printf("\n\t\t\t\t\t修改成功！");
		}
	}
	fclose(fp);
	fclose(ft);
	remove("stafflist.txt");                   //移除原文件
	rename("temp.txt", "stafflist.txt");       //将临时文件名改为原文件名
	if (flag) printf("\n\t\t\t\t\t抱歉TT未找到该员工信息！");
	system("\n\t\t\t\t\tpause");
	system("cls");
	return;
}
//4.查找信息函数
void staff_search()
{
	char name[11];
	node1* head, * r, * s, * p;
	FILE* fp = fopen("stafflist.txt", "rt");      //打开文件
	head = (node1*)malloc(sizeof(node1));
	head->next = NULL;                            //建立头结点
	r = head;
	while (!feof(fp))
	{
		s = (node1*)malloc(sizeof(node1));        //读文件并建立链表
		fscanf(fp, "%s %s %d %s", s->name, s->sex, &s->age, s->phone);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	fclose(fp);                                   //关闭文件
	system("cls");
	printf("\n\t\t\t\t\t请输入想要查询的员工姓名：");
	scanf("%s", name);
	p = head->next;
	while (p)                                    //遍历链表查找信息
	{
		if (strcmp(p->name, name) != 0)
			p = p->next;
		else
			break;
	}
	if (p == NULL)
		printf("\n\t\t\t\t\t抱歉TT未找到该员工信息!");
	else
	{

		printf("\n\t\t\t\t\t**********查询结果*********");  //找到则打印信息
		printf("\n\t\t\t\t\t 姓名 * %s", p->name);
		printf("\n\t\t\t\t\t 性别 * %s", p->sex);
		printf("\n\t\t\t\t\t 年龄 * %d", p->age);
		printf("\n\t\t\t\t\t 电话 * %s", p->phone);
	}
	printf("\n\n\t\t\t\t\t");
	system("pause");
	system("cls");
	return;
}

