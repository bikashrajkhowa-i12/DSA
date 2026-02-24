/*
Convert infix expression to prefix expression.

Example:
Input : x + y * z / w + u
Output: ++x/*yzwu
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Reverse string and swap brackets
string reverseStr(string &s)
{
    reverse(s.begin(), s.end());

    for (char &c : s)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    return s;
}

// Operator precedence
int priority(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// TC: O(n); SC: O(n)
//  Convert infix to prefix
string infix_to_prefix(string &infix)
{
    stack<char> st;
    string postfix;

    // Step 1: reverse infix and swap brackets
    string revInfix = reverseStr(infix);

    for (int i = 0; i < revInfix.size(); i++)
    {
        char ch = revInfix[i];

        // ignore spaces
        if (ch == ' ')
            continue;

        // operand
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }
        // closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            // pop the '('
            if (!st.empty())
                st.pop();
        }
        // operator
        else
        {
            while (!st.empty() &&
                   (priority(st.top()) > priority(ch) ||
                    (priority(st.top()) == priority(ch) && ch == '^')))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // pop remaining operators
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    // Step 3: reverse postfix → prefix
    return reverseStr(postfix);
}

int main()
{
    string infix = "(a+b)*c-d+f*g-h";

    cout << "Infix  : " << infix << endl;
    cout << "Prefix : " << infix_to_prefix(infix) << endl;

    return 0;
}
