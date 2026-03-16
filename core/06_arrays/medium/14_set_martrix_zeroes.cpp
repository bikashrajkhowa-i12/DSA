/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [
[1,1,1],
[1,0,1],
[1,1,1]]

Output: [
[1,0,1],
[0,0,0],
[1,0,1]]

Example 2:
Input: matrix = [
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]]

Output: [
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]]
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void markRow(vector<vector<int>> &arr, int i, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void markCol(vector<vector<int>> &arr, int j, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

/* brute-force
    TC: O(nm(n+m))
    SC: O(1)
*/

void brute_set_matrix_zero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    // convert -1 → 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
}

/* better
    TC: O(n * m)
    SC: O(n) + O(m) => O(m+n)
*/
void better_set_matrix_zero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
                arr[i][j] = 0;
        }
    }
}

void optimized_set_matrix_zero(vector<vector<int>> &arr)
{
}

int main()
{
    // vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j];
            if (j != arr[i].size() - 1)
                cout << ", ";
        }
        cout << "]";

        if (i != arr.size() - 1)
            cout << ", \n";
    }

    cout << "]";

    // brute_set_matrix_zero(arr);
    better_set_matrix_zero(arr);

    cout << endl
         << "Set martix to zero: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
            if (j != arr[i].size() - 1)
                cout << ", ";
        }
        cout << "]";

        if (i != arr.size() - 1)
            cout << ", \n";
    }

    cout << "]";
}