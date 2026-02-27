/*
Given an integer array arr of size N, sorted in ascending order (with distinct values),
the array is rotated at any index which is unknown. Find the minimum element in the array.

Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Input: arr = [4,5,6,7,0,1,2,3]
Output: 0
Explanation: The minimum element in the array is 0.
Input : arr = [3,4,5,1,2]
Output: 1
Explanation : The minimum element in the array is 1.
*/

#include <iostream>
#include <vector>

using namespace std;

// TC: O(n); SC: O(1)
int brute_min(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;

    int mini = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

// TC: O(logn); SC: O(1)
int optimized_min(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return arr[low];
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    cout << "Given rotated sorted-array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl
         << "Minimum(brute): " << brute_min(arr);
    cout << endl
         << "Minimum(optimal): " << optimized_min(arr);
}