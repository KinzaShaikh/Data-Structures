//File: bet.h                                             
// This is header file for the BET tree                    
// implementation is provided in bet.hpp file

#ifndef BET_H
#define BET_H 

using namespace std;
class BET
{
	struct BinaryNode
	{
		string data;
		//Right reference to node.
		BinaryNode* right;
		//left reference to node.
		BinaryNode* left;
		BinaryNode(const string& d = string{}, BinaryNode* l = nullptr, BinaryNode* r = nullptr) : data{ d }, left{ l }, right{ r } {}
	};

public:
	//default constructor.	
	BET();
	//constructor with one parameter that takes string as an input
	BET(const string postfix);
	//copy constructor
	BET(const BET&);
	//destructor.							
	~BET();
	//function having one parameter and return type of function is bool.								
	bool buildFromPostfix(const string& postfix);
	//assignment operator
	const BET& operator=(const BET&);
	//function that will print infix expression.			
	void printInfixExpression();
	//function that will print postfix expression
	void printPostfixExpression();
	//this function returns the number of nodes in the tree
	size_t size();
	//this function returns the number of leafs in the tree.
	size_t leaf_nodes();
	//this function will return true if tree is empty,false otherwise.
	bool empty();
	//this function will check the precedence of the brackets in expression 
	int precedenceCheck(string str);
	//this function will return true if the string is not valid, false otherwise
	bool notValid(string str);
	//this function will return true if the string contain operands (1,2,a,b)
	bool isOperand(string str);
	//this function will return true if the string contain operator(+,-,*)
	bool isOperator(string& str);

private: // private helper functions

	//reference of root of the tree
	BinaryNode* root;
	//this will print to standard output the corresponding infix expression.
	void printInfixExpression(BinaryNode* n);
	//this will print to standard output the corresponding postfix expression.
	void printPostfixExpression(BinaryNode* n);
	//this function will return number of nodes in subtree
	size_t size(BinaryNode* t);
	//this function will return number of leaf nodes in subtree
	size_t leaf_nodes(BinaryNode* t);
	//clone all the nodes in subtree
	BinaryNode* clone(BinaryNode* t) const;
	//this function will delete all nodes in subtree	 
	void makeEmpty(BinaryNode*& t);

};
#include "bet.hpp"
#endif