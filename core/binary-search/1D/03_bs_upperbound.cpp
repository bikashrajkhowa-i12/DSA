/*
Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
The upper bound is the smallest index, ind, where arr[ind] > x.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 5
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logn) SC: O(1)
int upperbound(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int idx = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
        {
            high = mid - 1;
            idx = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

int main()
{
    int target;
    vector<int> arr = {1, 2, 2, 3, 8, 15, 19, 19};

    cout << "Enter a target: ";
    cin >> target;

    cout << "The upperbound of " << target << " is in index " << upperbound(arr, arr.size(), target);
}