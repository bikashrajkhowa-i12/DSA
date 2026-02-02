/*
 Given an integer array nums, sorted in ascending order (with distinct values) and a target value k.
 The array is rotated at some pivot point that is unknown. Find the index at which k is present and
 if k is not present return -1.

Examples
Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums.
Thus, we get output as 4, which is the index at which 0 is present in the array.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force: linearly search the entire array and return the arr[i] == target return i;
// TC: O(n), SC:(1)

// optimal; TC: O(logN); SC: O(1)
int search_element(vector<int> &arr, int N, int target)
{
    int low = 0;
    int high = N - 1;

    //{4, 5, 6, 7, 0, 1, 2}, target=0
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // left is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target < arr[mid])
            {
                high = mid - 1; // shift to left
            }
            else
            {
                low = mid + 1; // shift to right part
            }
        }
        // right is sorted
        else
        {
            if (arr[mid] < target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int target;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Enter a target to be searched: ";
    cin >> target;

    cout << "The element " << target << " is at index: " << search_element(arr, arr.size(), target);
}