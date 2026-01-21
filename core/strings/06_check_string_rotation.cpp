/*
Given two strings s and goal, return true if and only if s can become
goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the
rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.

Example:
Input:
 s = "rotation", goal = "tionrota"
Output:
 true
Explanation:
 After multiple left shifts on "rotation", we get:
    1st shift → "otationr"
    2nd shift → "tationro"
    3rd shift → "ationrot"
    4th shift → "tionrota"
    So the goal string can be obtained by rotating the original string.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force TC: O(n^2), SC: O(n)
bool check_rotated_strings(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    for (int i = 0; i < s.length(); i++) // O(n) times
    {
        string rotated = s.substr(i) + s.substr(0, i); // O(n) for new substring

        if (rotated == goal)
            return true;
    }
    return false;
}

// optimized. TC: O(n); SC: O(1)
bool optimized_rotated_strings(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    return (s + s).find(goal) != string::npos;
}

int main()
{
    string s = "rotation";
    string goal = "tationro";

    cout << "Are both rotated strings: " << boolalpha << check_rotated_strings(s, goal) << endl;
    cout << "Are both rotated strings: " << boolalpha << optimized_rotated_strings(s, goal) << endl;
}
