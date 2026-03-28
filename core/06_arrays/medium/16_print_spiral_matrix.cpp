/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
    Input: [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]
    Output: [1,2,3,6,9,8,7,4,5]

Example 2:
    Input: [
        [1,2,3,4],
        [5,6,7,8],
        [9,10,11,12]
    ]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

void print_2d_matrix(const vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    if (n == 0)
        cout << "[]";
    else if (n == 1)
        return print_matrix(mat[0]);

    cout << "[\n";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1)
                cout << mat[i][j] << "]";
            else
                cout << mat[i][j] << ",";
        }
        if (i == n - 1)
            cout << ",\n]";
        else
            cout << ", \n";
    }
    return;
}

/*
    TC: O(n * m) // touching each and every element
    SC: O(n * m) // storing all elements in spiral order
*/
vector<int> spiral_matrix(vector<vector<int>> &mat)
{
    vector<int> spiralMat;
    if (mat.empty())
        return spiralMat;

    int m = mat.size();    // number of rows
    int n = mat[0].size(); // number of columns

    int left = 0, right = n - 1, top = 0, bottom = m - 1;

    while (left <= right && top <= bottom)
    {
        // traverse top row
        for (int i = left; i <= right; i++)
            spiralMat.push_back(mat[top][i]);
        top++;

        // traverse right column
        for (int i = top; i <= bottom; i++)
            spiralMat.push_back(mat[i][right]);
        right--;

        // traverse bottom row if still within bounds
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                spiralMat.push_back(mat[bottom][i]);
            bottom--;
        }

        // traverse left column if still within bounds
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                spiralMat.push_back(mat[i][left]);
            left++;
        }
    }

    return spiralMat;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "Given matrix: ";
    print_2d_matrix(mat);
    cout << endl
         << "Spiral matrix: ";
    print_matrix(spiral_matrix(mat));
    return 0;
}