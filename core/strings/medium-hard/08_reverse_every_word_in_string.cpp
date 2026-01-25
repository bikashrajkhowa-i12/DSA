/*
Given a string s, reverse every word. Reduce mutiple spaces to one ' ',

Example: " welcome to   the jungle "
Output: "elgnuj eht ot emoclew"
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n); SC: O(n)
string reverse_string(string s)
{
    string rev = "";
    vector<string> rev_arr;
    string word = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (c == ' ')
        {
            if (!word.empty())
            {
                rev_arr.push_back(word);
                word = "";
            }
        }
        else
        {
            word += c;
        }
    }

    for (int i = 0; i < rev_arr.size(); i++)
    {
        rev += i == rev_arr.size() - 1 ? rev_arr[i] : rev_arr[i] + " ";
    }
    return rev;
}

int main()
{
    string s = " welcome to   the jungle  ";
    cout << "Reverse string is: " << reverse_string(s);
}
