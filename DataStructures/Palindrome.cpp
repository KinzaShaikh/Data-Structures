#include<iostream>
using namespace std;
class node{
public:
node *next,*prev;
char data;
};
class list{
public:

node *head,*tail;
list()
{
head=NULL;
tail=NULL;

}

void insertData()
{
node *newNode,*curr;
char num;
char ch;
do{
cout<<"enter char "<<endl;
cin>>num;
newNode=new node;
newNode->data=num;
if(head==NULL)
{
newNode->next=NULL;
newNode->prev=NULL;
head=newNode;
tail=newNode;
curr=newNode;
}
else
{
newNode->next=NULL;
newNode->prev=curr;
curr->next=newNode;
curr=newNode;
tail=newNode;

}
cout<<"y to continue"<<endl;
cin>>ch;
} while(ch=='y');

curr=head;
while(curr)
{
cout<<curr->data<<" ";
curr=curr->next;
}
}

void display()
{
node *curr=tail;
while(curr)
{
cout<<curr->data<<" ";
curr=curr->prev;
}
}
int PALINDROM()

{node* start=head;

int count=0;

int i=0;

node*  end=tail;

bool found=false;

while(start)

{

       start=start->next;

       count++;

}

start=head;

while(i<count/2&&!found)

{

       if(start->data==end->data)

       { start=start->next;

       end=end->prev;

       i++;

       found=false;

     

       }

       else

       {

       found=true;

       }

 

}

return found;

}

};
int main()
{
char x;
list obj;
obj.insertData();
//obj.display();
int a=obj.PALINDROM();
if(a==0)
cout<<"palindrome"<<endl;
else
cout<<"no palidrome";
return 0;
}