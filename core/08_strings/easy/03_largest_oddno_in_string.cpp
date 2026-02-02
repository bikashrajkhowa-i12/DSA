/*
Given a string s, representing a large integer, the task is to
return the largest-valued odd integer (as a string) that is a
substring of the given string s.
The number returned should not have leading zero's. But the
given input string may have leading zero.

Example 1:
Input:
 s = "5347"
Output:
 "5347"
Explanation:
 The odd numbers formed by the given string are → 5, 3, 53, 347, 5347.
 The largest odd number without leading zeroes is 5347.

Example 2:
 Input:
 s = "0214638"
Output:
 "21463"
Explanation:
 The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463.
 We can't use numbers starting with 0, so the largest valid odd number is 21463.
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N); SC:O(1)
string max_odd(string s)
{
    int idx = -1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int num = (s[i] - '0') % 2;
        if (num > 0)
        {
            idx = i;
            break;
        }
    }

    string res = s.substr(0, idx + 1);
    int pos = 0;
    while (res.length() > 0 && res[pos] == '0')
    {
        pos++;
    }

    return res.substr(pos);
}

int main()
{
    string s = "0500347";
    cout << "Largest valid odd number is: " << max_odd(s);
}