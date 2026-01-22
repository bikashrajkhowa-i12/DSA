/*
A valid parentheses string is defined by the following rules:

It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.

A primitive valid parentheses string is a non-empty valid string that
cannot be split into two or more non-empty valid parentheses strings.

Given a valid parentheses string s, your task is to remove the outermost
parentheses from every primitive component of s and return the resulting string.

Example:
Input:
 s = "((()))"
Output:
 "(())"
Explanation:
 The input string is a single primitive: "((()))".
Removing the outermost layer yields: "(())".
*/

/******************APPROACH*******************
For '(': Increase depth after. Keep it only if depth > 0 before entering
For ')': Decrease depth before. Keep it only if depth > 0 after leaving

*/
#include <bits/stdc++.h>
using namespace std;

string removeParanthesis(string str)
{
    string newStr = "";
    int level = 0;

    if (str.length() < 2)
        return str;

    for (char ch : str)
    {
        if (ch == '(')
        {
            if (level > 0)
                newStr += ch;
            level++;
        }
        else if (ch == ')')
        {
            level--;
            if (level > 0)
                newStr += ch;
        }
    }

    return newStr;
}

int main()
{
    string str = "(((())))";
    cout << "Input string: " << str << endl;
    cout << "Removed paranthesis: " << removeParanthesis(str);
}