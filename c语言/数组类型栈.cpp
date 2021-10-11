 #include <iostream>
 #define STACK_SIZE 1005
 using namespace std;
 int s[STACK_SIZE];
 int top;
 inline void s_push(int val)
 {
 	if(top<STACK_SIZE-1)s[++top]=val; 
 	else cerr<<"stack over flow"<<endl;
 }
 inline int s_top()
 {
 	return s[top];
 }
 inline void s_pop()
 {
 	if(top>0)top--;
 	else cerr<<"stack over flow"<<endl;
 }
 inline int s_size()
 {
 	return top;
 }
 inline bool s_empty()
 {
 	return top==0;
 }
 int main()
 {
 	int n;
 	cin>>n;
 	while(n--)
 	{
 		int op,num;
 		cin>>op;
 		if(op==1)//��ջ 
 		{
 			cin>>num;
 			s_push(num);
		}
		if(op==2)//��ѯջ�� 
			cout<<"top: "<<s_top()<<endl;
		if(op==3)//��ջ 
			s_pop();
		if(op==4)//��С 
			cout<<"size: "<<s_size()<<endl;
		if(op==5)//�� 
			cout<<"empty: "<<(s_empty()?"true":"false")<<endl;
	}
	return 0;
 }

