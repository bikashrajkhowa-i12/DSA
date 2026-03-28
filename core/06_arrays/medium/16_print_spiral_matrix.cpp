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

void print_2d_matrix(const vector<vector<int>> &mat)
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

/*
    TC: O(n * m) // touching each and every element
    SC: O(n * m) // required space for all the element in matrix
*/
vector<int> spiral_matrix(vector<vector<int>> &mat)
{
    int n = mat.size();    // cols length
    int m = mat[0].size(); // rows length

    vector<int> spiralMat;

    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            spiralMat.push_back(mat[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            spiralMat.push_back(mat[i][right]);
        right--;

        for (int i = right; i >= left; i--)
            spiralMat.push_back(mat[bottom][i]);
        bottom--;

        for (int i = bottom; i >= top; i--)
            spiralMat.push_back(mat[i][left]);
        left++;
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