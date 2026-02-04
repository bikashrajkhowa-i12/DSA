/*
Given a binary value, find 1's compliment
*/

#include <iostream>
using namespace std;

string ones_compliment(string s)
{
    if (s.length() == 0)
        return "";

    // mutating the original string
    // use seperate variable incase of new string
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    return s;
}

int main()
{
    string s = "1101";
    cout << "1's compliment of " << s << " is: " << ones_compliment(s);
}