/*
 You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote
 the number of rows and columns, respectively. The elements of each row and each
 column are sorted in non-decreasing order. But, the first element of a row is
 not necessarily greater than the last element of the previous row (if it exists).
 You are given an integer ‘target’, and your task is to find if it exists in the
 given 'mat' or not.

Examples
Example 1:
Matrix=
1   4   7
3   6   9
4   20  31
Target: 9
Output: Found at (1,2) (0-indexed)
*/

#include <bits/stdc++.h>
using namespace std;

// optimized. TC:O(n+m) SC: O(1)
pair<int, int> get_coordinates(vector<vector<int>> &mat, int n, int m, int target)
{
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (mat[row][col] == target)
            return {row, col};
        else if (mat[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return {-1, -1};
}

int main()
{
    int target;
    vector<vector<int>> mat = {
        {1, 4, 7},
        {3, 6, 9},
        {4, 20, 31}};
    cout << "Enter your target: ";
    cin >> target;

    pair<int, int> coordinates = get_coordinates(mat, mat.size(), mat[0].size(), target);

    if (coordinates.first == -1 || coordinates.second == -1)
    {
        cout << "Not found!";
    }
    else
    {
        cout << "Found at: (" << coordinates.first << ", " << coordinates.second << ")";
    }
}