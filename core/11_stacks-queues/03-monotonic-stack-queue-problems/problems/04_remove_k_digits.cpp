/*
Given a string nums representing a non-negative integer, and an integer k,
find the smallest possible integer after removing k digits from num.

Examples
Example 1:
Input:
 nums = "541892", k = 2
Output:
 "1892"
Explanation:
 Removing the two digits 5 and 4 yields the smallest number, 1892.

Example 2:
Input:
 nums = "1002991", k = 3
Output:
 "21"
*/

#include <iostream>
#include <stack>
using namespace std;

/*APPROACH******
Core idea:
Remove larger digits that appear before smaller digits (left side matters more).

TC: O(n); SC: O(n)
*/
string smallest_number(string s, int k)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        while (!st.empty() && st.top() - '0' > s[i] - '0' && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // remove remaining digits if needed
    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    // build result string
    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    // remove leading zeros
    int pos = 0;
    while (pos < res.size() && res[pos] == '0')
        pos++;

    res = res.substr(pos);

    return res.empty() ? "0" : res;
}

int main()
{
    int k = 5;
    string s = "1250067256";
    cout << "Given number string: " << s;
    cout << endl
         << "Total digits to remove(k): " << k;
    cout << endl
         << "Smallest number after removing k digits: " << smallest_number(s, k);
}