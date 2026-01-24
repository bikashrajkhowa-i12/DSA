/*
Problem Statement: Roman numerals are represented by seven different
symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
Roman numerals are usually written largest to smallest from left to right.
But in six special cases, subtraction is used instead of addition: I before
V or X → 4 and 9, X before L or C → 40 and 90, C before D or M → 400 and 900
Given a Roman numeral, convert it to an integer.

*****************Core concept******************
Roman numerals follow two rules:
Normal rule → bigger or equal value comes first → add

X V → 10 + 5

Exception rule (subtractive) → smaller value comes before bigger → subtract

I V → 5 - 1

So the entire problem reduces to this:

If current value < next value → subtract
Else → add
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n); SC: O(1);
int roman_to_integer(string s)
{
    if (s.length() == 0)
        return 0;

    unordered_map<char, int> ump = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char cur = s[i];
        char next = s[i + 1];

        if (i + 1 < s.length() && ump[cur] < ump[next])
        {
            res = res - ump[cur]; // substraction
        }
        else
        {
            res = res + ump[cur]; // addition (normal + last char)
        }
    }
    return res;
}

int main()
{
    string roman = "LVCD";
    cout << roman << " in integer: " << roman_to_integer(roman);
}