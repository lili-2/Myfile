#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
    int id;
    char name[20];
    int age;
    struct Student* pre;
    struct Student* next;
}Node;

void AddNode(int id,char name[],int age,Node* MainNode);
void InsertNode(Node* posNode,Node* MainNode);
void DeINode(int age, Node* MainNode);
void PrintTitle();
void PrintTree(char mode, Node* MainNode);
Node* CreateTree();
Node* CreateNode(int id,char name[],int age);
int main(int argc, char const *argv[])
{
    Node* MotherNode = CreateTree();
    AddNode(1,"1",5,MotherNode);
    AddNode(2,"2",4,MotherNode);
    AddNode(3,"3",3,MotherNode);
    AddNode(4,"4",2,MotherNode);
    AddNode(5,"5",1,MotherNode);
    AddNode(6,"6",6,MotherNode);
    AddNode(7,"7",7,MotherNode);
    AddNode(8,"8",8,MotherNode);
    AddNode(9,"9",9,MotherNode);
    AddNode(10,"10",10,MotherNode);
    PrintTitle();
    PrintTree('1',MotherNode);
    return 0;
}
void AddNode(int id,char name[],int age,Node* MainNode)
{
    if (MainNode->id)
    {
        MainNode->id = id;
        strcpy(MainNode->name,name);
        MainNode->age = age;
    }else{
        Node* NewNode = CreateNode(id,name,age);
        InsertNode(NewNode, MainNode);
    }
    
}
void InsertNode(Node* posNode,Node* MainNode)
{
    if (posNode->age < MainNode->age)
    {
        if(!MainNode->pre)
        {
            MainNode->pre = posNode;
        }
        else
        {
            InsertNode(posNode,MainNode->pre);
        }
    }else{
        if (!MainNode->next)
        {
            MainNode->next = posNode;
        }
        else
        {
            InsertNode(posNode,MainNode->next);
        }
        
    }
}
void DeINode(int age, Node* MainNode);
void PrintTitle()
{
    printf("%s\t%s\t%s\n","1","2","3");
}
void PrintTree(char mode, Node* MainNode)
{
    if (MainNode)
    {
        if(mode == '1')
        {
            printf("%d\ts%s\t%d\n",MainNode->id,MainNode->name,MainNode->age);
        }
        PrintTree(mode,MainNode->pre);
        if(mode == '2')
        {
            printf("%d\ts%s\t%d\n",MainNode->id,MainNode->name,MainNode->age);
        }
        PrintTree(mode,MainNode->next);
        if(mode == '3')
        {
            printf("%d\ts%s\t%d\n",MainNode->id,MainNode->name,MainNode->age);
        }
    }
    
}
Node* CreateTree()
{
    return CreateNode(0, "NULL", 0);
}
Node* CreateNode(int id,char name[],int age)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->id = id;
    strcpy(NewNode->name, name);
    NewNode->age = age;
    NewNode->pre = NULL;
    NewNode->next = NULL;
    return NewNode;
}
