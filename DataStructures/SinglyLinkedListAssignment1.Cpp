#include<iostream>
using namespace std;
class child{
public:
	int child_age;
	string child_name;
	child *nextChild;
};
class employee{
	child *childListHead;
	public:
	int emp_id;
	string emp_name;
	employee *next;
	
	
	
	
		child *newNode,*currNode,*temp;
	
		
		employee()
		{
			childListHead=NULL;
		}
		void insertchild(int num)
		{
			char ch;
			int age;
			string name;
			for(int i=1;i<=num;i++)
	
	
				{
			cout<<endl<<"Enter "<<i<<" child name"<<endl;
			cin>>name;
			cout<<endl<<"Enter "<<i<<" child age"<<endl;
			cin>>age;
			newNode=new child;
			newNode->child_age=age;
			newNode->child_name=name;
			newNode->nextChild=NULL;
			if(childListHead==NULL)
				{
				childListHead=newNode;
				currNode=newNode;
				}
			else
				{
				currNode->nextChild=newNode;
				currNode=newNode;
				}
			}
	}
	void display()
	{
		temp=childListHead;
		while(temp)
		{
			cout<<endl<<" employee child name : "<<temp->child_name<<" employee child age : "<<temp->child_age<<endl;
			temp=temp->nextChild;
		}
		
	}

void deleteChild()
{
	child *currNode = childListHead, *nextNode = NULL;

while (currNode != NULL)

{
	nextNode=currNode->nextChild;
	delete currNode;
	currNode=nextNode;
}

}
};

	
	

class empList{
	employee *head,*newNode,*currNode,*temp;
	public:
		
		empList()
		{
			head=NULL;
		}
		void insertEmp()
		{
			char ch;
			int id,num;
			string name;
			do
				{
			cout<<endl<<"Enter employee name"<<endl;
			cin>>name;
			cout<<endl<<"Enter employee id"<<endl;
			cin>>id;
			cout<<endl<<"how many children have you?"<<endl;
			cin>>num;
			newNode=new employee;
			newNode->emp_id=id;
			newNode->emp_name=name;
			newNode->next=NULL;
			if(num==0)
			{
				newNode->insertchild(0);
			}
			else
			{
				newNode->insertchild(num);
			}
			if(head==NULL)
				{
				head=newNode;
				currNode=newNode;
				}
			else
				{
				currNode->next=newNode;
				currNode=newNode;
				}
			
			cout<<endl<<"enter Y to continue"<<endl;
			cin>>ch;
			}	while(ch=='Y'||ch=='y');
		
		}
		
		void displayEmpInfo()
		{
			temp=head;
		while(temp)
		{
			
			cout<<endl<<"employee name : "<<temp->emp_name<<" employee id : "<<temp->emp_id<<" "<<endl;
			temp->display();
			temp=temp->next;
		}
		
		
	}
	
	
	
	void deleteEmployee(int empID)
	{
		
		employee* prevNode=NULL;
		employee* currNode=head;
		int currIndex=1;

	while (currNode && currNode->emp_id != empID) {

	prevNode=currNode;
	currNode=currNode->next;
	currIndex++;

	}	
	
	
		if (currNode) {

	if (prevNode) {
	
	currNode->deleteChild();
	prevNode->next=currNode->next;
cout<<endl<<" employee name : "<<currNode->emp_name<<" having id : "<<currNode->emp_id<<" has deleted"<<endl;
		delete currNode;
	

				}		

	else {
	currNode->deleteChild();
	head=currNode->next;
cout<<endl<<" employee name : "<<currNode->emp_name<<" having id : "<<currNode->emp_id<<" has deleted"<<endl;
		delete currNode;

		}
	}
	
}






void insertNewEmp(int index)
{
	if (index < 0) cout<<"NULL"<<endl;

	int currIndex=1;

	employee *currNode=head;

	while (currNode && index > currIndex) {
	currNode=currNode->next;
	currIndex++;
	}	

	if (index > 0 && currNode == NULL) cout<<"NULL"<<endl;

string name;
int id,num;
			cout<<endl<<"Enter employee name"<<endl;
			cin>>name;
			cout<<endl<<"Enter employee id"<<endl;
			cin>>id;
			cout<<endl<<"how many children have you?"<<endl;
			cin>>num;
			employee* newNode=new employee;
			newNode->emp_id=id;
			newNode->emp_name=name;
			if(num==0)
			{
				newNode->insertchild(0);
			}
			else
			{
				newNode->insertchild(num);
			}
			

	if (index == 0) {
	newNode->next=head;
	head=newNode;
	}

	else {

	newNode->next=currNode->next;
	currNode->next=newNode;

	}
	
}








void searchEmployee(int id)
{
	
	employee *currNode=head;

	int currIndex=1;

while (currNode && currNode->emp_id != id) {

	currNode=currNode->next;
	currIndex++;

	}	

if (currNode)
{
	cout<<"FOUND"<<endl;
	cout<<endl<<" employee name : "<<currNode->emp_name<<" Employee id : "<<currNode->emp_id<<endl;
	currNode->display();
}

}
	
};

int main()
{
	int index,num,id;
	employee obj1;
		empList obj;
		char ch;
	obj.insertEmp();
	
	obj.displayEmpInfo();
	
	cout<<endl<<"press 1 to insert new Employee "<<endl<<endl<<"press 2 to delete Employee"<<endl<<endl<<"press 3 to search Employee"<<endl;
	cin>>num;
	if(num==1)
	{
	cout<<"enter index "<<endl;
	cin>>index;
	obj.insertNewEmp(index);
		
	}
	else if(num==2)
	{
		cout<<endl<<"enter employee id you want to delete"<<endl;
		cin>>id;
		obj.deleteEmployee(id);
	}
	else if(num==3)
	{
		cout<<endl<<"enter employee id you want to search"<<endl;
		cin>>id;
		obj.searchEmployee(id);
		
	}
	cout<<endl<<"press Y to Display Info"<<endl;
	cin>>ch;
	if(ch=='Y'||ch=='y')
	obj.displayEmpInfo();
	cout<<endl<<endl;
	
	return 0;
}
