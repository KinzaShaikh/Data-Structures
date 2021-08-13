//this is stack.h file
#ifndef DL_STACK_H
#define DL_STACK_H

#include <iostream>
#include <vector>
using namespace std;
namespace cop4530 {

    template<typename T>
    class stack {
    private:
        //variable for number of objects
        int size_;               
        vector<T> myStack;

    public:
       //default constructor
        stack();
        //destructor
        ~stack();
        //constructor used for copy
        stack(const stack<T>& x);
        //constructor used to move
        stack(stack<T>&& x);
        //= operator, for move
        stack<T>& operator= (stack<T>&& x);
        //= opertaor for copy
        stack<T>& operator= (const stack<T>& x);
        
        //empty function that will return true if the stack is empty
        bool empty() const;     
        //clear fuction make the stack empty
        void clear();    
        //push x into the stack using copy
        void push(const T& x);  
        //push x into the stack using move
        void push(T&& x); 
        //pop means remove, remove the first or top element
        void pop();   
        //returns the first or top element
        T& top();               
        //returns the first or top element const value
        const T& top() const;  
        //size function returns size of the stack
        int size() const;
        //print is used to print the elements with space 
        void print(std::ostream& os, char ofc = ' ') const;
    };  

    template<typename T>
    std::ostream& operator << (std::ostream& os, const stack<T>& x);

    template<typename T>
    bool operator == (const stack<T> stack1, const stack<T> stack2);

    template<typename T>
    bool operator != (const stack<T> stack1, const stack<T> stack2);

    template<typename T>
    bool operator <= (const stack<T> stack1, const stack<T> stack2);


#include "stack.hpp"  //including .hpp file
}

#endif