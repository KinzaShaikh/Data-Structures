#include<iostream>
using namespace std;
template<class type>
class stacks{
	public:
	int top;
	int max;
	int count;
	type *list;
	stacks()
	{
		count=0;
		top=0;
		max=20;
		list=new type[max];
	}
	void initialize()
	{
		top=0;
		count=0;
		
	}
	bool isEmpty(){
		return(top==0);
	}
	bool isFull()
	{
		return(top==max);
	}
	void create(type data)
	{
		if(!isFull())
		{
			list[top]=data;
			top++;
			count++;
		}
		else
		{
			cout<<"Already Full"<<endl;
		}
	}
	void pop()
	{
		if(!isEmpty())
		{
			top--;
			count--;
		}else
		{
			cout<<"empty "<<endl;
		}
	}
	void display()
	{
		for(int i=0;i<top;i++)
		{
			cout<<list[i]<<" ";
		}
	}
	~stacks()
	{
		delete []list;
	}
};
int main()
{
	stacks <int>obj;
	obj.create(1);
	obj.create(2);
	obj.create(3);
	obj.create(4);
	obj.create(5);
	obj.display();
	cout<<endl;
	obj.pop();
	obj.display();
	cout<<endl;
	obj.pop();
	obj.display();
	cout<<endl;
	obj.pop();
	
	return 0;
}
