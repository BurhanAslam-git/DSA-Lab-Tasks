#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }

    else if (op == '*' || op == '/')
    {
        return 2;
    }

    else if (op == '+' || op == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }

        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

void evaluateExpressions(string str)
{
    if (str == "")
        return;

    stack<int> exp;
    int res = 0;
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        // if it is a digit.
        if (str[i] >= 48 && str[i] <= 57)
        {
            exp.push(int(str[i]) - 48);

        }

        // if it is an operator.
        else if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '-')
        {
            int num1 = exp.top();
            exp.pop();
            int num2 = exp.top();
            exp.pop();

            if (str[i] == '+')
            {
                res = num2 + num1;
            }

            else if (str[i] == '*')
            {
                res = num2 * num1;
            }

            else if (str[i] == '/')
            {
                res = num2 / num1;
            }

            else if (str[i] == '-')
            {
                res = num2 - num1;
            }

            exp.push(res);
        }
    }

    cout << "The answer is: " << res << endl;
}

    int main()
    {
        string infix_exp;
        cout << "Enter infix expression: ";
        getline(cin, infix_exp);

        string postfix_exp = infixToPostfix(infix_exp);
        cout << "Postfix expression: " << postfix_exp << endl;

        evaluateExpressions(postfix_exp);

        return 0;
    }

