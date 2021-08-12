//File: bet.hpp                                             
// implementation is provided in bet.hpp file

#include <iostream>
#include <sstream> 
#include <string>
#include <stack>
#include <vector>
//#include "bet.h";
//using namespace std;

BET::BET()
{
    root = new BinaryNode;
}

//this will take postfix (string) as a parameter and build a tree.
BET::BET(const string postfix)
{
    root = new BinaryNode;
    buildFromPostfix(postfix);
}


BET::BET(const BET& rhs) : root{ nullptr }
{
    root = clone(rhs.root);
}

//thsi is descructor taht will make the tree empty only if the root of the tree is not null
BET::~BET()
{
    //function call
    makeEmpty(root);
}

//this function has a parameter and using postfix expression this will build the tree.
//this function also check if the expression is valid or not.
bool BET::buildFromPostfix(const string& postfix)
{
    stringstream s(postfix);
    //temporary string variable
    string tempStr;
    //A binary node
    stack<BinaryNode*> bNode;
    int Count1 = 0, Count2 = 0, count3 = 0;
    //if the postfix is empty this will show message of invalid expression.
    if (postfix.empty())
    {
        cout << "Invalid expression, please try again\n";
        root = nullptr;
        return false;
    }
    //if not empty it will call makeEmpty function.
    if (!empty())
    {
        makeEmpty(root);
    }
    while (s >> tempStr)
    {
        //here a newNode is created
        BinaryNode* newNode = new BinaryNode(tempStr);
        if (s.tellp() == 0 && count3 == 0)
        {
            //here its checking wether it is operator or ( ), that will be invalid
            if (isOperator(tempStr) || tempStr == "(" || tempStr == ")")
            {
                cout << "Expression is invalid, please try again\n";
                root = nullptr;
                return false;
            }
            count3 += 1;
        }
        //here it checks for the invalid expression
        if (notValid(tempStr))
        {
            cout << "Expression is invalid, please try again\n";
            root = nullptr;
            return false;
        }
        //if it is operand it is pushed.
        if (isOperand(tempStr))
        {
            Count1 += 1;
            bNode.push(newNode);
        }
        else if (precedenceCheck(tempStr) != 0)
        {
            //again checking for invalid input
            Count2 += 1;
            if (Count1 == Count2)
            {
                cout << "Error! Incorrect order or few operands\n";
                root = nullptr;
                return false;
            }
            else
            {
                //if the expression is valid this code will be executed
                newNode->left = bNode.top();
                bNode.pop();
                newNode->right = bNode.top();
                bNode.pop();
                bNode.push(newNode);
            }
        }
    }
    if (Count1 != Count2)
    {
        root = bNode.top();
    }
    if (bNode.empty())
    {
        cout << "Error! Invalid space character\n";
        root = nullptr;
        return false;
    }
    return true;
}

//= operator function
const BET& BET::operator=(const BET& r)
{
    root = clone(r.root);
    return *this;
}
//this will print the postfix expression. It has no parameter
void BET::printPostfixExpression()
{
    //call to a function that recieves a parameter and print postfix.
    printPostfixExpression(root);
    cout << endl;
}

//this will print the Infix expression. It has no parameter
void BET::printInfixExpression()
{
    //call to a function that recieves a parameter and print infix.
    printInfixExpression(root);
    cout << endl;
}

//this will return size of binary tree
size_t BET::size()
{
    return (size(root));
}

//this will return the number of leaf nodes
size_t BET::leaf_nodes()
{
    return (leaf_nodes(root));
}

//the function that will return true if the tree is empty else false
bool BET::empty()
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//this will return true if the string contain operator
bool BET::isOperator(string& str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/") //  || str == "^")
    {
        return true;
    }
    else
    {
        return false;
    }
}


//this will return true if the string contain operand
bool BET::isOperand(const string str)
{
    if (str != "+" && str != "-" && str != "*" && str != "/")
    {
        return true;
    }
    else
    {
        return false;
    }
}

//this function will check the precedence of brackets.
//it will return an integer.
int BET::precedenceCheck(const string str)
{
    if (str == "(" || str == ")")
        return (3);
    else if (str == "*" || str == "/")
        return (2);
    else if (str == "+" || str == "-")
        return (1);
    else
        return 0;
}


//this function will retuen rue if the expression is not valid else false
bool BET::notValid(string str)
{
    if (str == "(" || str == ")" || str == "^" || str == "_" || str == "&" || str == "%" || str == "$" || str == "#" || str == "@" || str == "!" || str == "~") // && str != "(" && str != ")" && str != "^")
    {
        return true;
    }
    else
    {
        return false;
    }
}


//private functions


//printing InfixExpression
void BET::printInfixExpression(BinaryNode* n)
{
    bool parenthesisFlag = false;
    //if the root is not null
    if (n != nullptr)
    {
        //if it is a leaf node print the data
        if (n->left == nullptr && n->right == nullptr)
            cout << n->data << " ";
        //else precedence is checked
        else
        {
            if (precedenceCheck(n->data) != 0 && precedenceCheck(n->right->data) != 0)
            {
                if (precedenceCheck(n->data) >= precedenceCheck(n->right->data))
                {
                    if (precedenceCheck(n->data) == 2)
                    {
                        cout << "( ";
                        parenthesisFlag = true;
                    }
                }
            }
            printInfixExpression(n->right);
            if (parenthesisFlag == true)
            {
                cout << ") ";
            }
            parenthesisFlag = false;
            cout << n->data << " ";
            if (precedenceCheck(n->data) != 0 && precedenceCheck(n->left->data) != 0)
            {
                if (precedenceCheck(n->data) >= precedenceCheck(n->left->data))
                {
                    cout << "( ";
                    parenthesisFlag = true;
                }
            }
            printInfixExpression(n->left);
            if (parenthesisFlag == true)
            {
                cout << ") ";
            }
            parenthesisFlag = false;
        }
    }
}


//this function will delete all nodes of binary tree recursively
void BET::makeEmpty(BinaryNode*& t)
{
    if (t != nullptr)
    {
        makeEmpty(t->right);
        makeEmpty(t->left);
        delete t;
    }
    t = nullptr;
}



//this will clone the nodes in subtree
BET::BinaryNode* BET::clone(BinaryNode* t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    else
    {
        return new BinaryNode(t->data, clone(t->left), clone(t->right));
    }
}

//this will print the postFix expression
void BET::printPostfixExpression(BinaryNode* n)
{
    if (n != nullptr)
    {
        printPostfixExpression(n->right);
        printPostfixExpression(n->left);
        cout << n->data << " ";

    }
}

//this will return the size of binary node
//this function is recursive
size_t BET::size(BinaryNode* t)
{
    if (t == nullptr)
    {
        return 0;
    }
    else
    {
        return (size(t->right) + size(t->left) + 1);
    }
}

//this will calculate the number of leaf nodes.
//this function also call itself (recursive)
size_t BET::leaf_nodes(BinaryNode* t)
{
    if (t == nullptr)
        return 0;
    else if ((t->left == nullptr) && (t->right == nullptr))
        return 1;
    else
        return (leaf_nodes(t->left) + leaf_nodes(t->right));
}
