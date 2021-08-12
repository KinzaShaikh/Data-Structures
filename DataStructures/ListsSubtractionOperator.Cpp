#include<iostream>
using namespace std;
struct node{
	int number;
	node *next;
};
struct list{
	node *head,*tail,*nHead,*nTail,*curr;
	list()
	{
		head=NULL;
		tail=NULL;
		nHead=NULL;
		nTail=NULL;
	}
	void create()
	{
		int num;
		char ch;
		node *newNode;
		do{
			cout<<"enter num"<<endl;
			cin>>num;
			newNode=new node;
			newNode->number=num;
			newNode->next=NULL;
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
			tail->next=newNode;
			tail=newNode;
				
			}
			
			cout<<"enter y to continue"<<endl;
			cin>>ch;
		}while(ch=='y');
	}
	void display()
	{
		curr=head;
		while(curr)
		{
			cout<<curr->number<<" ";
			curr=curr->next;
		}
	}
	
	void subtract(int a,int b)
	{
		
	node *newnode;
	newnode=new node;
		newnode->number=a-b;
		newnode->next=NULL;
		if(nHead==NULL)
		{
			nHead=newnode;
			nTail=newnode;
		}
		else
		{
			nTail->next=newnode;
			nTail=newnode;
		}
	}
	void displayFinal()
	{
			cout<<"after subtraction"<<endl;
		node *t=nHead;
		while(t)
		{
			cout<<t->number<<" ";
			t=t->next;
		}
	
	}
	list operator -(list &ob1)
	{
		cout<<endl;
		node *temp=head;
		node *temp2=ob1.head;
	int a,b;
	while(temp!=NULL || temp2!= NULL)
	{
	//	cout<<temp->number<<" "<<temp2->number<<endl;
	if(temp==NULL){
	
	//	cout<<"temp1"<<endl;
		a=0;
		b=temp2->number;
	//	cout<<"a"<<a<<endl;
	}
	
	else if(temp2==NULL)
	{
	//	cout<<"temp2"<<endl;
		a=temp->number;
		b=0;
	//	cout<<"b"<<b<<endl;
	}
	else{
		a=temp->number;
		b=temp2->number;
		}
	cout<<endl;
	//cout<<"a "<<a<<" b "<<b<<endl;
		subtract(a,b);
		if(temp)
		temp=temp->next;
		if(temp2)
		temp2=temp2->next;
		
	 } 
	displayFinal();
	}
};
int main()
{
	list obj1,obj2;
	cout<<"enter list one"<<endl;
	obj1.create();
	cout<<"enter list two"<<endl;
	obj2.create();
	cout<<endl<<" list one"<<endl;
	obj1.display();
	cout<<endl<<" list two"<<endl;
	obj2.display();
	obj1-obj2;
	
	return 0;
}
