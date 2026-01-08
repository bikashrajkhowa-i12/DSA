/*
 You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote
 the number of rows and columns, respectively. The elements of each row and each
 column are sorted in non-decreasing order. But, the first element of a row is not
 necessarily greater than the last element of the previous row (if it exists).
 You are given an integer ‘target’, and your task is to find if it exists in the
 given 'mat' or not.

Examples
Example 1:
Matrix=
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
Target: 9
Output: Found at (2,2) (0-indexed)
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
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}};

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