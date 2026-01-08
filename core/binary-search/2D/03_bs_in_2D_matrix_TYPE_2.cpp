/*
 You have been given a 2-D array mat of size N × M, where:

• Each row of the matrix is sorted in non-decreasing order
• There is NO guarantee that columns are sorted
• The first element of a row is not necessarily greater than the last element of the previous row

You are given an integer target.
Your task is to determine whether target exists in the matrix or not, and return its coordinates if found.

Examples
Example 1:
Matrix=
1   4   7   11
3   6   9   16
10  13  14  17
2   5   8   12
Target: 9
Output: Found at (1,2) (0-indexed)
*/

#include <bits/stdc++.h>
using namespace std;

// brute-force is traversing n*m elements and checking.. TC: O(n*m); SC: O(1)

// optimized: TC: O(n*logm); SC: O(1)
int bs(vector<int> &mat, int m, int target)
{
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mat[mid] == target)
        {
            return mid;
        }
        else if (mat[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

pair<int, int> print_coordinates(vector<vector<int>> &mat, int n, int m, int target)
{
    for (int row = 0; row < n; row++)
    {
        int col = bs(mat[row], m, target);
        if (col != -1)
            return {row, col};
    }
    return {-1, -1};
}

int main()
{
    int target;
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {3, 6, 9, 16},
        {10, 13, 14, 17},
        {2, 5, 8, 12},
    };

    cout << "Enter a target to be searched: ";
    cin >> target;

    pair<int, int> coordinates = print_coordinates(mat, mat.size(), mat[0].size(), target);

    if (coordinates.first == -1 || coordinates.second == -1)
    {
        cout << "Not found!";
    }
    else
    {
        cout << "Found at (" << coordinates.first << ", " << coordinates.second << ")";
    }
}