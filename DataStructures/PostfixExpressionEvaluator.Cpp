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
	
	char pop()
	{
		char a=list[stackTop];
		if(!empty())
		stackTop--;
		else
		cout<<"empty"<<endl;
		return a;
	}
	void display()
	{
		for(int i=0;i<=stackTop;i++)
		{
			cout<<list[i]<<" ";
		}
	
	}
	char top()
	{
		return list[stackTop];
	}
	
	int isOperator(char x)
	{
		switch(x)
		{
			case '+':
			case '-':
			case '/':
			case '*':
				{
				
				return 1;
				break;	
				}
				default:
				return 0;
		}
	}
	
	
	int isOperand(char ch)
	{
		if(ch>='a' && ch <= 'z' || ch>='A' && ch<= 'Z' || ch>='1' && ch<='9')
		return 1;
		else
		return 0;
	}
	
	
void postToAns(char input[])
	{
		int i=0;
		int n1,n2,n3,x;
		char d;
		while(input[i] != '\0')
		{
			if(isOperand(input[i]))
			{
				x=(int)input[i]-48;
			//	cout<<" "<<x;
				push(x);
			}
			else
			{
			n1 =(int)pop();
			n2 = (int)pop();
			//cout<<n1<<" "<<n2<<endl;
			switch ( input[i] )
			{
				case '+' :
					n3 = n2 + n1 ;
					break ;
				case '-' :
					n3 = n2 - n1 ;
					break ;
				case '/' :
					n3 = n2 / n1 ;
					break ;
				case '*' :
					n3 = n2 * n1 ;
					break ;
				case '%' :
					n3 = n2 % n1 ;
					break ;
				default :
					cout << "Unknown operator" ;
					
						}
			//cout<<" "<<n3<<endl;
			push ( (char)n3 ) ;
			
				
				}
				i++;
				}
				cout<<"Answer "<<(int)pop()<<endl;
	}
	
};

int main()
{

stack obj;
string data;
	
	cin>>data;
	
	int a=data.length();
	
	//cout<<a<<endl;
	char input[a];
	for(int i=0;i<a;i++)
	{
		input[i]=data[i];
	}
	obj.postToAns(input);
	
	return 0;
}
