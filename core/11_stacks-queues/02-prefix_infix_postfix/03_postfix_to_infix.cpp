/*
Given a postfix expression, convert it into infix.

Exaample: abcd^e-fgh*+^*+i-
Output: a+b*(c^d-e)^(f+g*h)-i
*/

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// TC: O(n); SC: O(n)
string postfix_to_infix(string postfix)
{
    stack<string> st;
    int i = 0;
    while (i < postfix.length())
    {
        if (postfix[i] == ' ')
        {
            i++;
            continue;
        }
        // operand
        else if (isalnum(postfix[i]))
        {
            st.push(string(1, postfix[i]));
        }
        // operator
        else
        {
            string c1 = st.top();
            st.pop();

            string c2 = st.top();
            st.pop();

            st.push("(" + c2 + postfix[i] + c1 + ")");
        }

        i++;
    }
    return st.top();
}

int main()
{
    string postfix = "abcd^e-fgh*+^*+i-";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfix_to_infix(postfix);
}