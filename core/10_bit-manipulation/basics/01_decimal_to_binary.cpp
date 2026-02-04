/*
Given a decimal value x. Convert it into binary.

Input: 13
Output: 1101
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log base2 * n); SC: O(log base2 * n)
string convert_to_binary(int x)
{
    if (x == 0)
        return "0";

    string res = "";

    while (x > 0)
    {
        if (x % 2 == 1)
            res += '1';
        else
            res += '0';

        x = x / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int x = 13; // 1101
    cout << "Binary of " << x << " is: " << convert_to_binary(x);
}