#include<iostream>
using namespace std;
struct child{
	int cAge;
	string cName;
	child * cNext;
};
struct wife{
	int wAge;
	string wName;
	wife *wNext;
};
struct employee{
	int age,id;
	string name;
	employee *next;
};
struct list{
	employee *eHead,*eCurr;
	wife *wHead,*wCurr;
	child *cHead,*cCurr;
	list()
	{
		eHead=NULL;
		cHead=NULL;
		wHead=NULL;
		}	
	void create()
	{
		int a,iD,wA,one,cA,two;
		string n,wN,cN;
		char ch;
		child *newC;
		employee *newNode;
		wife *newW;
		do{
			cout<<"enter id"<<endl;
			cin>>iD;
			cout<<"enter name "<<endl;
			cin>>n;
			cout<<"enter age "<<endl;
			cin>>a;
			newNode=new employee;
			newNode->age=a;
			newNode->id=iD;
			newNode->name=n;
			newNode->next=NULL;
			cout<<"press 1 if you are married"<<endl;
			cin>>one;
			if(one==1)
			{
				cout<<"enter wife name"<<endl;
				cin>>wN;
				cout<<"enter wife age"<<endl;
				cin>>wA;
				newW=new wife;
				newW->wAge=wA;
				newW->wName=wN;
				newW->wNext=NULL;
				cout<<"press 1 if you have children"<<endl;
				cin>>two;
				if(two==1)
				{
				cout<<"enter child name"<<endl;
				cin>>cN;
				cout<<"enter child age"<<endl;
				cin>>cA;
				newC=new child;
				newC->cAge=cA;
				newC->cName=cN;
				newC->cNext=NULL;
					if(cHead==NULL)
					{
						cHead=newC;
						cCurr=newC;
					}
					else
					{
						cCurr->cNext=newC;
						cCurr=newC;
					}
				}else
				{
					cout<<"you don't have child"<<endl;
				}
	
				if(wHead==NULL)
				{
					wHead=newW;
					wCurr=newW;
				}
				else
				{
					wCurr->wNext=newW;
					wCurr=newW;
				}
				
			}else
			{
				cout<<"You are not married"<<endl;
			}
			
			if(eHead==NULL)
			{
				eHead=newNode;
				eCurr=newNode;
			}
			else
			{
				eCurr->next=newNode;
				eCurr=newNode;
			}
			
			cout<<"enter y to continue"<<endl;
			cin>>ch;
		}while(ch=='y');
		
		
		
	}
	void display()
		
		{
			employee *temp=NULL;
			wife *temp1=NULL;
			temp1=wHead;
			temp=eHead;
			child *t=NULL;
			t=cHead;
			while(temp)
			{
				cout<<"employee name : "<<temp->name<<" employee age : "<<temp->age<<" employee id : "<<temp->id<<endl;
				temp=temp->next;
			}
			while(temp1)
			{
				cout<<"Wife NAME  : "<<temp1->wName<<"Wife Age "<<temp1->wAge<<endl;
				temp1=temp1->wNext;
			}
			while(t)
			{
				cout<<"Child name : "<<t->cName<<" child age : "<<t->cAge<<endl;
				t=t->cNext;
			}
		}
		
		void findParents(string name)
		{
			child *curr=cHead;
			employee *c=eHead;
			wife *w=wHead;
			while(curr->cName!=name)
			{
				c=c->next;
				w=w->wNext;
				curr=curr->cNext;
			}
			if(curr->cName==name)
			{
				cout<<" father age : "<<c->age<<" father id : "<<c->id<<" father name : "<<c->name<<endl;
				cout<<" mother age : "<<w->wAge<<" mother name : "<<w->wName<<endl;
			}
			
			
		}
		
		
		
		
		
		void findChild(string name)
		{
			child *curr=cHead;
			employee *c=eHead;
			wife *w=wHead;
		
			while(c->name!=name)
			{
				w=w->wNext;
				curr=curr->cNext;
				c=c->next;
				
			}
		
		if(w!=NULL&&curr!=NULL)
			{
					
				if(c->name==name)
			{
				cout<<" mother age : "<<w->wAge<<" mother name : "<<w->wName<<endl;
				cout<<" child age : "<<curr->cName<<" child name : "<<curr->cName<<endl;
			
			}
		}
		else
		{
			
				if(w==NULL)
			{
				cout<<" not married"<<endl;
			}
			else if(curr==NULL)
			{
				cout<<" mother age : "<<w->wAge<<" mother name : "<<w->wName<<endl;
				cout<<"no child"<<endl;
			}
		}
		
		}
};
int main()
{
	list obj;
	obj.create();
	cout<<endl;
	int option;
	string name,father;
	cout<<"enter 1 to find parents "<<" and 2 to find child"<<endl;
	cin>>option;
	if(option==1)
	{
		cout<<"enter child's name "<<endl;
		cin>>name;
	obj.findParents(name);
	}
	else if(option==2)
	{
		cout<<"enter father's name "<<endl;
		cin>>father;
		obj.findChild(father);
	}
	return 0;
}
