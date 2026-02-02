/*
You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the
smallest element in the array greater than or equal to x.

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> floor_and_ceil(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int floor;
    int ceil;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            low = mid + 1;
            floor = arr[mid];
        }

        if (arr[mid] >= target)
        {
            high = mid - 1;
            ceil = arr[mid];
        }
    }

    return {floor, ceil};
}

int main()
{
    int target;
    vector<int> arr = {1, 2, 2, 3, 8, 15, 19, 19};
    vector<int> result;

    cout << "Enter your target: ";
    cin >> target;

    result = floor_and_ceil(arr, arr.size(), target);
    cout << "Floor and ceil of " << target << " is: [ ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << "]";
}
