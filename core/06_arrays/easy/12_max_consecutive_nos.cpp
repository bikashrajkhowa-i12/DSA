/*
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array..

Examples
Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Example 2:
Input: prices = {1, 0, 1, 1, 0, 1}
Output: 2
Explanation: There are two consecutive 1's in the array.
*/

/*
i = 0 to n-1;

*/
#include <bits/stdc++.h>
using namespace std;

// TC: O(n); SC: O(1)
void max_consecutive_nos(vector<int> &arr, int n)
{
    int counter = 0;
    int maxCon1s = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            counter += 1;
        }
        else
        {
            counter = 0;
        }

        maxCon1s = max(maxCon1s, counter);
    }

    cout << "Maximum consecutive 1s are: " << maxCon1s;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1}; // op: 4

    max_consecutive_nos(arr, arr.size());
}
