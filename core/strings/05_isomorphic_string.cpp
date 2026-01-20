/*
Given two strings s and t, determine if they are isomorphic. Two strings s and t
are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same character,
but a character may map to itself.

***Example***
Input:
 s = "paper", t = "title"
Output:
 true
Explanation:
 The characters in "s" can be mapped one-to-one to characters in "t":
'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
Since the mapping is consistent and unique for each character, the strings are isomorphic.
*/

/*******APPROACH*******
 * if s1.length != s2.length -> false
 * unordered_map<char, char> ump1;
 * unordered_map<char, char> ump2;
 * for(i<s1.length){
 *  if ump1.find(s1[i]) != ump1.end() && ump1[s1[i]] != s2[i] -> return false
 *  if ump2.find(s1[i]) != ump2.end() && ump2[s1[i]] != s1[i] -> return false
 *  else -> ump1[s1[i]] = s2[i]; ump2[s2[i]] = s1[i];
 * }
 * return true;
 */

#include <bits/stdc++.h>
using namespace std;

bool is_isomorphic(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    unordered_map<char, char> s1_to_s2;
    unordered_map<char, char> s2_to_s1;

    for (int i = 0; i < s1.length(); i++)
    {
        char c1 = s1[i];
        char c2 = s2[i];

        auto it1 = s1_to_s2.find(c1);
        if (it1 != s1_to_s2.end() && s1_to_s2[c1] != c2)
        {
            return false;
        }

        auto it2 = s2_to_s1.find(c2);
        if (it2 != s2_to_s1.end() && s2_to_s1[c2] != c1)
        {
            return false;
        }

        s1_to_s2[c1] = c2;
        s2_to_s1[c2] = c1;
    }
    return true;
}

int main()
{
    string str1 = "title";
    string str2 = "paper";

    cout << "Is isomorphic strings: " << boolalpha << is_isomorphic(str1, str2);
}
