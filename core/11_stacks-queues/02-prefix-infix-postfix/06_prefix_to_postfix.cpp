#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// TC: O(n); SC: O(n)
string prefix_to_postfix(const string &prefix)
{
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

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
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();

            string res = left + right + string(1, ch);
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string prefix = "*+ab-cd"; // predefined valid prefix
    cout << "Prefix : " << prefix << endl;
    cout << "Postfix: " << prefix_to_postfix(prefix) << endl;
}
