/*
#include<stdio.h>

struct Student
{
	int age;
	float score;
	char sex;//定义类型 没有变量 
};
int main()
{
    struct Student st = {80,66.6,'F'};//初始化 定义的同时赋值
	//struct Student st2;
	//st2.age = 10;  
	
	struct Student * pst = &st; 
	
	pst->age = 88; //在计算机内部会被转换成（*pst）.age等价于 st.age 
	pst->name;				//pst所指向的那个结构体变量中的age这个成员 
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
}; //; 不能省
 
int main(void)
{
	struct Student st;
	
	InputStudent(&st);//对结构体变量输入 
	printf("%d %c %s\n",st.age,st.sex,st.name);
	OutoutStudent();//对结构体变量输出 
	
	return 0;
}

void InputStudent(struct Student * pstu)//pstu只占四个字节 保存第一个字节地址 通过类型（int *）来判断往下数几个 
{
	(*pust).age = 10;
	strcpy(pust->name,"张三");
	pstu->sex = 'F';
}


