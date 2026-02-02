/*
Given two strings, check if two strings are anagrams of each other or not.
String are called anagrams if boths strings contains the same number of letters and same letters but may
contain different order.

Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT
Output: false
Explanation: Since the count of U and T  is not equal in both strings.

*/

#include <bits/stdc++.h>
using namespace std;

// brute-force; TC: O(nlogn); SC:O(1)
bool brute_check_anagrams(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

// optimized; TC: O(n); SC: O(1)
bool optimized_check_anagrams(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int freq[26] = {};

    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'A']++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        freq[s2[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s1 = "CAT ALSK";
    string s2 = "TCA LAKS";

    cout << "Are strings anagrams(brute) ? " << boolalpha << brute_check_anagrams(s1, s2) << endl;
    cout << "Are strings anagrams(optimized) ? " << boolalpha << optimized_check_anagrams(s1, s2);
}
