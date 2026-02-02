/*
Write a function to find the longest common prefix string amongst
an array of strings. If there is no common prefix, return an empty string "".
*/

/************APPROACH***********
Longest common prefix amongst array of strings -> means each string will start with the same
If atleast one string word doesn't match return ""
Valid -> {"flower", "flow", "flight"}
Invalid -> {"flower", "flow", "banana"}
*/
#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n*m); SC: O(1)
string longest_common_prefix(vector<string> &s)
{
    if (s.size() == 0)
        return "";

    sort(s.begin(), s.end());

    string first = s[0];
    string last = s[s.size() - 1];

    int i = 0;
    while (i < first.size() && first[i] == last[i])
    {
        i++;
    }

    if (i == 0)
        return "";
    return first.substr(0, i);
}

int main()
{
    vector<string> str = {"flower", "flow", "flight"};

    cout << "Longest common prefix: " << longest_common_prefix(str);
}
