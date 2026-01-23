/*
You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
If two or more characters have same frequency then arrange them in alphabetic order.

Example:
Input:
 s = "tree"
Output:
 ['e', 'r', 't']
*/

#include <bits/stdc++.h>
using namespace std;

// optimal. TC: O(n + k log k )
string sort_by_freq(string s)
{
    if (s.length() == 0)
        return "";

    unordered_map<char, int> ump;
    vector<pair<char, int>> arr;
    string result = "";

    // count frequency... { t:1, r:1, e:2 }; ---> TC:O(n)
    for (char c : s)
    {
        ump[c]++;
    }

    // push into vector pairs...[(t,1),(r,1),(e,2)]; ---> TC:O(k)
    for (auto &it : ump)
    {
        arr.push_back({it.first, it.second});
    }

    // sort by freq (custom) ---> TC:O(k log k)
    sort(arr.begin(), arr.end(), [](const pair<char, int> &a, const pair<char, int> &b)

         { return a.second > b.second; });

    // append the string ---> TC:O(n)
    for (auto &it : arr)
    {
        result.append(it.second, it.first);
    }

    return result;
}

int main()
{
    string str = "ttttree";

    cout << "Unique characters are (brute-force): " << sort_by_freq(str);
    ;
}
