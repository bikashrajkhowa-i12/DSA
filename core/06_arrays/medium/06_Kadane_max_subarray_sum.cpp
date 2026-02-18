/*
Given an integer array nums, find the subarray with the largest sum and return the
sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Example 1:
Input:
 nums = [2, 3, 5, -2, 7, -4]
Output:
 15
Explanation:
 The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.
*/

#include <bits/stdc++.h>
using namespace std;

// brute-force; TC: O(n*n); SC: O(1)
int max_subarray_sum(vector<int> &arr)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum > 0 ? maxSum : 0;
}

// Kadane's algorithm(optimized)
// TC: O(n); SC: O(1)
long long Kadane_max_sum(vector<int> &arr)
{
    long long sum = 0, maxSum = LONG_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum > 0 ? maxSum : 0;
}

int main()
{
    // vector<int> arr = {-1, -3, -1, -2, -3};
    vector<int> arr = {2, 3, 5, -2, 7, -4};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl
         << "Result(brute): " << max_subarray_sum(arr);
    cout << endl
         << "Result(optimized): " << Kadane_max_sum(arr);
}