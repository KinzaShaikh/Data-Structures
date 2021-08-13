#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"
#include <algorithm>
#include <cstdlib>
using namespace std;
using namespace cop4530;


struct inputStruct {
    //store any expressiom
    string expression;
    //for precedence
    int precedence;

    //default constructor
    inputStruct() : expression(""), precedence(0) {}
    //parameter constructor
    inputStruct(string str) : expression(str) {

        if (!expression.empty()) {

            char operation = expression[0];
            if (operation == '+' || operation == '-')
            precedence = 1;
            if (operation == '*' || operation == '/') 
            precedence = 2;
            else 
            precedence = -1;
        }
        else precedence = -1;
    }
};

//these functions will be used
bool operandChecker(char str);
bool isNum(string str);
bool operatorChecker(char str);
void postfix_to_ans(vector<inputStruct> expression);
void infix_to_postfix(vector<inputStruct> expression);
string evaluate(inputStruct operation1, inputStruct operation2, inputStruct operation);

//main method
int main() {

    vector<inputStruct> inputS;
    string expression;
    char charInput;
    bool flag = true;

    while (flag) {
        cout << "Enter infix expression (\"exit\" to quit): ";

        while (cin.get(charInput) && flag) {
            if (expression == "exit") {
                flag = false;
                break;
            }
            else {
                if (charInput == '\n') {
                    inputS.push_back(expression);
                    infix_to_postfix(inputS);
                    expression = "";
                    inputS.clear();
                    cout << "Enter Infix expression (\"exit\" to quit): ";
                }
                else if (charInput == ' ') {
                    inputS.push_back(inputStruct(expression));
                    expression = "";
                }
                else if (charInput == '(' || charInput == ')') {
                    string x;
                    x += charInput;
                    inputS.push_back(inputStruct(x));
                }
                else if (charInput == '\0') {
                    flag = false;
                }
                else {
                    expression += charInput;
                }
            }
        }
        flag = false;
    }

    return (EXIT_SUCCESS);
}

//this function will return true is the input str is operator
bool operatorChecker(string inputStr)
{
    return(inputStr == "+" || inputStr == "-" || inputStr == "/" || inputStr == "*");
}

//this function will return true is the input str is operand
bool operandChecker(string inputStr)
{
    if (inputStr.length() == 1)
    {
        char ch = inputStr[0];

        return((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_'));
    }
    return true;
}


//this function will return true is the input str is variable, num or operator
bool isNum(string inputStr)
{
    for (auto i = inputStr.begin(); i != inputStr.end(); ++i)
    {
        char ch = *i;

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '_'))  return false;
    }
    return true;
}

//evaluation
string evaluate(inputStruct op1, inputStruct op2, inputStruct operation)
{
    double operand1 = 0.0, operand2 = 0.0;
    stringstream ss;

    //string to double conversion
    operand1 = atof(op1.expression.c_str());
    operand2 = atof(op2.expression.c_str());


    if (operation.expression == "*")
        operand1 *= operand2;
    else if (operation.expression == "/") {
        if (operand2 != 0)
            operand1 /= operand2;
        else
            cout << "Error! divide by zero";
    }
    else if (operation.expression == "+")
        operand1 += operand2;
    else if (operation.expression == "-")
        operand1 -= operand2;
    else
        cout << "Error! Operator is invalid";

    ss << operand1;
    return ss.str();
}

//infix to postfix conversion
void infix_to_postfix(const vector<inputStruct> vecInput)
{
    inputStruct input;
    vector<inputStruct> ans;
    stack<inputStruct> op;
    cout << "\nPostfix Expression is: ";

    for (auto i = vecInput.begin(); i != vecInput.end(); ++i)
    {
        inputStruct inputSt = *i;
        if (operandChecker(inputSt.expression))
        {
            cout << inputSt.expression << " ";
            
            if (inputSt.expression.length() > 0) 
            ans.push_back(inputSt.expression);
        }
        
        if (inputSt.expression == "(") 
        op.push(inputSt);
        
        else if (operatorChecker(inputSt.expression))
        {
            while (!op.empty() && op.top().expression != "(" && (op.top().precedence >= inputSt.precedence)) {
                
                cout << op.top().expression << " ";
                
                ans.push_back(op.top().expression);
                op.pop();
            }
            op.push(inputSt);
        }

        else if (inputSt.expression == ")")
        {
            if (operatorChecker(input.expression)) 
            cout << "Error! last input is operator";
            
            else
            {
                while (!op.empty() && op.top().expression != "(")
                {
                    cout << op.top().expression << " ";

                    ans.push_back(op.top().expression);
                    op.pop();
                }
                op.pop();
            }
        }
        input = inputSt;
    }

    if (operatorChecker(input.expression) || input.expression == "(") 
    cout << "Error! last input is operator";
    
    else
    {
        while (!op.empty())
        {
            if (op.top().expression == "(") { 
            cout << "paranthesis does not match";
            break;
            }
            cout << op.top().expression << " ";
            ans.push_back(op.top().expression);
            op.pop();
        }
        cout << endl;
    }
    postfix_to_ans(ans);
}

//postfix to answer
void postfix_to_ans(std::vector<inputStruct> vec)
{
    string ans;
    bool flag = false;
    stack<string> operand;
   
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        inputStruct inputSt = *i;
        ans += inputSt.expression + " ";

        if (!flag && isNum(inputSt.expression))
        {
            if (operandChecker(inputSt.expression)) 
            operand.push(inputSt.expression);
            
            else if (operatorChecker(inputSt.expression))
            {
                if (operand.size() < 2) 
                cout << "Error! less than two operands";
                else
                {
                    inputStruct operand1 = operand.top();
                    operand.pop();
                    inputStruct operand2 = operand.top();
                    operand.pop();

                    string result = evaluate(operand2, operand1, inputSt.expression);
                    operand.push(result);
                }
            }
        }
        else flag = true;
    }

    if (!flag)
    {
        if (operand.size() > 1) 
        cout << "One or more operands are still in the stack";

        else if (operand.size() == 1) 
        cout << "Postfix Evaluation is: " << ans << "=" << operand.top() << endl;
        else 
        cout << "Postfix Evaluation is: 0" << endl;
    }

    else
    cout << "Postfix Evaluation is: " << ans << "= " << ans << endl;
}
