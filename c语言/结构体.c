/*
#include<stdio.h>

struct Student
{
	int age;
	float score;
	char sex;//�������� û�б��� 
};
int main()
{
    struct Student st = {80,66.6,'F'};//��ʼ�� �����ͬʱ��ֵ
	//struct Student st2;
	//st2.age = 10;  
	
	struct Student * pst = &st; 
	
	pst->age = 88; //�ڼ�����ڲ��ᱻת���ɣ�*pst��.age�ȼ��� st.age 
	pst->name;				//pst��ָ����Ǹ��ṹ������е�age�����Ա 
} 
*/

#include<stdio.h>
#include<string.h>

void InputStudent(struct Student * pstu);

struct Student
{
	int age;
	char sex;
	char name[100];
}; //; ����ʡ
 
int main(void)
{
	struct Student st;
	
	InputStudent(&st);//�Խṹ��������� 
	printf("%d %c %s\n",st.age,st.sex,st.name);
	OutoutStudent();//�Խṹ�������� 
	
	return 0;
}

void InputStudent(struct Student * pstu)//pstuֻռ�ĸ��ֽ� �����һ���ֽڵ�ַ ͨ�����ͣ�int *�����ж����������� 
{
	(*pust).age = 10;
	strcpy(pust->name,"����");
	pstu->sex = 'F';
}


