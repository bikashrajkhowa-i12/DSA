/*
You are given a valid arithmetic expression in prefix notation. Your task is to convert it \
into a fully parenthesized infix expression.
Prefix notation (also known as Polish notation) places the operator before its operands.
In contrast, infix notation places the operator between operands.

Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

Example:
Input:
 expression = "*+ab-cd
Output:
 ((a+b)*(c-d))

*/
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// TC: O(n); SC: O(n)
string prefix_to_infix(string prefix)
{
    stack<string> st;
    int i = prefix.length() - 1;

    while (i >= 0)
    {
        if (prefix[i] == ' ')
        {
            i--;
            continue;
        }

        // operand
        if (isalnum(prefix[i]))
        {
            st.push(string(1, prefix[i]));
        }
        else
        {
            string c1 = st.top();
            st.pop();

            string c2 = st.top();
            st.pop();

            st.push("(" + c1 + prefix[i] + c2 + ")");
        }
        i--;
    }

    return st.top();
}

int main()
{
    string prefix = "*+ab-cd";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefix_to_infix(prefix);
}