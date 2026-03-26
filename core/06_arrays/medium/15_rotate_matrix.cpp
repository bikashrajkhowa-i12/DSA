/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
    Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

#include <iostream>
#include <vector>

using namespace std;

void print_matrix(const vector<vector<int>> &mat)
{
    int n = mat.size();

    if (n == 0)
        cout << "[]";

    cout << "[\n";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
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

/* brute-force
    TC: O(n*n)
    SC: O(n*n)
*/
vector<vector<int>> brute_rotate_matrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    if (n == 0)
        return {};

    vector<vector<int>> rotated_mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated_mat[j][n - 1 - i] = mat[i][j];
        }
    }
    return rotated_mat;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Given matrix: " << endl;
    print_matrix(mat);
    cout << endl
         << "Rotated matrix: " << endl;
    print_matrix(brute_rotate_matrix(mat));
}
