/*
You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M'
denote the number of rows and columns, respectively. The elements of each
row are sorted in non-decreasing order. Moreover, the first element of a
row is greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists
in the given 'mat' or not.

Examples
Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output :True.
Explanation :The target = 8 exists in the 'mat' at index (1, 3).
*/

/*
Type-1 matrix
apply -> low = 0, high = n*m - 1;
row = mid/m;
col = mid%2;
if(arr[row][col] == target) -> return;
else if(arr[row][col] > target) -> high = mid - 1;
else -> low = mid + 1;
*/

#include <bits/stdc++.h>
using namespace std;

// brute force: traverse 2 for loops for n and m resp. and check mat[i][j] == target
//  TC: O(n*m); SC: O(1)

// better: traverse for n rows, for each row apply binary search
//  TC: O(n*logm); SC: O(1)

// optimized: since the matrix is fully-sorted rows and columns properly,
// apply the binary search directly by flattening the matrix.
// TC: O(log(n*m)); SC: O(1)
bool check_target(vector<vector<int>> &mat, int n, int m, int target)
{
    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    int target;
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Enter a target to search: ";
    cin >> target;

    cout << "Exists? -> " << boolalpha << check_target(mat, mat.size(), mat[0].size(), target);
}
