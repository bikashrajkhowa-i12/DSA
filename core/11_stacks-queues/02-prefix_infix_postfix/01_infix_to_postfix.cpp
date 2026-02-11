/*
Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

Examples
Example 1:
Input:
 a + b * (c^d - e) ^ (f + g * h) - i
Output:
 abcd^e-fgh*+^*+i-
*/

#include <iostream>
#include <stack>

using namespace std;

int priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// TC: O(n); SC: O(n)
string infix_to_postfix(string infix)
{
    stack<char> st;
    string postfix = "";
    int i = 0;

    while (i < infix.size())
    {
        // if its a operand => append into the postfix output string
        if (
            (infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }
        // for brackets and operators
        else if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // to pop the '('
        }
        // check precedence(priority)
        else
        {
            while (!st.empty() && priority(infix[i]) <= priority(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        i++;
    }

    // add whatever is left in the stack to the postfix expression
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infix_to_postfix(infix);
    return 0;
}