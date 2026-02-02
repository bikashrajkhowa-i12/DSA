/*
Given a valid parentheses string s, return the nesting depth of s.
The nesting depth is the maximum number of nested parentheses.

Example:
Input:
 s = "(1+(2*3)+((8)/4))+1"
Output:
 3
Explanation:
 Digit 8 is inside of 3 nested parentheses in the string.
*/

/*Approach
max_depth = 0;
depth = 0;
for(char c in s)
if(c == '(') -> depth++;
else if(c == ')')depth--;
max_depth = max(max_depth, depth);
return max_depth;
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n); SC:O(1)
int max_nesting_depth(string s)
{
    if (s.length() == 0)
        return 0;

    int max_depth = 0;
    int depth = 0;

    for (char c : s)
    {
        if (c == '(')
            depth++;
        else if (c == ')')
            depth--;

        max_depth = max(depth, max_depth);
    }
    return max_depth;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Max nesting depth: " << max_nesting_depth(s);
}
