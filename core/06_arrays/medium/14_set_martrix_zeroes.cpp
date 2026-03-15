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

/* brute-force
    TC: O(n * n)
    SC: O(n) + O(m) => O(m+n)
*/
void set_matrix_zero(vector<vector<int>> &arr)
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

int main()
{
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

    set_matrix_zero(arr);
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