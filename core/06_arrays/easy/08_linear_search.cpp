/*
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples
Example 1:
Input:
arr[] = 1 2 3 4 5, num = 3
Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 6, 4, 9, 7, 3, 1, 5, 8};
    int num;

    cout << "Enter the number to be searched: ";
    cin >> num;

    cout << linear_search(arr, arr.size(), num);
}