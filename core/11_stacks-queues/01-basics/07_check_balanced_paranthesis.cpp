/*
Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']',
check if the input string is valid and return true if the string is balanced otherwise return false. .

Note:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Examples
Example 1:
Input: str = “( )[ { } ( ) ]”
Output: True
Explanation: As every open bracket has its corresponding close bracket.
Match parentheses are in correct order hence they are balanced.


Example 2:
Input: str = “[ ( )”
Output: False
Explanation: As ‘[‘ does not have ‘]’ hence it is not valid and will return false.

*/

#include <iostream>
#include <stack>

using namespace std;

// TC: O(N); SC: O(N)
bool check_valid_paranthesis(string s)
{
    stack<char> st;

    for (auto &it : s)
    {
        if (it == '[' || it == '{' || it == '(')
        {
            st.push(it);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();

            if ((ch == '(' && it == ')') ||
                (ch == '{' && it == '}') ||
                (ch == '[' && it == ']'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty(); // true if everything is cleared
}

int main()
{
    string str = "[({})]";
    cout << "Is valid paranthesis? " << boolalpha << check_valid_paranthesis(str);
}