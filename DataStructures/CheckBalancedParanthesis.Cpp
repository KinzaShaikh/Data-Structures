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

void pop()
{
stackTop--;

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
bool brackets(char a,char b)
{
	if(a=='(' && b== ')')return true;
	else if(a=='{' && b== '}')return true;
	else if(a=='[' && b== ']')return true;
	return false;
	
}

bool paran(char input[])
{
int i=0,a;
while(input[i]!='\0')
{
	
if(input[i]=='('|| input[i]=='{' || input[i]=='[')
	{
	//cout<<endl<<"push"<<input[i]<<endl;
push(input[i]);
	}
else if(input[i]==')'|| input[i]=='}' || input[i]==']')
	{
if(empty() || !brackets(top() , input[i]))
return false;
else pop();

	}
i++;
}
return empty();

 }
};
int main()
{
stack obj;

char input[]="{(}";
cout<<obj.paran(input);
return 0;
}
