/*
Given an input string, containing upper-case and lower-case letters,
digits, and spaces( ' ' ). A word is defined as a sequence of non-space
characters. The words in s are separated by at least one space. Return
a string with the words in reverse order, concatenated by a single space.

Examples
Input: s = "welcome to the jungle"
Output: "jungle the to welcome"
*/

#include <bits/stdc++.h>
using namespace std;

// brute force; TC: O(N), SC:O(N)
string brute_rev_str(string s)
{
    vector<string> str_array;
    string str = "";
    string word = "";

    for (char ch : s)
    {
        if (ch == ' ')
        {
            str_array.push_back(word);
            word = "";
        }
        else
        {
            word += ch;
        }
    }
    if (!word.empty())
    {
        str_array.push_back(word);
    }

    reverse(str_array.begin(), str_array.end());

    for (int i = 0; i < str_array.size(); i++)
    {
        str += str_array[i]; // form the new reverse string

        if (i != str_array.size() - 1) // if its not the last word add a space
            str += " ";
    }

    return str;
}

// optimized; TC:O(N), SC:O(1)
string optimized_rev_str(string s)
{
    string rev = "";

    int i = s.length() - 1;

    while (i >= 0)
    {
        if (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int end = i;
        while (i >= 0 && s[i] != ' ')
            i--;

        string word = s.substr(i + 1, end - i);

        if (!rev.empty())
            rev += " ";
        rev += word;
    }

    return rev;
}

string reverse_full(string s)
{
    string revStr = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        revStr += s[i];
    }
    return revStr;
}

string optimized_rev_full(string s)
{
    if (s.length() < 1)
        return s;
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main()
{
    string str = "welcome to the jungle";
    cout << "Given string:" << str << endl;
    cout << "Reverse string(brute):" << brute_rev_str(str) << endl;
    cout << "Reverse string(optimized):" << optimized_rev_str(str) << endl;
    cout << "Reverse full-string: " << reverse_full(str) << endl;
    cout << "Reverse full-string(optimized): " << optimized_rev_full(str);
}
