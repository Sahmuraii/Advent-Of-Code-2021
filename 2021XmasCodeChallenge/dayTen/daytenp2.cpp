/// @file pa18a.cpp
/// @author William Veric
/// @date 07/25/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief An program that demonstrates the use of the Stack.hpp template
/// class.

// Include Statements
#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <algorithm>

void PrintStack(std::stack<char> s);

// Using namespace statement
// using namespace std;

/// ---------------------------------------------------------------------------
/// Start of the program. Checks to see if a given expression has balanced
/// delimiters. Returns YES if the expression is balanced. Returns NO and the
/// position of the error if the expression is non-balanced.
/// @return 0.
/// --------------------------------------------------------------------------
int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        std::cout << "Usage: ./pa18a 'EXPRESSION' " << std::endl;
    }
    else
    {
        std::vector<long long> sums;
        std::vector<char> invalidChars;
        std::ifstream file(argv[1]);
        bool flag; // Holds if the expression is currently balanced.

        int length;
        std::string exp;
        int errorPos = 1;
        long long sum;
        int line;

        while (getline(file, exp, '\n'))
        {
            exp.erase(exp.length() - 1);
            length = exp.length(); // Stores length of expression.
            flag = true;
            std::stack<char> stack;
            errorPos = 1;
            sum = 0;
            line++;

            for (int i = 0; i < length && flag == true; i++)
            {
                switch (exp[i])
                {
                case '(':
                case '[':
                case '{':
                case '<':
                    stack.push(exp[i]);
                    break;
                case ')':
                    if (stack.top() != '(')
                    {
                        flag = false;
                        errorPos = i;
                    }
                    else
                    {
                        stack.pop();
                    }
                    break;
                case ']':
                    if (stack.top() != '[')
                    {
                        flag = false;
                        errorPos = i;
                    }
                    else
                    {
                        stack.pop();
                    }
                    break;
                case '}':
                    if (stack.top() != '{')
                    {
                        flag = false;
                        errorPos = i;
                    }
                    else
                    {
                        stack.pop();
                    }
                    break;
                case '>':
                    if (stack.top() != '<')
                    {
                        flag = false;
                        errorPos = i;
                    }
                    else
                    {
                        stack.pop();
                    }
                    break;
                default:
                    break;
                }
            }

            if (stack.empty() == true && flag == true)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                if(errorPos != length && errorPos != 1) {
                    invalidChars.push_back(exp[errorPos]);
                } else if (errorPos == 1) {
                    if(line == 101) {
                        stack.pop();
                    }
                    
                    while(!stack.empty()) {
                        std::cout << sum << '\n';
                        if(stack.top() == '(') {
                            sum *= 5;
                            sum += 1;
                            stack.pop();
                        } else if(stack.top() == '[') {
                            sum *= 5;
                            sum += 2;
                            stack.pop();
                        } else if(stack.top() == '{'){
                            sum *= 5;
                            sum += 3;
                            stack.pop();
                        } else if(stack.top() == '<') {
                            sum *= 5;
                            sum += 4;
                            stack.pop();
                        } //end of if statement
                    } // end of while loop
                    sums.push_back(sum);
                } // end of else if
            } // end of else 
        } // end of while

        sort(sums.begin(), sums.end());

        for(int i = 0; i < sums.size(); i++){
            std::cout << "I: " << i << " SUM: " << sums[i] << '\n';
        }

        std::cout << sums[sums.size() / 2] << '\n';

    }// else
    return 0;
}// main

void PrintStack(std::stack<char> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Print the stack element starting
    // from the bottom
    std::cout << x << " ";

    PrintStack(s);
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}