/*
Given a row-wise sorted matrix of size M*N, where M is no. of rows
and N is no. of columns, find the median in the given matrix.
Note: M*N is odd.

Examples
Input: M = 3, N = 3, matrix[][] =

1 4 9
2 5 6
3 7 8
Output: 5
Explanation:
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5
*/

#include <bits/stdc++.h>
using namespace std;

// brute force. TC: O(n*m + (log(n*m))); SC: O(n*m);
int brute_median(vector<vector<int>> &mat, int n, int m)
{
    vector<int> list;

    // single list {}
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            list.push_back(mat[i][j]);
        }
    }

    // sort -> list
    sort(list.begin(), list.end());

    return list[(n * m) / 2];
}

/*
*******Core Concept: Binary Search on Answer (Value Space)********
You are NOT searching indices.
You are searching the value that could be the median.

Define the answer range:
low = minimum element in matrix
high = maximum element in matrix

Pick a middle value:
mid = (low + high) / 2


Count elements ≤ mid
count = Σ upper_bound(row, mid)


Decide direction:
If count ≤ half → median is bigger
If count > half → median is smaller or equal

Repeat until low == high
*/
int upperBound(vector<int> &arr, int target)
{
    int res = arr.size();
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int optimized_median(vector<vector<int>> &mat, int n, int m)
{
    int low = mat[0][0];
    int high = mat[n - 1][m - 1];

    // find min and max in matrix
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += upperBound(mat[i], mid);
        }

        if (count <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 4, 9},
        {2, 5, 6},
        {3, 7, 8}};

    cout << "Median (brute-force) is: " << brute_median(mat, mat.size(), mat[0].size()) << endl;
    cout << "Median (optimized) is: " << optimized_median(mat, mat.size(), mat[0].size());
}