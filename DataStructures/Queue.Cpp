#include<iostream>
using namespace std;
struct node{
	string name;
	int priority;
	node *next;
};
struct queue{
	node *head,*rear,*curr,*newNode;
	queue()
	{
		head=NULL;
		rear=NULL;
	}
	
	void create(string n,int prior)
	{
		newNode=new node;
		newNode->name=n;
		newNode->priority=prior;
		if(head==NULL || prior < head->priority)
		{
			newNode->next=head;
			head=newNode;
		}
		else
		{
			curr=head;
			while(curr->next!=NULL && curr->next->priority <= prior)
			{
				curr=curr->next;
			}
			newNode->next=curr->next;
			curr->next=newNode;
			
		}
		
	
	
}
void display()
{
	node *temp=head;
	if(head!=NULL)
	{
		
	while(temp)
	{
		cout<<temp->name<<" "<<temp->priority<<endl;
		temp=temp->next;
	}
}
else
cout<<"NULL"<<endl;
}

void deleteNode()
{
	node *curr;
	if(head!=NULL)
	{
		curr=head;
		head=head->next;
		cout<<curr->name<<" "<<curr->priority<<" deleted"<<endl;
		delete curr;
	}
	
}
	
};
int main()
{
	queue obj;
	int choice;
	int p;
	string n;
	char ch;
	cout<<"enter 1 for insertion "<<endl<<" enter 2 for display "<<endl<<" enter 3 for deletion "<<endl;
	cin>>choice;
	
	if(choice==1)
	{
		
		do{
			
			cout<<"enter name of patient "<<endl;
			cin>>n;
			cout<<"enter priority" <<endl<<" a. Normal patients with Priority 0"<<endl<<"b. Patient that pay double fee with priority 1"<<endl;
			
cout<<"c. Patients who can’t wait longer due to some diseaseswith priority 2"<<endl<<"d. Serious patients with priority 3"<<endl;
cin>>p;
obj.create(n,p);
			
			cout<<"enter y to continue"<<endl;
			cin>>ch;
		}while(ch=='y');
		
	}
	else if(choice==2)
	{
	obj.display();
		
	}
	else if(choice==3)
	{
		obj.deleteNode();
	}
cout<<"final Queue"<<endl;
	obj.display();
	return 0;
}
