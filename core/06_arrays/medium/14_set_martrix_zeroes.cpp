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

/*
Brute Force ********************************************
    - When you see 0 -> mark its row & column (use -1 to avoid chain effect)
    - Continue scanning without converting to 0 immediately
    - After full traversal -> convert all -1 to 0

    - Complexity:
        - TC: O(n*m*(n+m))
        - SC: O(1)
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

/*
Better ********************************************
    - Scan matrix -> store which rows & cols need to be zero (row[], col[])
    - Traverse again -> if row[i] or col[j] is marked -> set arr[i][j] = 0
    - Complexity:
        - TC: O(n*m)
        - SC: O(n+m)
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

/*
Optimal ********************************************
    - Store instructions in first row/column
    - Apply instructions to inner matrix
    - Finally apply instructions to first row/column

    - Complexity:
        - TC: O(n*m)
        - SC: O(1)
*/

void optimized_set_matrix_zero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1;

    // Step 1: mark rows and columns
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    // Step 2: apply markers to the inner matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[0][j] == 0 || arr[i][0] == 0)
                arr[i][j] = 0;
        }
    }

    // Step 3: handle first row
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
            arr[0][j] = 0;
    }

    // Step 4: handle first column
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            arr[i][0] = 0;
    }
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
    // better_set_matrix_zero(arr);
    optimized_set_matrix_zero(arr);

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