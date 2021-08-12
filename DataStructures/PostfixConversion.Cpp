#include<iostream>
using namespace std;
struct stack{
	int stackTop;
	char *list;
	int max;
	stack()
	{
		stackTop=-1;
		max=50;
		list =new char[max];
	}
	bool empty()
	{
		return(stackTop==-1);
	}
	bool full()
	{
		return(stackTop==max);
	}
	void push(char x)
	{
		if(!full())
		{
		
		stackTop++;
		list[stackTop]=x;
		
	
		}
		else
		cout<<"FULL"<<endl;
			}
	
	void pop(char x)
	{
		
		if(list[stackTop]=='('&& x==')' || list[stackTop]=='{' && x=='}' || list[stackTop]=='[' && x==']' )
		{
			stackTop--;
			cout<<"done"<<endl;
		}
		
		else
		{
			cout<<"error"<<endl;
		}
	}
	void display()
	{
		for(int i=0;i<stackTop;i++)
		{
			cout<<list[i]<<" ";
		}
	
	}
	char top()
	{
		return list[stackTop];
	}
	void paran(char input[])
	{
		int i=0;
		while(input[i]!='\0')
		{
			if(input[i]=='('|| input[i]=='{' || input[i]=='[')
			{
				push(input[i]);
			}
			else if(input[i]==')'|| input[i]=='}' || input[i]==']')
			{
				pop(input[i]);
			
			}
			i++;
		}
		
 }
};
int main()
{
	stack obj;
	
	char input[]="[{()]";
	obj.paran(input);
	return 0;
}
