/*
Given a decimal value x. Convert it into binary.

Input: 1101
Output: 13
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log base2 * n); SC: O(log base2 * n)
int convert_to_decimal(string s)
{
    if (s.length() == 0)
        return 0;

    int num = 0;
    int pow2 = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            num = num + pow2;
        }

        pow2 = pow2 * 2;
    }
    return num;
}

int main()
{
    string s = "0110"; // 6
    cout << "Decimal of " << s << " is: " << convert_to_decimal(s);
}