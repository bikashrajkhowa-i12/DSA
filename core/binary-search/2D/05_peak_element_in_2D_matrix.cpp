/*
 Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

Examples
Example 1:
Input:
 mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
Output:
 [1, 1]
Explanation:
 The value at index [1, 1] is 25, which is a peak because all its neighbors (10, 7, 4, 9) are smaller.
*/

/*
******************Core Idea (the entire trick)********************
In a 2D matrix with no duplicates, you can always discard half of the columns (or rows)
by looking at the maximum element in a middle column and comparing it with its neighbors.
1. First pick the mid(cols)
2. Pick index of the highest element in the mid(i.e, index > up && index > down)
3. Then compare left and right ( index > left && index > right)
4. If left/right is > index, move center to that direction(col++/col--)
5. Eventually mid will be he peak.
*/
#include <bits/stdc++.h>
using namespace std;

// brute-force. TC: O(n*m) SC: O(1)
pair<int, int> peak_coordinates(vector<vector<int>> &mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr = mat[i][j];

            bool up = (i == 0) || curr > mat[i - 1][j];
            bool down = (i == n - 1) || curr > mat[i + 1][j];
            bool left = (j == 0) || curr > mat[i][j - 1];
            bool right = (j == m - 1) || curr > mat[i][j + 1];

            if (up && down && left && right)
                return {i, j};
        }
    }
    return {-1, -1};
}

int maxIndex(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

pair<int, int> optimized_peak(vector<vector<int>> &mat, int n, int m)
{
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRowIdx = maxIndex(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIdx][mid + 1] : -1;

        // if center > left && center > right
        if (mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right)
        {
            return {maxRowIdx, mid};
        }
        else if (mat[maxRowIdx][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {5, 10, 8},
        {4, 25, 7},
        {3, 9, 6}};

    cout << "Brute-force Peak element co-ordinates: "
         << peak_coordinates(mat, mat.size(), mat[0].size()).first << ", "
         << peak_coordinates(mat, mat.size(), mat[0].size()).second << endl;

    cout << "Optimized peak element co-ordinates: "
         << optimized_peak(mat, mat.size(), mat[0].size()).first << ", "
         << optimized_peak(mat, mat.size(), mat[0].size()).second;
}
