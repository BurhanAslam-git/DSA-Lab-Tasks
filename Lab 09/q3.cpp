#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr)
{
    if (expr == "")
    {
        return true;
    }
    stack<char> s;
    
    int length = expr.length();

    for (int i = 0; i < length; ++i)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            s.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s.empty())
                return false;
            char top = s.top();

            if ((expr[i] == ')' && top == '(') || (expr[i] == '}' && top == '{') || (expr[i] == ']' && top == '['))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression))
    {
        cout << "Balanced\n";
    }
    else
    {
        cout << "Not Balanced\n";
    }
    return 0;
}
