#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;
};
class list{
node *rear;
public:
list()
{
rear=NULL;
}
void create(int x)
{
node *newNode;
newNode=new node;
newNode->data=x;
newNode->next=NULL;
if(rear==NULL)
{
rear=newNode;
rear->next=newNode;
}
else
{
newNode->next=rear->next;
rear->next=newNode;
}



}


void display()
{
node *temp=NULL;
temp=rear->next;
do
{
cout<<temp->data<<" "<<endl;
temp=temp->next;
}while(temp!=rear->next);

}
};
int main()
{
list obj;
int num;
cin>>num;
while(num!=0)
{
obj.create(num%10);
num=num/10;

}
obj.display();


return 0;
}