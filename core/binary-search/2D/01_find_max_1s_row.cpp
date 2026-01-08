/*
You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s.
All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum
number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index.
If there's no row with at least 1 zero, return -1

Examples
Example 1:
Input Format: n = 3, m = 3,
mat[] =
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).
*/

#include <bits/stdc++.h>
using namespace std;

// brute force: traverse the entire n and m array and count the 1's.
// TC: O(n*m) SC: O(1)

// Optimal: Since its sorted, go with binary-search.
// TC: O(nlogm); SC: O(1)

int lower_bound(vector<int> &arr, int m, int target)
{
    int low = 0;
    int high = m - 1;
    int idx = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

int printIndex(vector<vector<int>> &arr, int n, int m)
{
    int count = 0;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        int total1s = m - lower_bound(arr[i], m, 1); // lowerbound of 1 or upperbound of 0
        if (total1s > count)
        {
            count = total1s;
            idx = i;
        }
    }

    return idx;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}};

    cout << "The index of the row with the maximum number of 1s is: " << printIndex(arr, arr.size(), arr[0].size());
}
