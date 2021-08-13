//this is stack.hpp file.
//this is implementation of stack.h
#include "stack.h"  
#include <vector> 
using namespace std;

//default constructor
template<typename T>
stack<T>::stack()
{
    //in deafult constructor size is set to be -1
    size_ = -1;
}


//destructor
template<typename T>
stack<T>::~stack()
{
    //descructor function calls clear function
    clear();
    size_ = -1;
}

//copy constructor
template<typename T>
stack<T>::stack(const stack<T>& x)
{
    //copy the size of the parameter stack
    size_ = x.size_;
    //use move function for copy
    myStack = move(x.myStack);
}


//copy assignment
template<typename T>
stack<T>& stack<T>::operator= (const stack<T>& x)
{
    //creating a temp stacka and assigning the stack that is passed
    stack<T> tempStack = x;
    //using swap function
    swap(*this, tempStack);
    return *this;
}


//move constuctor
template<typename T>
stack<T>::stack(stack<T>&& x)
{
    //copy the size of the parameter stack
    size_ = x.size_;
    myStack = x.myStack;
    //set the size as -1
    x.size_ = -1;
    x.myStack = vector<T>();
}

//move assignment
template<typename T>
stack<T>& stack<T>::operator= (stack<T>&& x)
{
    //using move function
    myStack = move(x.myStack);
    return *this;
}


//returns true if the stack is of size -1 means empty
template<typename T>
bool stack<T>::empty() const
{
    return (size_ < 0);
}


//clear function
template<typename T>
void stack<T>::clear()
{
    //pop until the stack is empty
    while (!empty()) 
        pop();
}

//push using move function
template<typename T>
void stack<T>::push(T&& x)
{   
    //increasing the size of stack
    size_++;
    //push element in stack using move
    myStack.push_back(move(x));
}

//push function, const
template<typename T>
void stack<T>::push(const T& x)
{
    //increasing the size of stack
    size_++;
    //adding element into stack using push_back function
    myStack.push_back(x); 
}



//returns the top element
template<typename T>
T& stack<T>::top()
{
    return myStack[size_];
}


//returns top element, const
template<typename T>
const T& stack<T>::top() const
{
    return myStack[size_];
}

//pop or remove the element
template<typename T>
void stack<T>::pop()
{
    //remove element using pop_back
    myStack.pop_back();
    //decrement in size
    size_--;
}


//returns the size of the stack
template<typename T>
int stack<T>::size() const
{
    return (myStack.size());
}

//print the stack
template<typename T>
void stack<T>::print(std::ostream& os, char ofc) const
{
    for (auto i : myStack) os << i << ofc;
}


//<< operator
template<typename T>
std::ostream& operator << (std::ostream& os, const stack<T>& x)
{
    x.print(os);
    return os;
}

//<= operator
template<typename T>
bool operator <= (const stack<T> s1, const stack<T> s2)
{
    if (s1 == s2)
        return true;
    else if (s1.size() == s2.size())
    {
        stack<T> stack1 = s1, stack2 = s2;
        while (!stack2.empty())
        {
            if (stack2.top() > stack1.top())
                return false;
            stack2.pop();
            stack1.pop();
        }
    }
    return true;
}

//== operator
template<typename T>
bool operator== (const stack<T> s1, const stack<T> s2)
{
    if (s1.size() != s2.size()) 
    return false;
    else
    {
        
        stack <T> stack1 = s1, stack2 = s2;
        while (!stack1.empty() && !stack2.empty())
        {
            if (stack1.top() != stack2.top())
            return false;
            stack1.pop();
            stack2.pop();
        }
    }

    return true;
}
//!= operator
template<typename T>
bool operator!= (const stack<T> stack1, const stack<T> stack2)
{
    return !(stack1 == stack2);
}
