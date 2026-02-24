#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// TC: O(n); SC: O(n)
string postfix_to_prefix(const string &postfix)
{
    stack<string> st;

    for (char ch : postfix)
    {
        if (ch == ' ')
            continue;

        // operand
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        // operator
        else
        {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();

            string res = string(1, ch) + left + right;
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string postfix = "ab+cd-*"; // predefined valid postfix
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix : " << postfix_to_prefix(postfix) << endl;
}
