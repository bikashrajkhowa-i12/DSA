/*
Given a binary value, find 2's compliment
*/

#include <iostream>
using namespace std;

// TC: O(n*n); SC: O(1)
string twos_compliment(string s)
{
    if (s.length() == 0)
        return "";

    // Step 1: Invert original
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = s[i] == '0' ? '1' : '0';
    }

    // Step 2: Add 1
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            break;
        }
        else
        {
            s[i] = '0';
        }
    }

    return s;
}

int main()
{
    string s = "1101"; // 0011
    cout << "1's compliment of " << s << " is: " << twos_compliment(s);
}