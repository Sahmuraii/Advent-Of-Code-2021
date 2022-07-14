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
        std::vector<char> invalidChars;
        std::ifstream file(argv[1]);
        bool flag; // Holds if the expression is currently balanced.

        int length;
        std::string exp;
        int errorPos = 1;
        int sum = 0;

        while (getline(file, exp, '\n'))
        {
            exp.erase(exp.length() - 2);
            // std::cout << "EXPRESSION: " << exp << '\n';
            length = exp.length() - 1; // Stores length of expression.
            // std::cout << "LENGTH: " << length << '\n';
            flag = true;
            std::stack<char> stack;
            errorPos = 1;

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
                // std::cout << errorPos << '\n';
                if(errorPos != length && errorPos != 1) {
                    invalidChars.push_back(exp[errorPos]);
                } // if
            } // if
        }// while

    for(int i = 0; i < invalidChars.size(); i++){
        if(invalidChars[i] == ')') 
        {
            sum += 3;
        } 
        else if(invalidChars[i] == ']') 
        {
            sum += 57;
        }
        else if(invalidChars[i] == '}')
        {
            sum += 1197;
        }
        else if(invalidChars[i] == '>')
        {
            sum += 25137;
        }
    }

    std::cout << sum << '\n';

    }// else
    return 0;
}// main